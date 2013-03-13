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
        AggMax();
        AggMax(const AggMax<T>& o);
        virtual ~AggMax();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    AggMax<T>::AggMax(){
    }
    
    template<class T>
    AggMax<T>::AggMax(const AggMax<T>& o){
    }
    
    template<class T>
    AggMax<T>::~AggMax(){
    }
    
    template<class T>
    T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        return (lt < rt)?rt:lt;
    }
}

#endif	/* AGGMAX_H */

