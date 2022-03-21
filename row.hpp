#ifndef ROW_H
#pragma once
#define ROW_H
#include <string>
#define LEN 100
using namespace std;
class Row
{
    char *Letters;
    bool *Filled;

    public:
        Row();
        Row(string str, int startFrom);
        ~Row();
        bool canWrite(int startFrom, int endAt);
        int getCharStatus(int index);
        void writeToRow(int startFrom, string str);
        void removeChar(int index);
};

#endif