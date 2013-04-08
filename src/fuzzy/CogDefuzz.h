/* 
 * File:   CogDefuzz.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 09:00
 */

#ifndef COGDEFUZZ_H
#define	COGDEFUZZ_H

#include <stdexcept>

#include "MamdaniDefuzz.h"
#include "../core/Expression.h"
#include "../core/Evaluator.h"

namespace fuzzy{
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    private:
        typedef typename std::vector<T>::const_iterator const_iterator;
        typedef typename std::vector<T>::iterator iterator;
    public:
        CogDefuzz(const T& min, const T& max, const T& step);
        CogDefuzz(const CogDefuzz<T>& o);
        virtual ~CogDefuzz();
        virtual T defuzz(typename core::Evaluator<T>::Shape) const;
    };
    
    template<class T>
    CogDefuzz<T>::CogDefuzz(const T& min, const T& max, const T& step)
    :MamdaniDefuzz<T>(min, max, step){
    }
    
    template<class T>
    CogDefuzz<T>::CogDefuzz(const CogDefuzz<T>& o)
    :MamdaniDefuzz<T>(o){
    }
    
    template<class T>
    T CogDefuzz<T>::defuzz(typename core::Evaluator<T>::Shape s) const{
        T num = 0;
        T denum = 0;
        T first;
        T second;
        
        const_iterator itf = s.first.begin();
        const_iterator its = s.second.begin();
        while(itf != s.first.end() && its != s.second.end()){
            first = *itf;
            second = *its;
            num += first * second;
            denum += second;
        }
        
        if(denum == 0){
            throw std::logic_error("Divided by zero");
        }
        return num / denum;
    }
}

#endif	/* COGDEFUZZ_H */

