/* 
 * File:   OrMax.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:02
 */

#ifndef ORMAX_H
#define	ORMAX_H

#include "Or.h"

namespace fuzzy{
    template<class T>
    class OrMax : public Or{
    public:
        OrMax();
        OrMax(const OrMax<T>& o);
        virtual ~OrMax();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    OrMax<T>::OrMax(){
    }
    
    template<class T>
    OrMax<T>::OrMax(const OrMax<T>& o){
    }
    
    template<class T>
    OrMax<T>::~OrMax(){
    }
    
    template<class T>
    T OrMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        return (lt < rt)?rt:lt;
    }
}

#endif	/* ORMAX_H */

