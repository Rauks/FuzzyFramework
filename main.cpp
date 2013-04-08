/* 
 * File:   main.cpp
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:30
 */

#include <cstdlib>

#include "src/fuzzy/NotMinus1.h"
#include "src/fuzzy/AndMin.h"
#include "src/fuzzy/OrMax.h"
#include "src/fuzzy/ThenMin.h"
#include "src/fuzzy/AggMax.h"
#include "src/fuzzy/CogDefuzz.h"

#include "src/fuzzy/FuzzyFactory.h"

#include "src/fuzzy/IsTriangle.h"

#include "src/core/Expression.h"
#include "src/core/ValueModel.h"

using namespace std;
using namespace core;
using namespace fuzzy;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    IsTriangle<float> triangle(5, 10, 15);
    
    ExpressionFactory<float> f;
    ValueModel<float>* val = f.newValue(5);
    Expression<float>* exp = f.newUnary(&triangle, val);
    
    Evaluator<float>::Shape s = Evaluator<float>::buildShape(0, 30, 1, val, exp);
    std::cout << s;
    */
    
    //operators
    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::ThenMin<float> opThen;
    fuzzy::AggMax<float> opAgg;
    fuzzy::CogDefuzz<float> opDefuzz(0, 25, 1);
    
    //fuzzy expession factory 
    fuzzy::FuzzyFactory<float> f(&opAnd, &opOr, &opNot, &opThen, &opAgg, &opDefuzz);
    
    //membership function 
    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);
    fuzzy::IsTriangle<float> cheap(0,5,10);
    fuzzy::IsTriangle<float> average(10,15,20);
    fuzzy::IsTriangle<float> generous(20,25,30);
    
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
    core::Expression<float> *system = f.newDefuzz(&tips, r);
    
    //apply input 
    float s;
    while(true){
        cout << "service : ";cin >> s;
        service.setValue(s);
        cout << "tips -> " << system->evaluate() << endl;
    }
    
    
    return 0;
}

