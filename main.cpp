/* 
 * File:   main.cpp
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:30
 */

#include <cstdlib>
#include <stdexcept>
#include <vector>

#include "src/fuzzy/NotMinus1.h"
#include "src/fuzzy/AndMin.h"
#include "src/fuzzy/OrMax.h"
#include "src/fuzzy/ThenMin.h"
#include "src/fuzzy/AggMax.h"
#include "src/fuzzy/CogDefuzz.h"
#include "src/fuzzy/ThenSugeno.h"

#include "src/fuzzy/FuzzyFactory.h"

#include "src/fuzzy/IsTriangle.h"
#include "src/fuzzy/IsTrapese.h"
#include "src/fuzzy/IsTrapeseLeft.h"
#include "src/fuzzy/IsTrapeseRight.h"
#include "src/fuzzy/IsGaussian.h"

#include "src/core/Expression.h"
#include "src/core/ValueModel.h"

using namespace std;

void sugenoTest(){
    try{
        //operators
        fuzzy::NotMinus1<float> opNot;
        fuzzy::AndMin<float> opAnd;
        fuzzy::OrMax<float> opOr;
        fuzzy::ThenSugeno<float> opThen;
        fuzzy::AggMax<float> opAgg;
        fuzzy::CogDefuzz<float> opMamdani = fuzzy::CogDefuzz<float>(0, 25, 1);
        fuzzy::SugenoDefuzz<float> opSugeno = fuzzy::SugenoDefuzz<float>();

        vector<float> coefs;
        coefs.push_back(1);
        coefs.push_back(1);
        coefs.push_back(1);
        fuzzy::SugenoDefuzzConclusion<float> opConclusion = fuzzy::SugenoDefuzzConclusion<float>(&coefs);

        //fuzzy expession factory
        fuzzy::FuzzyFactory<float> f(&opAnd, &opOr, &opNot, &opThen, &opAgg, &opMamdani, &opSugeno, &opConclusion);

        //membership function
        fuzzy::IsTriangle<float> poor(-5, 0, 5);
        fuzzy::IsTriangle<float> good(0, 5, 10);
        fuzzy::IsTriangle<float> excellent(5, 10, 15);
        fuzzy::IsTriangle<float> rancid(-5, 0, 5);
        fuzzy::IsTriangle<float> delicious(5, 10, 15);

        //values
        core::ValueModel<float> service(0);
        core::ValueModel<float> food(0);
        core::ValueModel<float> tips(0);

        //sugeno conclusion
        vector<core::Expression<float>*> sugenoConcServiceFood;
        sugenoConcServiceFood.push_back(&service);
        sugenoConcServiceFood.push_back(&food);

        vector<core::Expression<float>*> sugenoConcService;
        sugenoConcService.push_back(&service);

        vector<core::Expression<float>*> r;
        r.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&service,&poor),
                    f.newIs(&food,&rancid)
                ),
                f.newConclusion(&sugenoConcServiceFood)
            )
        );
        r.push_back(
            f.newThen(
                f.newIs(&service,&good),
                f.newConclusion(&sugenoConcService)
            )
        );
        r.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&service,&excellent),
                    f.newIs(&food,&delicious)
                ),
                f.newConclusion(&sugenoConcServiceFood)
            )
        );

        //defuzzification
        core::Expression<float> *system = f.newSugeno(&r);

        //apply input
        float s;
        while(true)
        {
                cout << "service : ";
                cin >> s;
                service.setValue(s);
                cout << "food : ";
                cin >> s;
                food.setValue(s);
                cout << "tips -> " << system->evaluate() << endl;
        }
    } catch(const std::exception& ex){
        cout << ex.what();
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    //mamdaniTest();
    //sugenoTest();
    
    
    try{
        //operators
        fuzzy::OrMax<float> opOr;
        fuzzy::ThenMin<float> opThen;
        fuzzy::AggMax<float> opAgg;
            //mamdani
            fuzzy::CogDefuzz<float> opDefuzz(0, 25, 0.1);
            //sugeno
            fuzzy::SugenoDefuzz<float> opSugeno;
            vector<float> coefs;
            coefs.push_back(1);
            coefs.push_back(1);
            coefs.push_back(1);
            fuzzy::SugenoDefuzzConclusion<float> opConclusion = fuzzy::SugenoDefuzzConclusion<float>(&coefs);
        //unused operators (for factory init only)
        fuzzy::NotMinus1<float> opNot;
        fuzzy::AndMin<float> opAnd;
        
        //fuzzy expession factory 
        fuzzy::FuzzyFactory<float> f(&opAnd, &opOr, &opNot, &opThen, &opAgg, &opDefuzz, &opSugeno, &opConclusion);
        
        //membership function
        fuzzy::IsGaussian<float> poor(0, 6);
        fuzzy::IsGaussian<float> good(5, 6);
        fuzzy::IsGaussian<float> excellent(10, 6);
        
        fuzzy::IsTrapeseLeft<float> rancid(1, 4);
        fuzzy::IsTrapeseRight<float> delicious(6, 9);
        
        fuzzy::IsTriangle<float> cheap(0, 6, 12);
        fuzzy::IsTriangle<float> average(7, 13, 19);
        fuzzy::IsTriangle<float> generous(14, 20, 26);

        //values
        core::ValueModel<float> service(0); //0-10
        core::ValueModel<float> food(0);  // 0-10
        core::ValueModel<float> tips(0);  // 0-26
        
        //Mamdani system
        core::Expression<float> *r = 
            f.newAgg(
                f.newAgg(
                    f.newThen(
                        f.newOr(
                            f.newIs(&service, &poor), 
                            f.newIs(&food, &rancid)
                        ),
                        f.newIs(&tips,&cheap)
                    ),
                    f.newThen(
                        f.newIs(&service,&good),
                        f.newIs(&tips,&average)
                    )
                ),
                f.newThen(
                    f.newOr(
                        f.newIs(&service, &excellent), 
                        f.newIs(&food, &delicious)
                    ),
                    f.newIs(&tips,&generous)
                )
        );
        
        //Mamdani system defuzzification
        core::Expression<float> *system = f.newMamdaniDefuzz(&tips, r);
        
        //Apply values
        service.setValue(3);
        food.setValue(8);
        
        //Print result
        cout << "Mamdani tip result : " << endl << system->evaluate();
        
    } catch(const std::exception& ex){
        cout << ex.what();
    }
    
    return 0;
}


