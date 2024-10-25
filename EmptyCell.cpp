#include "EmptyCell.h"
#include <string>  // For std::string

// Return exactly 10 spaces
std::string EmptyCell::abbreviatedCellText() const {
    return std::string(10, ' ');  // Return a string of 10 spaces
}

// Return an empty string for full cell text
std::string EmptyCell::fullCellText() const {
    return "";
}

// Return 0.0 for the numeric value of an empty cell
double EmptyCell::getDoubleValue() const {
    return 0.0;
}
