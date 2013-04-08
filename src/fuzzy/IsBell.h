/* 
 * File:   IsBell.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 14:19
 */

#ifndef ISBELL_H
#define	ISBELL_H

#include <math.h>

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsBell : public Is<T>{
    private:
        T _min;
        T _center;
        T _max;
    public:
        IsBell(const T& min, const T& center, const T& max);
        IsBell(const IsBell<T>& o);
        virtual ~IsBell();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsBell<T>::IsBell(const T& min, const T& center, const T& max)
    :_min(min), _center(center), _max(max){
    }
    
    template<class T>
    IsBell<T>::IsBell(const IsBell<T>& o)
    :_min(o._min), _center(o._center), _max(o._max){
    }
    
    template<class T>
    IsBell<T>::~IsBell(){
    }
    
    template<class T>
    T IsBell<T>::evaluate(core::Expression<T>* operand) const{
        return (1 / (1 + pow(abs((operand->evaluate() - _center) / _min)), 2 * _max));
    }
}

#endif	/* ISBELL_H */

