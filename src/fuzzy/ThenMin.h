/* 
 * File:   ThenMin.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:02
 */

#ifndef THENMIN_H
#define	THENMIN_H

#include "../core/Expression.h"
#include "Then.h"

namespace fuzzy{
    template<class T>
    class ThenMin : public Then<T>{
    public:
        ThenMin();
        ThenMin(const ThenMin<T>& o);
        virtual ~ThenMin();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    ThenMin<T>::ThenMin(){
    }
    
    template<class T>
    ThenMin<T>::ThenMin(const ThenMin<T>& o){
    }
    
    template<class T>
    ThenMin<T>::~ThenMin(){
    }
    
    template<class T>
    T ThenMin<T>::evaluate(core::Expression<T>* cond, core::Expression<T>* result) const{
        T lt = cond->evaluate();
        T rt = result->evaluate();
        return (lt < rt)?lt:rt;
    }
}

#endif	/* THENMIN_H */

