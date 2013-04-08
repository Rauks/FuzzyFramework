/* 
 * File:   UnaryShadowExpression.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 16:11
 */

#ifndef UNARYSHADOWEXPRESSION_H
#define	UNARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "NullArgumentException.h"

#include <iostream>

namespace core{
    template<class T>
    class UnaryShadowExpression : public UnaryExpression<T>{
    private:
        UnaryExpression<T>* _exp;
    public:
        UnaryShadowExpression(UnaryExpression<T>* exp = NULL);
        UnaryShadowExpression(const UnaryShadowExpression<T>& o);
        virtual ~UnaryShadowExpression();
        virtual T evaluate(Expression<T>* operand) const;
        void setExpression(UnaryExpression<T>* exp);
    };
    
    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* exp)
    :_exp(exp){
    }
    
    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(const UnaryShadowExpression<T>& o)
    :_exp(o._exp){
    }
    
    template<class T>
    UnaryShadowExpression<T>::~UnaryShadowExpression(){
    }
    
    template<class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T>* operand) const{
        if(_exp != NULL)
            return _exp->evaluate(operand);
        throw NullArgumentException("UnaryShadowExpression : Expression");
    }
    
    template<class T>
    void UnaryShadowExpression<T>::setExpression(UnaryExpression<T>* exp){
        _exp = exp;
    }
}

#endif	/* UNARYSHADOWEXPRESSION_H */

