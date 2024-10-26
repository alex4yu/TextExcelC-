#include "RealCell.h"
#include <string>

RealCell::RealCell(const std::string& txt): text(txt) {}

// Return exactly 10 spaces
std::string RealCell::abbreviatedCellText() const {
    return std::string(10, ' ');  // Return a string of 10 spaces
}

// Return an empty string for full cell text
std::string RealCell::fullCellText() const {
    return "";
}

// Return 0.0 for the numeric value of an empty cell
double RealCell::getDoubleValue() const {
    return 0.0;
}

std::string RealCell::toString() const {
    return text;
}