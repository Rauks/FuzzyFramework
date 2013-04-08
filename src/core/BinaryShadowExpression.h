/* 
 * File:   BinaryShadowExpression.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 16:12
 */

#ifndef BINARYSHADOWEXPRESSION_H
#define	BINARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"
#include "NullArgumentException.h"

#include <iostream>

namespace core{
    template<class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
    private:
        BinaryExpression<T>* _exp;
    public:
        BinaryShadowExpression(BinaryExpression<T>* exp = NULL);
        BinaryShadowExpression(const BinaryShadowExpression<T>& o);
        virtual ~BinaryShadowExpression();
        virtual T evaluate(Expression<T>* left, Expression<T>* right) const;
        void setExpression(BinaryExpression<T>* exp);
    };
    
    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* exp)
    :_exp(exp){
    }
    
    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(const BinaryShadowExpression<T>& o)
    :_exp(o._exp){
    }
    
    template<class T>
    BinaryShadowExpression<T>::~BinaryShadowExpression(){
    }
    
    template<class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const{
        if(_exp != NULL)
            return _exp->evaluate(left, right);
        throw NullArgumentException("Shadow expression : Operand");
    }
    
    template<class T>
    void BinaryShadowExpression<T>::setExpression(BinaryExpression<T>* exp){
        _exp = exp;
    }
}

#endif	/* BINARYSHADOWEXPRESSION_H */

