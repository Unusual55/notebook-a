#ifndef ROW_H
#pragma once
#define ROW_H
#include <string>
#include <iostream>
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
        void printRow()
        {
            for (int i = 0; i < LEN; i++)
            {
                cout << Letters[i];
            }
            cout << endl;
        }
        void removeFromRow(int startFrom, int length);
};

#endif