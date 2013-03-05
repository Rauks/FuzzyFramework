/* 
 * File:   Expression.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:53
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

namespace core{
    template<class T>
    class Expression{
    public:
        T evaluate() const = 0;
    };
}

#endif	/* EXPRESSION_H */

