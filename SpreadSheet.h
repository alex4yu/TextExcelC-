#ifndef SPREADSHEET_H  // Include guard to prevent multiple inclusion
#define SPREADSHEET_H

#include <string>
#include <cctype>  // For std::toupper
#include "Cell.h"
#include "SpreadSheetLocation.h"


class SpreadSheet {
private:
    Cell* excel[20][12];  // 2D array of pointers to Cells

public:
    // Constructor
    SpreadSheet();

    // Destructor
    ~SpreadSheet();

    // Process a command and return the result
    std::string processCommand(const std::string& command);

    // Clear the entire spreadsheet
    void clearSpreadSheet();

    // Get the number of rows in the spreadsheet
    int getRows() const;

    // Get the number of columns in the spreadsheet
    int getCols() const;

    // Get the cell at a specific location
    Cell* getCell(const SpreadSheetLocation& loc) const;

    // Get the entire grid as a formatted text string
    std::string getGridText() const;

    // Static helper methods
    static int getColumnNumberFromColumnLetter(const std::string& columnLetter);
    static std::string getColumnLetterFromColumnNumber(int columnNumber);
    static std::string addSpace(int numOfSpaces);
};

#endif  // SPREADSHEET_H