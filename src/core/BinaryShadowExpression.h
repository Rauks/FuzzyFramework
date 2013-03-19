/* 
 * File:   BinaryShadowExpression.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 16:12
 */

#ifndef BINARYSHADOWEXPRESSION_H
#define	BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"

#include <iostream>

namespace core{
    template<class T>
    class BinaryExpressionExpression : BinaryExpression<T>{
    private:
        BinaryExpression<T>* _exp;
    public:
        BinaryExpressionExpression(BinaryExpression<T>* exp = NULL);
        BinaryExpressionExpression(const BinaryExpressionExpression<T>& o);
        virtual ~BinaryExpressionExpression();
        virtual T evaluate(Expression<T>* left, Expression<T>* right) const;
        void setExpression(BinaryExpression<T>* exp);
    };
    
    template<class T>
    BinaryExpressionExpression<T>::BinaryExpressionExpression(BinaryExpression<T>* exp)
    :_exp(exp){
    }
    
    template<class T>
    BinaryExpressionExpression<T>::BinaryExpressionExpression(const BinaryExpressionExpression<T>& o)
    :_exp(o._exp){
    }
    
    template<class T>
    BinaryExpressionExpression<T>::~BinaryExpressionExpression(){
    }
    
    template<class T>
    T BinaryExpressionExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const{
        if(_exp != NULL)
            return _exp->evaluate(left, right);
        throw NullArgumentException("Shadow expression : Operand");
    }
    
    template<class T>
    void BinaryExpressionExpression<T>::setExpression(BinaryExpression<T>* exp){
        _exp = exp;
    }
}

#endif	/* BINARYSHADOWEXPRESSION_H */

