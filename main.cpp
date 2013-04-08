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

void mamdaniTest(){
    try{
        //operators
        fuzzy::NotMinus1<float> opNot;
        fuzzy::AndMin<float> opAnd;
        fuzzy::OrMax<float> opOr;
        fuzzy::ThenMin<float> opThen;
        fuzzy::AggMax<float> opAgg;
        fuzzy::CogDefuzz<float> opDefuzz(0, 25, 1);

        //fuzzy expession factory 
        fuzzy::FuzzyFactory<float> f(&opAnd, &opOr, &opNot, &opThen, &opAgg, &opDefuzz, NULL, NULL);

        //membership function 
        fuzzy::IsTriangle<float> poor(-5,0,5);
        //fuzzy::IsTriangle<float> good(0,5,10);
        //fuzzy::IsTriangle<float> excellent(5,10,15);
        //fuzzy::IsTriangle<float> cheap(0,5,10);
        fuzzy::IsTriangle<float> average(10,15,20);
        //fuzzy::IsTriangle<float> generous(20,25,30);
        
        fuzzy::IsTrapese<float> good(0,5,6,11);
        fuzzy::IsTrapeseLeft<float> excellent(5,10);
        fuzzy::IsTrapeseRight<float> cheap(5,10);
        fuzzy::IsGaussian<float> generous(20,2);

        //values
        core::ValueModel<float> service(0);
        core::ValueModel<float> food(0);
        core::ValueModel<float> tips(0);
        core::Expression<float> *r = 
            f.newAgg(
                f.newAgg(
                    f.newThen(
                        f.newIs(&service,&poor),
                        f.newIs(&tips,&cheap)
                    ),
                    f.newThen(
                        f.newIs(&service,&good),
                        f.newIs(&tips,&average)
                    )
                ),
                f.newThen(
                    f.newIs(&service,&excellent),
                    f.newIs(&tips,&generous)
                )
        );

        //defuzzification
        core::Expression<float> *system = f.newMamdaniDefuzz(&tips, r);

        //apply input 
        float s;
        while(true){
            cout << "service : ";
            cin >> s;
            service.setValue(s);

            cout << "food : ";
            cin >> s;
            food.setValue(s);

            cout << "tips -> " << system->evaluate() << endl;
        }
    } catch(std::exception ex){
        cout << ex.what();
    }
}

void sugenoTest(){

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
    fuzzy::FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opMamdani, &opSugeno, &opConclusion);
    
    //membership function
    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);
    fuzzy::IsTriangle<float> rancid(-5,0,5);
    fuzzy::IsTriangle<float> delicious(5,10,15);
    
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
    
    vector<core::Expression<float>*>* r;
    r->push_back(
        f.newThen(
            f.newOr(
                f.newIs(&service,&poor),
                f.newIs(&food,&rancid)
            ),
            f.newConclusion(sugenoConcServiceFood)
        )
    );
    r->push_back(
        f.newThen(
            f.newIs(&service,&good),
            f.newConclusion(sugenoConcService)
        )
    );
    r->push_back(
        f.newThen(
            f.newOr(
                f.newIs(&service,&excellent),
                f.newIs(&food,&delicious)
            ),
            f.newConclusion(sugenoConcServiceFood)
        )
    );
    
    //defuzzification
    core::Expression<float> *system = f.newSugeno(&r);
    
    //apply input
    float s;
    while(true)
    {
            cout << "service : ";cin >> s;
            service.setValue(s);
            cout << "food : ";cin >> s;
            food.setValue(s);
            cout << "tips -> " << system->evaluate() << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    //mamdaniTest();
    sugenoTest();
    
    return 0;
}


