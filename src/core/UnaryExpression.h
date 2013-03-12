/* 
 * File:   UnaryExpression.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:53
 */

#ifndef UNARYEXPRESSION_H
#define	UNARYEXPRESSION_H

namespace core{
    template<class T>
    class UnaryExpression{
    public:
        virtual T evaluate(Expression<T>* operand) const = 0;
    };
}

#endif	/* UNARYEXPRESSION_H */

