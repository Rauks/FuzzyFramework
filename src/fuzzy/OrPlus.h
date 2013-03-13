/* 
 * File:   OrPlus.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:02
 */

#ifndef ORPLUS_H
#define	ORPLUS_H

#include "Or.h"

namespace fuzzy{
    template<class T>
    class OrPlus : public Or{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right);
    };
    
    template<class T>
    T evaluate(core::Expression<T>* left, core::Expression<T>* right){
        T lt = left->evaluate();
        T rt = right->evaluate();
        T sum = lt + rt;
        return (sum > 1)?1:sum;
    }
}

#endif	/* ORPLUS_H */

