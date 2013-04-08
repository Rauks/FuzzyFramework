/* 
 * File:   NaryExpression.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 14:54
 */

#ifndef NARYEXPRESSION_H
#define	NARYEXPRESSION_H

#include <vector>

#include "Expression.h"

namespace core{
    template<class T>
    class NaryExpression{
    public:
        virtual T evaluate(std::vector<Expression<T>*>* operands) const = 0;
    };
}

#endif	/* NARYEXPRESSION_H */
