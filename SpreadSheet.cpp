#include "SpreadSheet.h"
#include "SpreadSheetLocation.h"
#include "EmptyCell.h"
#include "TextCell.h"
#include <iostream>
#include <string>
#include <cctype>

// Constructor
SpreadSheet::SpreadSheet() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 12; ++j) {
            excel[i][j] = new EmptyCell();
        }
    }
}

// Destructor to clean up dynamic memory
SpreadSheet::~SpreadSheet() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 12; ++j) {
            delete excel[i][j];
        }
    }
}

// Process a command and return result
std::string SpreadSheet::processCommand(const std::string& command) {
    std::string result = "";

    if (command.length() == 5 && command.substr(0, 5) == "CLEAR") {
        //clear grid
        clearSpreadSheet();
        result = getGridText();
    } else if (command.length() > 6 && command.substr(0, 5) == "CLEAR") {
        //clear cell
        SpreadSheetLocation location(command.substr(command.find(" ") + 1));
        delete excel[location.getRow()][location.getCol()];
        excel[location.getRow()][location.getCol()] = new EmptyCell();
        result = getGridText();
    } else if (command.length() == 3 || command.length() == 2) {
        //get contents of cell
        SpreadSheetLocation location(command);
        result = excel[location.getRow()][location.getCol()]->fullCellText();
    } else if (command.find("\"") != -1) {
        //create text cell at given location
        SpreadSheetLocation location(command.substr(0,command.find(" ")));
        delete excel[location.getRow()][location.getCol()];
        int start = command.find("\"") + 1;
        excel[location.getRow()][location.getCol()] = new TextCell(command.substr(start, command.length() - 1 - start ));
        result = getGridText();
    }
    else{
        result = "Invalid Command";
    }

    return result;
}

// Clear the entire SpreadSheet
void SpreadSheet::clearSpreadSheet() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 12; ++j) {
            delete excel[i][j];
            excel[i][j] = new EmptyCell();
        }
    }
}

// Get number of rows
int SpreadSheet::getRows() const {
    return 20;
}

// Get number of columns
int SpreadSheet::getCols() const {
    return 12;
}

// Get the cell at a specific location
Cell* SpreadSheet::getCell(const SpreadSheetLocation& loc) const {
    return excel[loc.getRow()][loc.getCol()];
}

// Get grid text as a string (formatted output)
std::string SpreadSheet::getGridText() const {
    std::string result = addSpace(3) + "|";
    for (int i = 0; i < 12; ++i) {
        result += getColumnLetterFromColumnNumber(i) + addSpace(9) + "|";
    }
    result += "\n";

    for (int row = 1; row <= 20; ++row) {
        if (row >= 10) {
            result += std::to_string(row) + addSpace(1) + "|";
        } else {
            result += std::to_string(row) + addSpace(2) + "|";
        }
        for (int col = 1; col <= 12; ++col) {
            result += excel[row-1][col-1]->abbreviatedCellText() + "|";
        }
        result += "\n";
    }

    return result;
}

// Static helper methods
int SpreadSheet::getColumnNumberFromColumnLetter(const std::string& columnLetter) {
    return std::toupper(columnLetter[0]) - 'A';
}

std::string SpreadSheet::getColumnLetterFromColumnNumber(int columnNumber) {
    return std::string(1, 'A' + columnNumber);
}

std::string SpreadSheet::addSpace(int numOfSpaces) {
    return std::string(numOfSpaces, ' ');
}
