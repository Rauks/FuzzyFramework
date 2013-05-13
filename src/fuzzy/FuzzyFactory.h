/* 
 * File:   FuzzyFactory.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 10:26
 */

#ifndef FUZZYFACTORY_H
#define	FUZZYFACTORY_H

#include <vector>

#include "Agg.h"
#include "And.h"
#include "Is.h"
#include "Not.h"
#include "Or.h"
#include "Then.h"
#include "MamdaniDefuzz.h"
#include "SugenoDefuzz.h"
#include "SugenoDefuzzConclusion.h"

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
#include "../core/NaryShadowExpression.h"

namespace fuzzy{
    template<class T>
    class FuzzyFactory : public core::ExpressionFactory<T>{
    private:
        core::BinaryShadowExpression<T>* _sAnd;
        core::BinaryShadowExpression<T>* _sOr;
        core::UnaryShadowExpression<T>* _sNot;
        core::BinaryShadowExpression<T>* _sThen;
        core::BinaryShadowExpression<T>* _sAgg;
        core::BinaryShadowExpression<T>* _sMamdaniDefuzz;
        core::NaryShadowExpression<T>* _sSugenoDefuzz;
        core::NaryShadowExpression<T>* _sSugenoConclusion;
        
    public:
        FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg, MamdaniDefuzz<T>* sMamdaniDefuzz, SugenoDefuzz<T>* sSugenoDefuzz, SugenoDefuzzConclusion<T>* sSugenoConclusion);
        FuzzyFactory(const FuzzyFactory<T>& o);
        virtual ~FuzzyFactory();
        
        core::Expression<T>* newAnd(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newOr(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newThen(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newAgg(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newMamdaniDefuzz(core::Expression<T>* left, core::Expression<T>* right);
        core::Expression<T>* newSugeno(std::vector<core::Expression<T>*> *operands);
        core::Expression<T>* newConclusion(std::vector<core::Expression<T>*>* operands);
        core::Expression<T>* newNot(core::Expression<T>* op);
        core::Expression<T>* newIs(core::Expression<T>* op, Is<T>* is);
        
        void changeAnd(And<T>* opAnd);
        void changeOr(Or<T>* opOr);
        void changeThen(Then<T>* opThen);
        void changeAgg(Agg<T>* opAgg);
        void changeMamdani(MamdaniDefuzz<T>* opMamdani);
        void changeSugeno(SugenoDefuzz<T>* opSugeno);
        void changeConclusion(SugenoDefuzzConclusion<T>* opSugenoConclusion);
        void changeNot(Not<T>* opNot);
    };
    
    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg, MamdaniDefuzz<T>* opMamdaniDefuzz, SugenoDefuzz<T>* opSugenoDefuzz, SugenoDefuzzConclusion<T>* opSugenoConclusion){
        _sAnd = new core::BinaryShadowExpression<T>(opAnd);
        _sOr = new core::BinaryShadowExpression<T>(opAnd);
        _sNot = new core::UnaryShadowExpression<T>(opNot);
        _sThen = new core::BinaryShadowExpression<T>(opThen);
        _sAgg = new core::BinaryShadowExpression<T>(opAgg);
        _sMamdaniDefuzz = new core::BinaryShadowExpression<T>(opMamdaniDefuzz);
        _sSugenoConclusion = new core::NaryShadowExpression<T>(opSugenoConclusion);
        _sSugenoDefuzz = new core::NaryShadowExpression<T>(opSugenoDefuzz);
    }
    
    template<class T>
    FuzzyFactory<T>::FuzzyFactory(const FuzzyFactory<T>& o){
        _sAnd = new core::BinaryShadowExpression<T>(o._sAnd);
        _sOr = new core::BinaryShadowExpression<T>(o._sAnd);
        _sNot = new core::UnaryShadowExpression<T>(o._sNot);
        _sThen = new core::BinaryShadowExpression<T>(o._sThen);
        _sAgg = new core::BinaryShadowExpression<T>(o._sAgg);
        _sMamdaniDefuzz = new core::BinaryShadowExpression<T>(o._sMamdaniDefuzz);
        _sSugenoConclusion = new core::NaryShadowExpression<T>(o._sSugenoConclusion);
        _sSugenoDefuzz = new core::NaryShadowExpression<T>(o._sSugenoDefuzz);
    }
    
    template<class T>
    FuzzyFactory<T>::~FuzzyFactory(){
        delete _sAnd;
        delete _sOr;
        delete _sNot;
        delete _sThen;
        delete _sAgg;
        delete _sMamdaniDefuzz;
        delete _sSugenoDefuzz;
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
    core::Expression<T>* FuzzyFactory<T>::newMamdaniDefuzz(core::Expression<T>* left, core::Expression<T>* right){
        return newBinary(_sMamdaniDefuzz, left, right);
    }
    
    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<core::Expression<T>*>* operands)
    {
        return newNary(_sSugenoDefuzz, operands);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newConclusion(std::vector<core::Expression<T>*>* operands)
    {
        return newNary(_sSugenoConclusion, operands);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeAnd(And<T>* opAnd){
        _sAnd->setExpression(opAnd);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeOr(Or<T>* opOr){
        _sOr->setExpression(opOr);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeThen(Then<T>* opThen){
        _sThen->setExpression(opThen);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeAgg(Agg<T>* opAgg){
        _sAgg->setExpression(opAgg);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeMamdani(MamdaniDefuzz<T>* opMamdanu){
        _sMamdaniDefuzz->setExpression(opMamdanu);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T>* opSugeno){
        _sSugenoDefuzz->setExpression(opSugeno);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeConclusion(SugenoDefuzzConclusion<T>* opConclusion){
        _sSugenoConclusion->setExpression(opConclusion);
    }
    
    template<class T>
    void FuzzyFactory<T>::changeNot(Not<T>* opNot){
        _sNot->setExpression(opNot);
    }
}

#endif	/* FUZZYFACTORY_H */

