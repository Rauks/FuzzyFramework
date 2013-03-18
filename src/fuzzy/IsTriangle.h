/* 
 * File:   isTriangle.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:01
 */

#ifndef ISTRIANGLE_H
#define	ISTRIANGLE_H

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTriangle : public Is<T>{
    private:
        T _min;
        T _mid;
        T _max;
    public:
        IsTriangle(const T& min, const T& mid, const T& max);
        IsTriangle(const IsTriangle<T>& o);
        virtual ~IsTriangle();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsTriangle<T>::IsTriangle(const T& min, const T& mid, const T& max)
    :_min(min), _mid(mid), _max(max){
    }
    
    template<class T>
    IsTriangle<T>::IsTriangle(const IsTriangle<T>& o)
    :_min(o._min), _mid(o._mid), _max(o._max){
    }
    
    template<class T>
    IsTriangle<T>::~IsTriangle(){
    }
    
    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* operand) const{
        T val = operand->evaluate();
        if(val > _min && val < _mid){
             return (val - _min) / (_mid - _min);
        }
        if(val >= _mid && val < _max){
            return (val - _max) / (_mid - _max);
        }
        return 0;
    }
}

#endif	/* ISTRIANGLE_H */

