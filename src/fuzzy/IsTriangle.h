/* 
 * File:   isTriangle.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:01
 */

#ifndef ISTRIANGLE_H
#define	ISTRIANGLE_H

#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTriangle : public Is{
    private:
        T* _min;
        T* _mid;
        T* _max;
    public:
        IsTriangle();
        IsTriangle(const IsTriangle<T>& o);
        virtual ~IsTriangle();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsTriangle<T>::IsTriangle(T* min, T* mid, T* max)
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
            //TODO
        }
        if(val > _mid && val < _max){
            //TODO
        }
        return 0;
    }
}

#endif	/* ISTRIANGLE_H */

