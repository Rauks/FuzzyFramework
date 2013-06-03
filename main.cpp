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
            fuzzy::CogDefuzz<float> opDefuzz(0, 26, 0.1);
            //sugeno
            fuzzy::SugenoDefuzz<float> opSugeno;
            fuzzy::ThenSugeno<float> opThenSugeno;
            vector<float> coefs;
            coefs.push_back(1.6);
            coefs.push_back(2.1);
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
        
        //Print mamdani result
        cout << "Mamdani tip result : " << endl << system->evaluate() << endl;
        
        //Change then for sugeno
        f.changeThen(&opThenSugeno);
        
        //Sugeno conclusions
        vector<core::Expression<float>*> sugenoConcServiceFood;
        sugenoConcServiceFood.push_back(&service);
        sugenoConcServiceFood.push_back(&food);

        vector<core::Expression<float>*> sugenoConcService;
        sugenoConcService.push_back(&service);
        
        //Sugeno system (use nary)
        vector<core::Expression<float>*> sRules;
        sRules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&service,&poor),
                    f.newIs(&food,&rancid)
                ),
                f.newConclusion(&sugenoConcServiceFood)
            )
        );
        sRules.push_back(
            f.newThen(
                f.newIs(&service,&good),
                f.newConclusion(&sugenoConcService)
            )
        );
        sRules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&service,&excellent),
                    f.newIs(&food,&delicious)
                ),
                f.newConclusion(&sugenoConcServiceFood)
            )
        );
        
        //Sugeno system defuzzification
        core::Expression<float> *systemSugeno = f.newSugeno(&sRules);
        
        //Print sugeno result
        cout << "Sugeno tip result : " << endl << systemSugeno->evaluate();
        
    } catch(const std::exception& ex){
        cout << ex.what();
    }
    
    return 0;
}


