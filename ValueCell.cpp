#include "ValueCell.h"
#include <string>


ValueCell::ValueCell(const std::string& txt): RealCell(txt){}

// Abbreviated cell text (like truncated or padded value for display)
std::string ValueCell::abbreviatedCellText() const {
    std::string r = RealCell::toString();  // Get the string from RealCell
    
    // If the string is 10 or more characters, truncate to 10 characters
    if (r.length() >= 10) {
        r = r.substr(0, 10);
    } else {
        // If the string is shorter, pad it with spaces to make it exactly 10 characters
        while (r.length() < 10) {
            r += " ";
        }
    }
    
    return r;
}

// Full cell text (the entire unmodified value as a string)
std::string ValueCell::fullCellText() const {
    return RealCell::toString();  // Return the unmodified value from RealCell
}

// Return the value as a double
double ValueCell::getDoubleValue() const {
    return std::stod(RealCell::toString());  // Convert the string to a double
}