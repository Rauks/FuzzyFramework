/* 
 * File:   Evaluator.h
 * Author: Karl
 *
 * Created on 18 mars 2013, 09:26
 */

#ifndef EVALUATOR_H
#define	EVALUATOR_H

#include <vector>
#include <iostream>

#include "src/core/Expression.h"
#include "src/core/ValueModel.h"

namespace core{
    template<class T>
    class Evaluator{
    public:
        typedef std::pair<std::vector<T>, std::vector<T> > Shape;
        static Evaluator<T>::Shape evaluate(const T& min, const T& max, const T& step, const Expression<T>& var, const Expression<T>& exp);
        static std::ostream& printShape(const Evaluator<T>::Shape s, std::ostream& os);
    };
    
    template<class T>
    static typename Evaluator<T>::Shape Evaluator<T>::evaluate(const T& min, const T& max, const T& step, ValueModel<T>& var, Expression<T>& exp){
        typename Evaluator<T>::Shape s;
        for(T i = min; i < max; i += step){
            s.first.push_back(i);
            var.setValue(i);
            s.second.push_back(exp.evaluate());
        }
        return s;
    }
    
    template<class T>
    static std::ostream& Evaluator<T>::printShape(const Evaluator<T>::Shape s, std::ostream& os){
        os << "Shape : " << std::endl;
        os << "X : " << std::endl;
        for(std::vector<T>::const_iterator it = s.first.begin(); it != s.first.end(); it++){
            os << *it << " ";
        }
        os << "Y : " << std::endl;
        for(std::vector<T>::const_iterator it = s.second.begin(); it != s.second.end(); it++){
            os << *it << " ";
        }
        return os;
    }
}

#endif	/* EVALUATOR_H */

