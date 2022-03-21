#include "page.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <iterator>
#include <vector>

Page::Page(){
    this->rowCounter=0;
}

Page::~Page(){
    rows.clear();
}

void  Page::addRow(string str, int startFrom){
    rows.push_back(new Row(str, startFrom));
    rowCounter++;
}

void Page::addRow(){
    rows.push_back(new Row());
    rowCounter++;
}

void Page::removeCharAt(int row, int col){
    if(row<0||row>=rowCounter||col<0||col>=LEN){
        std::__throw_invalid_argument("The row or column you entered does not exist.");
        exit(1);
    }
    rows.at(row)->removeChar(col);
}

void Page::writeToRow(int rowIndex, int startFrom, string str, ariel::Direction dir){
    int rowEndIndex;
    int i;
    int j;
    string c;
    if(rowIndex<0||rowIndex>=rowCounter||startFrom<0||startFrom>=LEN){
        std::__throw_invalid_argument("The row or column you entered does not exist.");
        exit(1);
    }
    if(dir==ariel::Direction::Vertical){
        rows.at(rowIndex)->writeToRow(startFrom, str);
        return;
    }       
    else{
        rowEndIndex=rowEndIndex+str.length();
        if(!isRowExist(rowEndIndex-1)){
            std::__throw_invalid_argument("one or more rows does not exist.");
        }
        for(i=rowIndex;i<rowEndIndex;i++){
            if(rows.at(i)->getCharStatus(startFrom)){
                std::__throw_invalid_argument("one or more rows does not exist."); 
                exit(1);
            }
        }
        j=0;
        for(i=rowIndex;i<rowEndIndex;i++){
            c=str.at(j);
            rows.at(i)->writeToRow(startFrom, c);
            j++;
        }
    }
}