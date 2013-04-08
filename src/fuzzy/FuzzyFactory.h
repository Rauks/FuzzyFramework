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

#include "AndMult.h"
#include "OrPlus.h"
#include "ThenMult.h"
#include "AggPlus.h"
#include "NotMinus1.h"
#include "CogDefuzz.h"

#include "../core/Expression.h"
#include "../core/ExpressionFactory.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"

namespace fuzzy{
    template<class T>
    class FuzzyFactory : public core::ExpressionFactory<T>{
    private:
        core::BinaryShadowExpression<T>* _sAnd;
        core::BinaryShadowExpression<T>* _sOr;
        core::UnaryShadowExpression<T>* _sNot;
        core::BinaryShadowExpression<T>* _sThen;
        core::BinaryShadowExpression<T>* _sAgg;
        core::BinaryShadowExpression<T>* _sDefuzz;
        
        static AndMult<T> DEFAULT_AND;
        static OrPlus<T> DEFAULT_OR;
        static ThenMult<T> DEFAULT_THEN;
        static AggPlus<T> DEFAULT_AGG;
        static NotMinus1<T> DEFAULT_NOT;
        static CogDefuzz<T> DEFAULT_DEFUZZ;
        
    public:
        FuzzyFactory();
        FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg, MamdaniDefuzz<T>* opDefuzz);
        FuzzyFactory(const FuzzyFactory& o);
        virtual ~FuzzyFactory();
        
        core::Expression<T>* newAnd(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newOr(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newThen(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newAgg(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newDefuzz(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newNot(core::Expression<T>* op);
        core::Expression<T>* newIs(core::Expression<T>* op, Is<T>* is);
        
        void changeAnd(And<T>* opAnd);
        void changeOr(Or<T>* opOr);
        void changeThen(Then<T>* opThen);
        void changeAgg(Agg<T>* opAgg);
        void changeDefuzz(MamdaniDefuzz<T>* opDefuzz);
        void changeNot(Not<T>* opNot);
    };
    
    template<class T>
    FuzzyFactory<T>::FuzzyFactory()
    :FuzzyFactory(DEFAULT_AND, DEFAULT_OR, DEFAULT_NOT, DEFAULT_THEN, DEFAULT_AGG, DEFAULT_DEFUZZ){
    }
    
    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg, MamdaniDefuzz<T>* opDefuzz){
        _sAnd = new core::BinaryShadowExpression<T>(opAnd);
        _sOr = new core::BinaryShadowExpression<T>(opAnd);
        _sNot = new core::UnaryShadowExpression<T>(opNot);
        _sThen = new core::BinaryShadowExpression<T>(opThen);
        _sAgg = new core::BinaryShadowExpression<T>(opAgg);
        _sDefuzz = new core::BinaryShadowExpression<T>(opDefuzz);
    }
    
    template<class T>
    FuzzyFactory<T>::~FuzzyFactory(){
        delete _sAnd;
        delete _sOr;
        delete _sNot;
        delete _sThen;
        delete _sAgg;
        delete _sDefuzz;
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* left, core::Expression<T>* right){
        return newBinary(_sAnd, left, right);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* left, core::Expression<T>* right){
        return newBinary(_sOr, left, right);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* left, core::Expression<T>* right){
        return newBinary(_sThen, left, right);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* left, core::Expression<T>* right){
        return newBinary(_sAgg, left, right);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* op){
        return newUnary(_sNot, op);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newIs(core::Expression<T>* op, Is<T>* is){
        return newUnary(is, op);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeAnd(And<T>* opAnd){
        _sAnd.setExpression(opAnd);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeOr(Or<T>* opOr){
        _sOr.setExpression(opOr);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeThen(Then<T>* opThen){
        _sThen.setExpression(opThen);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeAgg(Agg<T>* opAgg){
        _sAgg.setExpression(opAgg);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>* opDefuzz){
        _sDefuzz.setExpression(opDefuzz);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeNot(Not<T>* opNot){
        _sNot.setExpression(opNot);
    }
}

#endif	/* FUZZYFACTORY_H */

