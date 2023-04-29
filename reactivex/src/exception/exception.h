#ifndef RX_EXCEPTION_EXCEPTION_H
#define RX_EXCEPTION_EXCEPTION_H

#include <exception>

class NotImplementedException : public std::exception
{
public:
    virtual char const* what() { 
        return "Function not implemented!"; 
    }
};

class DisposedException : public std::exception
{
public:
    virtual char const* what() { 
        return "Tried to access disposed element!"; 
    }
};

#endif // RX_EXCEPTION_EXCEPTION_H