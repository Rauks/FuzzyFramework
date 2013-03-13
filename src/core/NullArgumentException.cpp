/* 
 * File:   NullArgumentException.cpp
 * Author: Karl
 * 
 * Created on 12 mars 2013, 09:33
 */

#include "NullArgumentException.h"

namespace core{
    NullArgumentException::NullArgumentException(std::string msg)
    :_msg(msg){
    }

    NullArgumentException::NullArgumentException(const NullArgumentException& o)
    :_msg(o._msg){
    }

    NullArgumentException::~NullArgumentException() throw(){
    }
    
    const char* NullArgumentException::what() const throw(){
        return _msg.c_str();
    }
}
