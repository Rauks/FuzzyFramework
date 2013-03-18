/* 
 * File:   AggPlus.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:00
 */

#ifndef AGGPLUS_H
#define	AGGPLUS_H

#include "../core/Expression.h"
#include "Agg.h"

namespace fuzzy{
    template<class T>
    class AggPlus : public Agg<T>{
    public:
        AggPlus();
        AggPlus(const AggPlus<T>& o);
        virtual ~AggPlus();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    AggPlus<T>::AggPlus(){
    }
    
    template<class T>
    AggPlus<T>::AggPlus(const AggPlus<T>& o){
    }
    
    template<class T>
    AggPlus<T>::~AggPlus(){
    }
    
    template<class T>
    T AggPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        T sum = lt + rt;
        return (sum > 1)?1:sum;
    }
}

#endif	/* AGGPLUS_H */

