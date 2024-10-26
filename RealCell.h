#ifndef REALCELL_H
#define REALCELL_H

#include <string>
#include "Cell.h"

class RealCell: public Cell {
    private:
        std::string text;
    public: 
        RealCell(const std::string& txt);

        std::string abbreviatedCellText() const override;  
        std::string fullCellText() const override;        
        double getDoubleValue() const override;  
        std::string toString() const;


};

#endif