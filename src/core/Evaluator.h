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

#include "Expression.h"
#include "ValueModel.h"

namespace core{
    template<class T>
    class Evaluator{
    private:
        typedef typename std::vector<T>::const_iterator const_iterator;
        typedef typename std::vector<T>::iterator iterator;
    public:
        typedef typename std::pair<std::vector<T>, std::vector<T> > Shape;
        static Shape evaluate(const T& min, const T& max, const T& step, ValueModel<T>& var, Expression<T>& exp);
        static std::ostream& printShape(const Shape s, std::ostream& os);
    protected:
        friend std::ostream& operator<<(std::ostream &os, const Shape& s){ return printShape(s, os); }; //Introvert operator
    };
    
    template<class T>
    typename Evaluator<T>::Shape Evaluator<T>::evaluate(const T& min, const T& max, const T& step, ValueModel<T>& var, Expression<T>& exp){
        Shape s;
        for(T i = min; i < max; i += step){
            s.first.push_back(i);
            var.setValue(i);
            s.second.push_back(exp.evaluate());
        }
        return s;
    }
    
    template<class T>
    std::ostream& Evaluator<T>::printShape(const Evaluator<T>::Shape s, std::ostream& os){
        os << std::endl << "Shape : ";
        os << std::endl << "X : ";
        for(const_iterator it = s.first.begin(); it != s.first.end(); it++){
            os << *it << " ";
        }
        os << std::endl << "Y : ";
        for(const_iterator it = s.second.begin(); it != s.second.end(); it++){
            os << *it << " ";
        }
        return os;
    }    
}

#endif	/* EVALUATOR_H */

