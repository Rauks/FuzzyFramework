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
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const = 0;
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
    
    template<class T>
    T SugenoDefuzzConclusion<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
        T result = 0;
        const_iterator coeffIt = _coeff->begin();
        const_iterator opIt = operands->begin();
        
        while(coeffIt != _coeff->end() && opIt != operands->end()){
            result += (*coeffIt) * (*opIt)->evaluate();
            coeffIt++;
            opIt++;
        }
        if(opIt != operands->end()){
            throw std::length_error("Not enougth operands to match coeffs");
        }
        if(coeffIt == operands->end()){
            throw std::length_error("Not enougth coeffs");
        }
        result += (*coeffIt);
        return result;
    }
}

#endif	/* SUGENODEFUZZCONCLUSION_H */

