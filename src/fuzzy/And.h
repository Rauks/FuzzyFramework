/* 
 * File:   And.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:49
 */

#ifndef AND_H
#define	AND_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{
    template<class T>
    class And : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const = 0;
    };
}

#endif	/* AND_H */

