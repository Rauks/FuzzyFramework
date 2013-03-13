/* 
 * File:   Or.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:50
 */

#ifndef OR_H
#define	OR_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{
    template<class T>
    class Or : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const = 0;
    };
}

#endif	/* OR_H */

