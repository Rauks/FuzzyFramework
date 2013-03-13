/* 
 * File:   Is.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:50
 */

#ifndef IS_H
#define	IS_H

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy{
    template<class T>
    class Agg : public core::UnaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* operand) const = 0;
    };
}

#endif	/* IS_H */

