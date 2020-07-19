#pragma once
#include <iostream>
#include <vector>

class ChestTable
{
public:
    enum Exceptions { DIFFERENT, OUT_OF_RANGE, WRONG_FORMAT };
    ChestTable();
    ChestTable(int n, int m);
    ChestTable(const ChestTable &a);
    ChestTable& operator=(const ChestTable &a);

    int n = 0, m = 0;


    int getElem(int i, int j);

    friend ChestTable operator+ (const ChestTable &a, const ChestTable &b);
    friend ChestTable operator* (const ChestTable &a, const ChestTable &b);
    friend std::ostream& operator << (std::ostream &s, const ChestTable &a);
    friend std::istream& operator >> (std::istream &s, ChestTable &a);
private:
    ChestTable(int n, int m, const std::vector<int>& mtx);
    std::vector<int> mtx;
};
