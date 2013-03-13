/* 
 * File:   Then.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:51
 */

#ifndef THEN_H
#define	THEN_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{
    template<class T>
    class Then : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const = 0;
    };
}

#endif	/* THEN_H */

