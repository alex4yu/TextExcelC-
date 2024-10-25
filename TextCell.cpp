#include <string>
#include "TextCell.h"


TextCell::TextCell(const std::string& str): text(str) {}


std::string TextCell::abbreviatedCellText() const {
    if(text.length() > 10){
        return text.substr(0,10);
    }
    else{
        int dif = 10 - text.length();
        return text + std::string(dif,' ');
    }
}

std::string TextCell::fullCellText() const {
    return text;
}

double TextCell::getDoubleValue() const {
    return 0.0;
}

