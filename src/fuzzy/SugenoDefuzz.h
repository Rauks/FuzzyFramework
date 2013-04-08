/* 
 * File:   SugenoDefuzz.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 16:51
 */

#ifndef SUGENODEFUZZ_H
#define	SUGENODEFUZZ_H

#include <vector>

#include "../core/Expression.h"
#include "../core/BinaryExpressionModel.h"
#include "../core/BinaryShadowExpression.h"

#include "SugenoDefuzzConclusion.h"

namespace fuzzy{
    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T>{
    private:
        typedef typename std::vector<core::Expression<T>*>::const_iterator const_iterator;
        typedef typename std::vector<core::Expression<T>*>::iterator iterator;
    public:
        SugenoDefuzz();
        SugenoDefuzz(const SugenoDefuzz<T>& o);
        virtual ~SugenoDefuzz();
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    };
    
    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(){
    }
    
    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(const SugenoDefuzz<T>& o){
    }
    
    template<class T>
    SugenoDefuzz<T>::~SugenoDefuzz(){
    }
    
    /**
     * @param operands Vector of BinaryExpressionModel > BinaryShadowExpression > ThenSugeno based expressions.
     * ThenSugeno created with FuzzyFactory#newThenSugeno are well formed.
     * 
     * @return Evaluation
     * @warning All Expression in operands will be casted into ThenSugeno
     */
    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
        std::vector<core::ValueModel<T>*> premises;
        
        T denum = 0;
        T num = 0;
        for(const_iterator it = operands->begin(); it != operands->end(); it++){
            core::Expression<T>* operand = (*it);
            core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*) operand;
            core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
            T premise = ((ThenSugeno<T>*) bse->getExpression())->premiseValue();
            denum += premise;
            num += operand->evaluate();
        }
        
        if(denum == 0){
            throw std::logic_error("Divided by zero");
        }
        return num / denum;
    }
}

#endif	/* SUGENODEFUZZ_H */

