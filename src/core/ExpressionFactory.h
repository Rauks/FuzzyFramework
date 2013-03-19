/* 
 * File:   ExpressionFactory.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 16:45
 */

#ifndef EXPRESSIONFACTORY_H
#define	EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "ValueModel.h"

#include <vector>

namespace core{
    template<class T>
    class ExpressionFactory{
    private:
        typedef typename std::vector<Expression<T>*>::const_iterator const_iterator;
        typedef typename std::vector<Expression<T>*>::iterator iterator;
        std::vector<Expression<T>*> _memory;
    public:
        ExpressionFactory();
        ExpressionFactory(const ExpressionFactory& o);
        virtual ~ExpressionFactory();
        Expression<T>* newUnary(Expression<T>* operand = NULL, BinaryExpression<T>* op = NULL);
        Expression<T>* newBinary(Expression<T>* left = NULL, Expression<T>* right = NULL, BinaryExpression<T>* op = NULL);
        Expression<T>* newValue(const T& value);
    protected:
        Expression<T>* hold(Expression<T>* exp);
    };
    
    template<class T>
    ExpressionFactory<T>::ExpressionFactory(){
    }
    
    template<class T>
    ExpressionFactory<T>::ExpressionFactory(const ExpressionFactory& o)
    :_memory(o._memory){
    }
    
    template<class T>
    ExpressionFactory<T>::~ExpressionFactory(){
        for(iterator it = _memory.begin(); it != _memory.end(); it++){
            delete *it;
        }
    }
    
    template<class T>
    Expression<T>* ExpressionFactory<T>::hold(Expression<T>* exp){
        _memory.push_back(exp);
        return exp;
    }
    
    template<class T>
    Expression<T>* ExpressionFactory<T>::newUnary(Expression<T>* operand, BinaryExpression<T>* op){
        return hold(new UnaryModelExpression(operand, op));
    }
    
    template<class T>
    Expression<T>* ExpressionFactory<T>::newBinary(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* op){
        return hold(new BinaryModelExpression(left, right, op));
    }
    
    template<class T>
    Expression<T>* ExpressionFactory<T>::newValue(const T& value){
        return hold(new ValueModel(T));
    }
}

#endif	/* EXPRESSIONFACTORY_H */

