/* 
 * File:   NullArgumentException.cpp
 * Author: Karl
 * 
 * Created on 12 mars 2013, 09:33
 */

#include "NullArgumentException.h"

namespace core{
    NullArgumentException::NullArgumentException(const std::string& msg)
    :std::invalid_argument(msg){
    }

    NullArgumentException::~NullArgumentException() throw(){
    }
}
