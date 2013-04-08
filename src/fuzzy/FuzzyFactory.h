/* 
 * File:   FuzzyFactory.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 10:26
 */

#ifndef FUZZYFACTORY_H
#define	FUZZYFACTORY_H

#include "Agg.h"
#include "And.h"
#include "Is.h"
#include "Not.h"
#include "Or.h"
#include "Then.h"
#include "MamdaniDefuzz.h"

#include "../core/ExpressionFactory.h"

namespace fuzzy{
    template<class T>
    class FuzzyFactory : public core::ExpressionFactory<T>{
    private:
        BinaryShadowExpression<T>* _sAnd;
        BinaryShadowExpression<T>* _sOr;
        UnaryShadowExpression<T>* _sNot;
        BinaryShadowExpression<T>* _sThen;
        BinaryShadowExpression<T>* _sAgg;
        BinaryShadowExpression<T>* _sDefuzz;
    public:
        FuzzyFactory();
        FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg, MamdaniDefuzz<T>* opDefuzz);
        FuzzyFactory(const FuzzyFactory& o);
        virtual ~FuzzyFactory();
        
        Expression<T>* newAnd(Expression<T>* left, Expression<T>* right);
        Expression<T>* newOr(Expression<T>* left, Expression<T>* right);
        Expression<T>* newThen(Expression<T>* left, Expression<T>* right);
        Expression<T>* newAgg(Expression<T>* left, Expression<T>* right);
        Expression<T>* newDefuzz(Expression<T>* left, Expression<T>* right);
        Expression<T>* newNot(Expression<T>* op);
        Expression<T>* newIs(Expression<T>* op, Is<T>* is);
        
        void changeAnd(And<T>* opAnd);
        void changeOr(Or<T>* opOr);
        void changeThen(Then<T>* opThen);
        void changeAgg(Agg<T>* opAgg);
        void changeDefuzz(MamdaniDefuzz<T>* opDefuzz);
        void changeNot(Not<T>* o);
    };
}

#endif	/* FUZZYFACTORY_H */

