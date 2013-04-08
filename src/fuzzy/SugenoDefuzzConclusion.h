/* 
 * File:   SugenoDefuzzCondition.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 16:51
 */

#ifndef SUGENODEFUZZCONCLUSION_H
#define	SUGENODEFUZZCONCLUSION_H

#include <stdexcept>
#include <vector>

#include "../core/Expression.h"
#include "../core/NaryExpression.h"
#include "ThenSugeno.h"

namespace fuzzy{
    template<class T>
    class SugenoDefuzzConclusion : public core::NaryExpression<T>{
    private:
        typedef typename std::vector<core::Expression<T>*>::const_iterator const_iterator;
        typedef typename std::vector<core::Expression<T>*>::iterator iterator;
        const std::vector<T>* _coeff;
    public:
        SugenoDefuzzConclusion(std::vector<T>* coeff);
        SugenoDefuzzConclusion(const SugenoDefuzzConclusion<T>& o);
        virtual ~SugenoDefuzzConclusion();
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    };
    
    template<class T>
    SugenoDefuzzConclusion<T>::SugenoDefuzzConclusion(std::vector<T>* coeff)
    :_coeff(coeff){
    }
    
    template<class T>
    SugenoDefuzzConclusion<T>::SugenoDefuzzConclusion(const SugenoDefuzzConclusion<T>& o)
    :_coeff(o._coeff){
    }
    
    template<class T>
    SugenoDefuzzConclusion<T>::SugenoDefuzzConclusion(){
    }
    
    /**
     * @param operands Vector of ThenSugeno based expressions
     * @return Evaluation
     * @warning All Expression in operands will be casted into ThenSugeno
     */
    template<class T>
    T SugenoDefuzzConclusion<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
        const_iterator coeffIt = _coeff->begin();
        const_iterator opIt = operands->begin();
        
        T result = 0;
        while(coeffIt != _coeff->end() && opIt != operands->end()){
            T premise = ((ThenSugeno<T>*) (*opIt))->premiseValue();
            result += (*coeffIt) * premise;
            coeffIt++;
            opIt++;
        }
        
        return result;
    }
}

#endif	/* SUGENODEFUZZCONCLUSION_H */

