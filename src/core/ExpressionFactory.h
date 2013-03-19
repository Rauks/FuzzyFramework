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
        UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* op = NULL, Expression<T>* operand = NULL);
        BinaryExpressionModel<T>* newBinary(BinaryExpression<T>* op = NULL, Expression<T>* left = NULL, Expression<T>* right = NULL);
        ValueModel<T>* newValue(const T& value);
    protected:
        void hold(Expression<T>* exp);
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
    void ExpressionFactory<T>::hold(Expression<T>* exp){
        _memory.push_back(exp);
    }
    
    template<class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* op, Expression<T>* operand){
        UnaryExpressionModel<T>* exp = new UnaryExpressionModel<T>(operand, op);
        hold(exp);
        return exp;
    }
    
    template<class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* op, Expression<T>* left, Expression<T>* right){
        BinaryExpressionModel<T>* exp = new BinaryExpressionModel<T>(left, right, op);
        hold(exp);
        return exp;
    }
    
    template<class T>
    ValueModel<T>* ExpressionFactory<T>::newValue(const T& value){
        ValueModel<T>* exp = new ValueModel<T>(value);
        hold(exp);
        return exp;
    }
}

#endif	/* EXPRESSIONFACTORY_H */

