/* 
 * File:   AndMult.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:00
 */

#ifndef ANDMULT_H
#define	ANDMULT_H

#include "And.h"

namespace fuzzy{
    template<class T>
    class AndMult : public And{
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

#endif	/* ANDMULT_H */

