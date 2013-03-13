/* 
 * File:   isTriangle.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:01
 */

#ifndef ISTRIANGLE_H
#define	ISTRIANGLE_H

#include "Is.h"

namespace fuzzy{
    template<class T>
    class IsTriangle : public Is{
    private:
        T _min;
        T _max;
        T _mid;
    public:
        virtual T evaluate(core::Expression<T>* operand) const;
    };
    
    template<class T>
     T evaluate(core::Expression<T>* operand) const{
        
    }
}

#endif	/* ISTRIANGLE_H */

