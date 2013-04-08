/* 
 * File:   IsTrapeseLeft.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 22:02
 */

#ifndef ISTRAPESELEFT_H
#define	ISTRAPESELEFT_H

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTrapeseLeft : public Is<T>{
    private:
        T _midMax;
        T _max;
    public:
        IsTrapeseLeft(const T& midMax, const T& max);
        IsTrapeseLeft(const IsTrapeseLeft<T>& o);
        virtual ~IsTrapeseLeft();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsTrapeseLeft<T>::IsTrapeseLeft(const T& midMax, const T& max)
    :_midMax(midMax), _max(max){
    }
    
    template<class T>
    IsTrapeseLeft<T>::IsTrapeseLeft(const IsTrapeseLeft<T>& o)
    :_midMax(o._midMax), _max(o._max){
    }
    
    template<class T>
    IsTrapeseLeft<T>::~IsTrapeseLeft(){
    }
    
    template<class T>
    T IsTrapeseLeft<T>::evaluate(core::Expression<T>* operand) const{
        T val = operand->evaluate();
        if(val <= _midMax){
             return 1;
        }
        if(val > _midMax && val < _max){
            return (val - _max) / (_midMax - _max);
        }
        return 0;
    }
}

#endif	/* ISTRAPESELEFT_H */

