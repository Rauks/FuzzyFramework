/* 
 * File:   MamdaniDefuzz.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 08:59
 */

#ifndef MAMDANIDEFUZZ_H
#define	MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

namespace fuzzy{
    template<class T>
    class MamdaniDefuzz : core::BinaryExpression<T>{
    private:
        T _min;
        T _max;
        T _step;
    public:
        MamdaniDefuzz(const T& min, const T& max, const T& step);
        MamdaniDefuzz(const MamdaniDefuzz<T>& o);
        virtual ~MamdaniDefuzz();
        virtual T evaluate(Expression<T>* left, Expression<T>* right) const;
        virtual T defuzz(core::Evaluator<T>::Shape) = 0;
    };
    
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& min, const T& max, const T& step)
    :_min(min), _max(max), _step(step){
    }
    
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const MamdaniDefuzz<T>& o)
    :_min(o._min), _max(o._max), _step(o._step){
    }
    
    template<class T>
    MamdaniDefuzz<T>::~MamdaniDefuzz(){
    }
    
    /**
     * Use an Evaluator to build the shape. Return the T value calculated with defuzz.
     * 
     * @param left variable for the shape building, must be a ValueModel.
     * @param right expression for the shape building.
     * @return a shape builded with left and right evaluation.
     */
    template<class T>
    T MamdaniDefuzz<T>::evaluate(Expression<T>* left, Expression<T>* right) const{
        return defuzz(core::Evaluator<T>::buildShape(_min, _max, _step, left, right));
    }
}

#endif	/* MAMDANIDEFUZZ_H */

