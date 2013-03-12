/* 
 * File:   ValueModel.h
 * Author: Karl
 *
 * Created on 5 mars 2013, 17:56
 */

#ifndef VALUEMODEL_H
#define	VALUEMODEL_H

#include <iostream>

namespace core{
    template<class T>
    class ValueModel : public Expression{
    private:
        T _value;
    public:
        ValueModel(T value);
        ValueModel(const ValueModel<T>& o);
        virtual ~ValueModel();
        void setValue(T value);
        virtual T evaluate() const;
    };
    
    template<class T>
    ValueModel<T>::ValueModel(T value)
    :_value(value){
    }

    template<class T>
    ValueModel<T>::ValueModel(const ValueModel<T>& o)
    :_value(o._value){
    }

    template<class T>
    ValueModel<T>::~ValueModel(){
    }
    
    template<class T>
    void ValueModel<T>::setValue(T value){
        _value = value;
    }
    
    template<class T>
    T ValueModel<T>::evaluate() const{
        return _value;
    }
}

#endif	/* VALUEMODEL_H */

