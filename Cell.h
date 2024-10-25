#ifndef CELL_H
#define CELL_H
#include <string>

class Cell{
public:
    virtual ~Cell() {};

    virtual std::string abbreviatedCellText() const = 0;
    virtual std::string fullCellText() const = 0;
    virtual double getDoubleValue() const = 0;

};

#endif 