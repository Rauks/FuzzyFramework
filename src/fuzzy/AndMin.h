/* 
 * File:   AndMin.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:00
 */

#ifndef ANDMIN_H
#define	ANDMIN_H

#include "And.h"

namespace fuzzy{
    template<class T>
    class AndMin : public And<T>{
    public:
        AndMin();
        AndMin(const AndMin<T>& o);
        virtual ~AndMin();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    AndMin<T>::AndMin(){
    }
    
    template<class T>
    AndMin<T>::AndMin(const AndMin<T>& o){
    }
    
    template<class T>
    AndMin<T>::~AndMin(){
    }
    
    template<class T>
    T AndMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        return (lt < rt)?lt:rt;
    }
}

#endif	/* ANDMIN_H */

