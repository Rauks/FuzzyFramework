/* 
 * File:   ExpressionFactory.h
 * Author: Karl
 *
 * Created on 19 mars 2013, 16:45
 */

#ifndef EXPRESSIONFACTORY_H
#define	EXPRESSIONFACTORY_H

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
}

#endif	/* EXPRESSIONFACTORY_H */

