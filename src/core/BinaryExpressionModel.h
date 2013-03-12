/* 
 * File:   BinaryExpressionModel.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:55
 */

#ifndef BINARYEXPRESSIONMODEL_H
#define	BINARYEXPRESSIONMODEL_H

#include <iostream>

#include "BinaryExpression.h"

namespace core{
    template<class T>
    class BinaryExpressionModel : public Expression, public BinaryExpression{
    private:
        Expression<T>* _left;
        Expression<T>* _right;
        BinaryExpression<T>* _op;
    public:
        BinaryExpressionModel(Expression<T>* left = NULL, Expression<T>* right = NULL, BinaryExpression<T>* op = NULL);
        BinaryExpressionModel(const BinaryExpressionModel<T>& o);
        virtual ~BinaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* left, Expression<T>* right) const;
    };
    
    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* op)
    :_left(left), _right(right), _op(op){
    }
    
    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(const BinaryExpressionModel<T>& o)
    :_left(o._left), _right(o._right), _op(o._op){      
    }
    
    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel(){
    }
    
    template<class T>
    T BinaryExpressionModel<T>::evaluate() const{
        if(_left != NULL && _right != NULL)
            return evaluate(_left, _right);
    }
    
    template<class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* left, Expression<T>* right) const{
        if(operator != NULL)
            return _op.evaluate(left, right);
    }
}

#endif	/* BINARYEXPRESSIONMODEL_H */

