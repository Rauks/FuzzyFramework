/* 
 * File:   BinaryExpression.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:54
 */

#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

#include "Expression.h"

namespace core{
    template<class T>
    class BinaryExpression{
    public:
        virtual T evaluate(Expression<T>* left, Expression<T>* right) const = 0;
    };
}

#endif	/* BINARYEXPRESSION_H */

