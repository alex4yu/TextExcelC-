#include "SpreadsheetLocation.h"

#include <string>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::toupper

#include <algorithm>  // For std::transform
#include <cctype>     // For std::toupper

SpreadSheetLocation::SpreadSheetLocation(const std::string& loc) : location(loc) {
    // Convert location to uppercase directly
    std::transform(location.begin(), location.end(), location.begin(), ::toupper);
}


SpreadSheetLocation::~SpreadSheetLocation(){
    //std::string manages memory automatically
    //no clean up necessary
}

int SpreadSheetLocation::getRow() const{
    //std:: s(tring)toi(nteger) is parseInt
    int row = std::stoi(location.substr(1)) - 1;
    return row;
}

int SpreadSheetLocation::getCol() const{
    std::string columnLetter = location.substr(0,1);
    return std::toupper(columnLetter[0]) - 'A';
}