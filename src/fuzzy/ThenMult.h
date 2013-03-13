/* 
 * File:   ThenMult.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:03
 */

#ifndef THENMULT_H
#define	THENMULT_H

#include "Then.h"

namespace fuzzy{
    template<class T>
    class ThenMult : public Then{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right);
    };
    
    template<class T>
    T evaluate(core::Expression<T>* left, core::Expression<T>* right){
        T lt = left->evaluate();
        T rt = right->evaluate();
        return lt * rt;
    }
}

#endif	/* THENMULT_H */

