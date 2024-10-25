#ifndef TEXTCELL_H
#define TEXTCELL_H

#include <string>
#include "Cell.h"
class TextCell : public Cell{
    private: 
        std::string text;
    public:
        TextCell(const std::string& str);
        //default deconstructor is sufficient

        std::string abbreviatedCellText() const override;  
        std::string fullCellText() const override;        
        double getDoubleValue() const override;                  
};
#endif 