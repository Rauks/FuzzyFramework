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
    class AndMult : public And<T>{
    public:
        AndMult();
        AndMult(const AndMult<T>& o);
        virtual ~AndMult();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    AndMult<T>::AndMult(){
    }
    
    template<class T>
    AndMult<T>::AndMult(const AndMult<T>& o){
    }
    
    template<class T>
    AndMult<T>::~AndMult(){
    }
    
    template<class T>
    T AndMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        return lt * rt;
    }
}

#endif	/* ANDMULT_H */

