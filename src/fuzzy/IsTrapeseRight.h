/* 
 * File:   IsTrapeseRight.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 22:01
 */

#ifndef ISTRAPESERIGHT_H
#define	ISTRAPESERIGHT_H

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTrapeseRight : public Is<T>{
    private:
        T _min;
        T _midMin;
    public:
        IsTrapeseRight(const T& min, const T& midMin);
        IsTrapeseRight(const IsTrapeseRight<T>& o);
        virtual ~IsTrapeseRight();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsTrapeseRight<T>::IsTrapeseRight(const T& min, const T& midMin)
    :_min(min), _midMin(midMin){
    }
    
    template<class T>
    IsTrapeseRight<T>::IsTrapeseRight(const IsTrapeseRight<T>& o)
    :_min(o._min), _midMin(o._midMin){
    }
    
    template<class T>
    IsTrapeseRight<T>::~IsTrapeseRight(){
    }
    
    template<class T>
    T IsTrapeseRight<T>::evaluate(core::Expression<T>* operand) const{
        T val = operand->evaluate();
        if(val > _min && val < _midMin){
             return (val - _min) / (_midMin - _min);
        }
        if(val >= _midMin){
             return 1;
        }
        return 0;
    }
}

#endif	/* ISTRAPESERIGHT_H */

