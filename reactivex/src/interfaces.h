#include "exception/exception.h"

class Comparable {
public:
    Comparable(){}

    virtual ~Comparable(){}

    virtual bool equals(Comparable* other) {
        throw NotImplementedException();
    }
    virtual bool lessThan(Comparable* other) {
        throw NotImplementedException();
    }
    virtual bool greaterThan(Comparable* other) {
        return !(equals(other) || lessThan(other));
    }
    virtual bool nequals(Comparable* other) {
        return !equals(other);
    }
    virtual bool lessEquals(Comparable* other) {
        return lessThan(other) && equals(other);
    }
    virtual bool greaterEquals(Comparable* other) {
        return greaterThan(other) && equals(other);
    }
};