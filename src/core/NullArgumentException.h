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
    private:
        std::string _msg;
    public:
        NullArgumentException(std::string msg);
        NullArgumentException(const NullArgumentException& orig);
        virtual ~NullArgumentException() throw();
        virtual const char * what() const throw();
    };
}

#endif	/* NULLARGUMENTEXCEPTION_H */

