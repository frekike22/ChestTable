

#include "Read.h"

void beolvas(string fnev, int &n, vector<vector<int> > &t)
{
    ifstream f;
    bool hiba=false;
    //Ha hib�s f�jlnevet adtunk meg, m�sikat k�r
    do
    {
        f.open(fnev.c_str());
        if (f.fail())
        {
            cout <<"Nincs meg a fajl!" <<endl;
            f.clear();
            hiba=true;
            cout <<"Kerem a fajl nevet! ";
            cin >>fnev; //Billenty�zetr�l olvassa a f�jl nev�t
        } else hiba=false;
    } while(hiba);
    int i,j;
    string tmp;
    f >> tmp;
    n=atoi(tmp.c_str());//Sorok sz�ma
    t.resize(n); //m�trix sorainak lefoglal�sa
    for (i=0; i<n; i++)
    {
        t[i].resize(5); //Tudjuk, hogy h�ny elem van egy sorban.
        for (j=0; j<5; j++)
        {
            f >> t[i][j];
            cout << t[i][j]<<'\t';
        }
        cout << endl;
    }
    f.close();
}
