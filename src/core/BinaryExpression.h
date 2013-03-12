/* 
 * File:   BinaryExpression.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:54
 */

#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

namespace core{
    template<class T>
    class BinaryExpression{
    public:
        T evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };
}

#endif	/* BINARYEXPRESSION_H */

