/* 
 * File:   Agg.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 10:51
 */

#ifndef AGG_H
#define	AGG_H

#include "../core/Expression.h"
#include "../core/BinaryExpression.h"

namespace fuzzy{
    template<class T>
    class Agg : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const = 0;
    };
}

#endif	/* AGG_H */

