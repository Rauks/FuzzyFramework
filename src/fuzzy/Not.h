/* 
 * File:   Not.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:50
 */

#ifndef NOT_H
#define	NOT_H

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy{
    template<class T>
    class Not : public core::UnaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* operand) const = 0;
    };
}

#endif	/* NOT_H */

