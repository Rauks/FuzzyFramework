/* 
 * File:   UnaryExpressionModel.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:54
 */

#ifndef UNARYEXPRESSIONMODEL_H
#define	UNARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "NullArgumentException.h"

#include <iostream>

namespace core{
    template<class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T>{
    private:
        Expression<T>* _operand;
        UnaryExpression<T>* _op;
    public:
        UnaryExpressionModel(Expression<T>* operand = NULL, UnaryExpression<T>* op = NULL);
        UnaryExpressionModel(const UnaryExpressionModel<T>& o);
        virtual ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* operand) const;
        virtual UnaryExpression<T>* getOperator() const;
    };
    
    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* op)
    :_operand(operand), _op(op){
    }
    
    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(const UnaryExpressionModel<T>& o)
    :_operand(o._operand), _op(o._op){
    }
    
    template<class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel(){
    }
    
    template<class T>
    T UnaryExpressionModel<T>::evaluate() const{
        if(_operand != NULL)
            return evaluate(_operand);
        throw NullArgumentException("Expression : Operand");
    }
    
    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* operand) const{
        if(_op != NULL)
            return _op->evaluate(operand);
        throw NullArgumentException("UnaryExpression : Operator");
    }
    
    template<class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() const{
        return _op;
    }
}

#endif	/* UNARYEXPRESSIONMODEL_H */

