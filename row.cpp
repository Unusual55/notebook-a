#include "row.hpp"
#include <string>
#include <iostream>
#include <cctype>
Row::Row()
{
    int i = 0;
    this->Letters = new (nothrow) char[LEN];
    if (this->Letters == nullptr)
    {
        exit(1); // bad allocation;
    }
    this->Filled = new (nothrow) bool[LEN];
    if (this->Filled == nullptr)
    {
        exit(1); // bad allocation;
    }
    for (i = 0; i < LEN; i++)
    {
        this->Letters[i] = '_';
        this->Filled[i] = false;
    }
}

Row::Row(string str, int startFrom){
    int i = 0;
    int charTrack=0;
    int endAt=startFrom+str.length();
    if(startFrom<0||startFrom>=LEN||endAt<0||endAt>=LEN){
        std::__throw_invalid_argument("The inedex you entered is now withing the bounds of a row.");
    }
    this->Letters = new (nothrow) char[LEN];
    if (this->Letters == nullptr)
    {
        exit(1); // bad allocation;
    }
    this->Filled = new (nothrow) bool[LEN];
    if (this->Filled == nullptr)
    {
        exit(1); // bad allocation;
    }
    for (i = 0; i < LEN; i++)
    {
        if(i<startFrom || i>=endAt){
            this->Letters[i] = '_';
            this->Filled[i] = false;
        }
        else{
            this->Letters[i]=str.at(charTrack);
            this->Filled[i]=true;
            charTrack++;
        }
    }
}

Row::~Row(){
    delete[] this->Letters;
    delete[] this->Filled;
}

int Row::getCharStatus(int index){
    if(index<0 || index>=LEN){
        std::__throw_invalid_argument("The inedex you entered is now withing the bounds of a row.");
    }
    return this->Filled[index];
}

bool Row::canWrite(int startFrom, int endAt){
    int i;
    for(i=startFrom;i<endAt;i++){
        //if we found a char which is not available within the given range, then we can't write to this range.
        if(Row::getCharStatus(i)){
            return false;
        }
    }
    //if we did not find any unavailable character within the given range, then we can write to this row.
    return true;
}

void Row::writeToRow(int startFrom, string str){
    int endAt=startFrom+str.length();
    int i;
    int charTrack=0;
    if(!Row::canWrite(startFrom,endAt)){
        std::__throw_invalid_argument("you can't write to this letters in this range");
    }
    for(i=startFrom;i<endAt;i++){
        this->Letters[i]=str.at(charTrack);
        this->Filled[i]=true;
        charTrack++;
    }
}



void Row::removeChar(int index){
    if(index<0 || index>=LEN){
        std::__throw_invalid_argument("The inedex you entered is now withing the bounds of a row.");
    }
    this->Letters[index]='~';
    this->Filled[index]=false;;
}

void Row::removeFromRow(int startFrom, int length){
    int endAt=startFrom+length;
    int i;
    if(startFrom<0 || startFrom>=LEN || endAt<0 || endAt>=LEN){
        std::__throw_invalid_argument("The inedex you entered is now withing the bounds of a row.");
    }
    for(i=startFrom;i<endAt;i++){
        removeChar(i);
    }
}

// int main(){
//     Row r;
//     r.printRow();
//     Row r2=Row("hello world", 45);
//     r2.removeChar(44);
//     r2.printRow();
//     r2.writeToRow(50, "adon shoko");

// }




