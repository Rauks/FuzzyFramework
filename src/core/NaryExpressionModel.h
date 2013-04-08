/* 
 * File:   NaryExpressionModel.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 15:21
 */

#ifndef NARYEXPRESSIONMODEL_H
#define	NARYEXPRESSIONMODEL_H

#include <vector>
#include <iostream>

#include "Expression.h"
#include "NaryExpression.h"
#include "NullArgumentException.h"

namespace core{
    template<class T>
    class NaryExpressionModel : public Expression<T>, public NaryExpression<T>{
    private:
        std::vector<Expression<T>*>* _operands;
        NaryExpression<T>* _op;
    public:
        NaryExpressionModel(std::vector<Expression<T>*>* operands = NULL, NaryExpression<T>* op = NULL);
        NaryExpressionModel(const NaryExpressionModel<T>& o);
        virtual ~NaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(std::vector<Expression<T>*>* operands) const;
<<<<<<< HEAD
=======
        virtual NaryExpression<T>* getOperator() const;
>>>>>>> origin/dev
    };
    
    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(std::vector<Expression<T>*>* operands, NaryExpression<T>* op)
    :_operands(operands), _op(op){
    }
    
    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(const NaryExpressionModel<T>& o)
    :_operands(o._operands), _op(o._op){      
    }
    
    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel(){
    }
    
    template<class T>
    T NaryExpressionModel<T>::evaluate() const{
        if(_operands != NULL)
            return evaluate(_operands);
        throw NullArgumentException("NaryExpression : Operands");
    }
    
    template<class T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>*>* operands) const{
        if(_op != NULL)
            return _op->evaluate(operands);
        throw NullArgumentException("NaryExpression : Operator");
    }
<<<<<<< HEAD
=======
    
    template<class T>
    NaryExpression<T>* NaryExpressionModel<T>::getOperator() const{
        return _op;
    }
>>>>>>> origin/dev
}

#endif	/* NARYEXPRESSIONMODEL_H */

