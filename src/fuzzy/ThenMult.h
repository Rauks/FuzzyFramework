/* 
 * File:   ThenMult.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:03
 */

#ifndef THENMULT_H
#define	THENMULT_H

#include "Then.h"

namespace fuzzy{
    template<class T>
    class ThenMult : public Then<T>{
    public:
        ThenMult();
        ThenMult(const ThenMult<T>& o);
        virtual ~ThenMult();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
    };
    
    template<class T>
    ThenMult<T>::ThenMult(){
    }
    
    template<class T>
    ThenMult<T>::ThenMult(const ThenMult<T>& o){
    }
    
    template<class T>
    ThenMult<T>::~ThenMult(){
    }
    
    template<class T>
    T ThenMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const{
        T lt = left->evaluate();
        T rt = right->evaluate();
        return lt * rt;
    }
}

#endif	/* THENMULT_H */

