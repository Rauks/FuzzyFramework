/* 
 * File:   NorMinus1.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:01
 */

#ifndef NOTMINUS1_H
#define	NOTMINUS1_H

#include "Not.h"

namespace fuzzy{
    template<class T>
    class NotMinus1 : public Not{
    public:
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
     T evaluate(core::Expression<T>* operand) const{
        return 1 - operand->evaluate();
    }
}

#endif	/* NOTMINUS1_H */

