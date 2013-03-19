/* 
 * File:   main.cpp
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:30
 */

#include <cstdlib>

#include "src/core/ValueModel.h"
#include "src/core/BinaryExpressionModel.h"
#include "src/core/UnaryExpressionModel.h"
#include "src/fuzzy/AndMin.h"
#include "src/fuzzy/IsTriangle.h"

#include "src/core/Evaluator.h"

using namespace std;
using namespace core;
using namespace fuzzy;

/*
 * 
 */
int main(int argc, char** argv) {
    ValueModel<float> vm1(1);
    IsTriangle<float> op2(5, 10, 15);
    UnaryExpressionModel<float> uem(&vm1, &op2);
    
    Evaluator<float>::Shape s = Evaluator<float>::evaluate(0, 30, 1, vm1, uem);
    std::cout << s;
    
    /*
    //operators
    NotMinus1 opNot;
    AndMin opAnd;
    OrMax opOr;
    ThenMin opThen;
    CogDefuzz opDefuzz;
    
    //fuzzy expession factory 
    FuzzyExpressionFactory f(&opNot,&opAnd,&opOr,&opThen,&opOr,&opDefuzz);
    
    //membership function 
    IsTriangle poor(-5,0,5);
    IsTriangle good(0,5,10);
    IsTriangle excellent(5,10,15);
    IsTriangle cheap(0,5,10);
    IsTriangle average(10,15,20);
    IsTriangle generous(20,25,30);
    
    //values
    Value service(,0);
    Value food(0);
    Value tips(0);
    Expression *r = 
        f.NewAgg(
            f.NewAgg(
                f.NewThen(
                    f.NewIs(&service,&poor),
                    f.NewIs(&tips,&cheap)
                ),
                f.NewThen(
                    f.NewIs(&service,&good),
                    f.NewIs(&tips,&average)
                )
            ),
            f.NewThen(
                f.NewIs(&service,&excellent),
                f.NewIs(&tips,&generous)
            )
    );
    
    //defuzzification
    core::Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);
    
    //apply input 
    float s;
    while(true){
        cout << "service : ";cin >> s;
        service.SetValue(s);
        cout << "tips -> " << system->evaluate() << endl;
    }
    */
    
    return 0;
}

