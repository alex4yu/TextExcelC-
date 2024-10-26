#ifndef VALUECELL_H
#define VALUECELL_H
#include "RealCell.h"
#include <string>

class ValueCell: public RealCell{

    public: 
        ValueCell(const std::string& txt); 
        std::string abbreviatedCellText() const override;  
        std::string fullCellText() const override;        
        double getDoubleValue() const override;  
};

#endif