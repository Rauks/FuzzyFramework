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
#include "../core/NaryExpression.h"

namespace fuzzy{
    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T>{
    private:
        typedef typename std::vector<core::Expression<T>*>::const_iterator const_iterator;
        typedef typename std::vector<core::Expression<T>*>::iterator iterator;
        const SugenoDefuzzConclusion<T>* _conclusion;
    public:
        SugenoDefuzz(const SugenoDefuzzConclusion<T>* conclusion);
        SugenoDefuzz(const SugenoDefuzz<T>& o);
        virtual ~SugenoDefuzz();
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    };
    
    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(const SugenoDefuzzConclusion<T>* conclusion)
    :_conclusion(conclusion){
    }
    
    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(const SugenoDefuzz<T>& o)
    :_conclusion(o._conclusion){
    }
    
    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(){
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
        for(const_iterator it = operands->begin(); it != operands->end(); it++){
            core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*) (*it);
            core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
            T premise = ((ThenSugeno<T>*) bse->getExpression())->premiseValue();
            premises.push_back(core::ValueModel<T>(premise));
            denum += premise;
        }
        
        T num = _conclusion->evaluate(premises);
        
        if(denum == 0){
            throw std::logic_error("Divided by zero");
        }
        return num / denum;
    }
}

#endif	/* SUGENODEFUZZ_H */

