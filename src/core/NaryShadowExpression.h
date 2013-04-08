/* 
 * File:   NaryShadowExpression.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 16:12
 */

#ifndef NARYSHADOWEXPRESSION_H
#define	NARYSHADOWEXPRESSION_H

#include <vector>
#include <iostream>

#include "Expression.h"
#include "NaryExpression.h"
#include "NullArgumentException.h"


namespace core{
    template<class T>
    class NaryShadowExpression : public NaryExpression<T>{
    private:
        NaryExpression<T>* _exp;
    public:
        NaryShadowExpression(NaryExpression<T>* exp = NULL);
        NaryShadowExpression(const NaryShadowExpression<T>& o);
        virtual ~NaryShadowExpression();
        virtual T evaluate(std::vector<Expression<T>*>* operands) const;
        virtual void setExpression(NaryExpression<T>* exp);
        virtual NaryExpression<T>* getExpression() const;
    };
    
    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression(BinaryExpression<T>* exp)
    :_exp(exp){
    }
    
    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression(const NaryShadowExpression<T>& o)
    :_exp(o._exp){
    }
    
    template<class T>
    NaryShadowExpression<T>::~NaryShadowExpression(){
    }
    
    template<class T>
    T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*>* operands) const{
        if(_exp != NULL)
            return _exp->evaluate(operands);
        throw NullArgumentException("NaryShadowExpression : Expression");
    }
    
    template<class T>
    void NaryShadowExpression<T>::setExpression(NaryExpression<T>* exp){
        _exp = exp;
    }
    
    template<class T>
    NaryExpression<T>* NaryShadowExpression<T>::getExpression() const{
        return _exp;
    }
}

#endif	/* NARYSHADOWEXPRESSION_H */

