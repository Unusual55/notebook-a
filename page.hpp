#ifndef PAGE_H
#pragma once
#define PAGE_H
#include <string>
#include "row.hpp"
#include <vector>
#include "Direction.hpp"
using namespace std;
using namespace ariel;
class Page
{
        std::vector<Row *> rows;
        int rowCounter;
        ~Page();

    public:
        Page();
        int getRowCount() { return this->rowCounter; }
        bool isRowExist(int rowIndex) { return rowIndex >= 0 && rowIndex < rowCounter; }
        void addRow(string str, int startFrom);
        void addRow();
        void removeCharAt(int row, int col);
        void writeToRow(int rowIndex, int startFrom, string str, ariel::Direction dir);
        void removeFromPage(int rowIndex, int startFrom, int length, ariel::Direction dir);
};

#endif