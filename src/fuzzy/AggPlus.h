/* 
 * File:   AggPlus.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:00
 */

#ifndef AGGPLUS_H
#define	AGGPLUS_H

#include "Agg.h"

namespace fuzzy{
    template<class T>
    class AggPlus : public Agg{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    T evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        T sum = lt + rt;
        return (sum > 1)?1:sum;
    }
}

#endif	/* AGGPLUS_H */

