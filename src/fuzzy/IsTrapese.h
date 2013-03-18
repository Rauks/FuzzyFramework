/* 
 * File:   IsTrapese.h
 * Author: Karl
 *
 * Created on 18 mars 2013, 09:08
 */

#ifndef ISTRAPESE_H
#define	ISTRAPESE_H

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTrapese : public Is<T>{
    private:
        T _min;
        T _midMin;
        T _midMax;
        T _max;
    public:
        IsTrapese(const T& min, const T& midMin, const T& midMax, const T& max);
        IsTrapese(const IsTrapese<T>& o);
        virtual ~IsTrapese();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsTrapese<T>::IsTrapese(const T& min, const T& midMin, const T& midMax, const T& max)
    :_min(min), _midMin(midMin), _midMax(midMax), _max(max){
    }
    
    template<class T>
    IsTrapese<T>::IsTrapese(const IsTrapese<T>& o)
    :_min(o._min), _midMin(o._midMin), _midMax(o._midMax), _max(o._max){
    }
    
    template<class T>
    IsTrapese<T>::~IsTrapese(){
    }
    
    template<class T>
    T IsTrapese<T>::evaluate(core::Expression<T>* operand) const{
        T val = operand->evaluate();
        if(val > _min && val < _midMin){
             return (val - _min) / (_midMin - _min);
        }
        if(val >= _midMin && val <= _midMax){
             return 1;
        }
        if(val > _midMax && val < _max){
            return (val - _max) / (_midMax - _max);
        }
        return 0;
    }
}

#endif	/* ISTRAPESE_H */

