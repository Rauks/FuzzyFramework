/* 
 * File:   CogDefuzz.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 09:00
 */

#ifndef COGDEFUZZ_H
#define	COGDEFUZZ_H

#include "MamdaniDefuzz.h"
#include "../core/Expression.h"

namespace fuzzy{
    template<class T>
    class CogDefuzz : MamdaniDefuzz<T>{
    private:
        typedef typename std::vector<T>::const_iterator const_iterator;
        typedef typename std::vector<T>::iterator iterator;
    public:
        CogDefuzz(const T& min, const T& max, const T& step);
        CogDefuzz(const CogDefuzz<T>& o);
        virtual ~CogDefuzz();
        virtual T defuzz(core::Evaluator<T>::Shape) const = 0;
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
    T CogDefuzz<T>::defuzz(core::Evaluator<T>::Shape s) const{
        T num = 0;
        T denom = 0;
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
        
        if(denom == 0){
            return 0;
        }
        return num / denum;
    }
}

#endif	/* COGDEFUZZ_H */

