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
        T evaluate(Expression<T>* o) const = 0;
    };
}

#endif	/* UNARYEXPRESSION_H */

