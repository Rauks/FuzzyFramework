/* 
 * File:   NullArgumentException.h
 * Author: Karl
 *
 * Created on 12 mars 2013, 09:33
 */

#ifndef NULLARGUMENTEXCEPTION_H
#define	NULLARGUMENTEXCEPTION_H

#include <stdexcept>

namespace core{
    class NullArgumentException : std::invalid_argument{
    public:
        NullArgumentException(const std::string& msg);
        virtual ~NullArgumentException() throw();
    };
}

#endif	/* NULLARGUMENTEXCEPTION_H */

