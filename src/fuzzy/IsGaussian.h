/* 
 * File:   IsGaussian.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 14:33
 */

#ifndef ISGAUSSIAN_H
#define	ISGAUSSIAN_H

#include <math.h>

#include "../core/Expression.h"
#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsGaussian : public Is<T>{
    private:
        T _center;
        T _sigma;
    public:
        IsGaussian(const T& center, const T& sigma);
        IsGaussian(const IsGaussian<T>& o);
        virtual ~IsGaussian();
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
    IsGaussian<T>::IsGaussian(const T& center, const T& sigma)
    :_center(center), _sigma(sigma){
    }
    
    template<class T>
    IsGaussian<T>::IsGaussian(const IsGaussian<T>& o)
    :_center(o._center), _sigma(o._sigma){
    }
    
    template<class T>
    IsGaussian<T>::~IsGaussian(){
    }
    
    template<class T>
    T IsGaussian<T>::evaluate(core::Expression<T>* operand) const{
        T value = operand->evaluate();
        return exp(-((value - _center) * (value - _center)) / (2 * _sigma * _sigma));
    }
}

#endif	/* ISGAUSSIAN_H */

