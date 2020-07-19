#include "ChestTable.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


ChestTable::ChestTable()
{
}

ChestTable::ChestTable(int n, int m)
{
    this->n = n;
    this->m = m;
    this->mtx.reserve(ceil(n*m*0.5));
}

ChestTable::ChestTable(const ChestTable &a)
{
    this->n = a.n;
    this->m = a.m;
    this->mtx.assign(a.mtx.begin(), a.mtx.end());
}

ChestTable::ChestTable(int n, int m, const vector<int>& mtx)
{
    this->n = n;
    this->m = m;
    this->mtx = mtx;
}

ChestTable& ChestTable::operator=(const ChestTable& a)
{
    if(this==&a)
        return *this;

    if(this->n != a.n || this->m != a.m)
        throw DIFFERENT;

    this->n = n;
    this->m = m;
    this->mtx.assign(a.mtx.begin(), a.mtx.end());
    return *this;
}

int ChestTable::getElem(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m)
    {
        throw OUT_OF_RANGE;
    }
    // Paratlan osszeg mindig 0
    if ((i + j) % 2 != 0)
        return 0;
    // A ceil fuggveny kezeli a paratlan matrix dimenziokat
    int elemszam = ceil((i-1) * n *0.5) + ceil(j*0.5) - 1;
    return mtx[elemszam];
}

ChestTable operator+(const ChestTable& a, const ChestTable& b)
{
    if (a.n != b.n || a.m != b.m)
    {
        throw ChestTable::DIFFERENT;
    }
    vector<int> mtx(a.mtx.size());
    for (int i = 0; i < a.mtx.size(); i++)
    {
        mtx.at(i) = a.mtx.at(i) + b.mtx.at(i);
    }
    ChestTable retVal(a.n, a.m, mtx);
    return retVal;
}

ChestTable operator*(const ChestTable& a, const ChestTable& b)
{
    if (a.n != b.n || a.m != b.m)
    {
        throw ChestTable::DIFFERENT;
    }
    vector<int> mtx(a.mtx.size());
    for (int i = 0; i < a.mtx.size(); i++)
    {
        mtx.at(i) = a.mtx.at(i) * b.mtx.at(i);
    }
    ChestTable retVal(a.n, a.m, mtx);
    return retVal;
}

ostream& operator<<(ostream& s, const ChestTable& a)
{
    int c=0;
    for (int i = 0; i < (a.n * a.m); i++)
    {
        if (a.n%2!=0)  // Paros elem (1,1) => i=0, (1,3) => i=2 kiiratando elem
        {
            if (i % 2 == 0)
            {
                s << a.mtx[i/2] << " ";

            }
            else
            {

                s << "0 ";
            }
            if ((i + 1) % a.n == 0)
            {
                s << "\n";

            }
        }
        else
        {
            if(c%2==0)
            {
                if (i % 2 == 0)
                {
                    s << a.mtx[i/2] << " ";

                }
                else
                {

                    s << "0 ";
                }

                if((i +1 ) % a.n == 0)
                {

                    s << "\n";
                    c++;


                }
            }
            else
            {
                if(i%2==0)
                {
                    s << "0 ";
                }
                if(i%2!=0)
                {

                    s << a.mtx[i/2+1] << " ";
                }

                if ((i+1)  % a.n == 0)
                {

                    s << "\n";
                    c++;

                }
            }
        }



    }
    return s;
}

istream& operator>>(istream& s, ChestTable& a)
{
    int n,m;
    vector<int> mtx;

    s >> a.n >> a.m;
    if (a.n <= 0 || a.m <= 0)
    {
        throw ChestTable::OUT_OF_RANGE;
    }
    a.mtx.resize(ceil(a.n * a.m * 0.5));
    int tmp;
    int i = 0;
    while(s >> tmp)
    {
        if (tmp!= 0)
        {
            a.mtx[i]=tmp;

            /*a.mtx.at(i / 2) = tmp;*/
        }
        else
        {
            i++;
        }
        /*else if (tmp == 0) {
           i++;
           // Ha a paratlan elem nem 0, akkor nem sakktabla matrix
           throw ChestTable::WRONG_FORMAT;
        }*/
    }
    return s;
}





