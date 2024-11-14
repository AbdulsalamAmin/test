#include "shape.h"

class Shape {
public:
    virtual void create() = 0;
    virtual void print() const = 0;
    virtual ~Shape() {}
};
