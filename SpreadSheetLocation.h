#ifndef SPREADSHEETLOCATION_H
#define SPREADSHEETLOCATION_H

#include <string>

class SpreadSheetLocation{
    private: 
        std::string location;
    public:
        SpreadSheetLocation(const std::string& loc);
        ~SpreadSheetLocation();

        int getRow() const;
        int getCol() const;
};
#endif 