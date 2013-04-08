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
     * @param operands Vector of ThenSugeno based expressions
     * @return Evaluation
     * @warning All Expression in operands will be casted into ThenSugeno
     */
    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
        T num = _conclusion->evaluate(operands);
        
        T denum = 0;
        for(const_iterator it = operands->begin(); it != operands->end(); it++){
            T premise = ((ThenSugeno<T>*) (*opIt))->premiseValue();
            denum += premise;
        }
        
        if(denum == 0){
            throw std::logic_error("Divided by zero");
        }
        return num / denum;
    }
}

#endif	/* SUGENODEFUZZ_H */

