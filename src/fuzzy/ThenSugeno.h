/* 
 * File:   ThenSugeno.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 16:34
 */

#ifndef THENSUGENO_H
#define	THENSUGENO_H

#include "../core/Expression.h"
#include "Then.h"

namespace fuzzy{
    template<class T>
    class ThenSugeno : public Then<T>{
    private:
        mutable T _premise;
    public:
        ThenSugeno();
        ThenSugeno(const ThenSugeno<T>& o);
        virtual ~ThenSugeno();
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right) const;
        virtual T premiseValue() const;
    };
    
    template<class T>
    ThenSugeno<T>::ThenSugeno()
    :_premise(0){
    }
    
    template<class T>
    ThenSugeno<T>::ThenSugeno(const ThenSugeno<T>& o)
    :_premise(o._premise){
    }
    
    template<class T>
    ThenSugeno<T>::~ThenSugeno(){
    }
    
    template<class T>
    T ThenSugeno<T>::evaluate(core::Expression<T>* cond, core::Expression<T>* result) const{
        T lt = cond->evaluate();
        _premise = lt;
        T rt = result->evaluate();
        return lt * rt;
    }
    
    template<class T>
    T ThenSugeno<T>::premiseValue() const{
        return _premise;
    }
}

#endif	/* THENSUGENO_H */

