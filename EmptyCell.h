#ifndef EMPTYCELL_H  // Include guard to prevent multiple inclusion
#define EMPTYCELL_H

#include "Cell.h"   // Include the base class Cell

class EmptyCell : public Cell {
public:
    // Constructor
    EmptyCell() {}

    //default deconstructor is sufficient

    // Implementations of the pure virtual methods from Cell class
    std::string abbreviatedCellText() const override;  // Return exactly 10 spaces
    std::string fullCellText() const override;         // Return an empty string
    double getDoubleValue() const override;            // Return 0.0
};

#endif  // EMPTYCELL_H
