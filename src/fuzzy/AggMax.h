/* 
 * File:   AggMax.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:00
 */

#ifndef AGGMAX_H
#define	AGGMAX_H

#include "Agg.h"

namespace fuzzy{
    template<class T>
    class AggMax : public Agg{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right);
    };
    
    template<class T>
    T evaluate(core::Expression<T>* left, core::Expression<T>* right){
        T lt = left->evaluate();
        T rt = right->evaluate();
        return (lt < rt)?rt:lt;
    }
}

#endif	/* AGGMAX_H */

