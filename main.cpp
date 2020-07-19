#include <iostream>
#include <fstream>
#include "ChestTable.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Hun");
    bool kilep = false;
    vector<int> mtx;
    ChestTable a;
    ChestTable b;
    int i,j;

    char q;

    do
    {
        cout<<"1.) a matrix beolvasasa fajlbol"<<endl;
        cout<<"2.) a matrix kiiratasa kepernyore"<<endl;
        cout<<"3.) adott elem kiíratasa a matrixbol"<<endl;
        cout<<"4.) matrixok szorzasa"<<endl;
        cout<<"5.) matrixok osszeadasa"<<endl;

        cin >> q;

        if(q=='1')
        {
            ifstream f;
            string path;

            cout << "Adja meg a bemeneti fájlt: ";
            cin >> path;

            cout << "A fájl helye: " << path << endl;

            f.open(path.c_str());
            if(!f)
            {
                cout << "Hibás fájl." << endl;
            }
            else
            {
                try
                {
                    f >> a;
                }
                catch(ChestTable::Exceptions ex)
                {
                    if(ex == ChestTable::OUT_OF_RANGE)
                        cout<<"Out of range! "<<endl;
                    else
                    {
                        cout<<"Unhandled exception! "<<endl;
                    }
                }
                f.close();
            }
        }

        if(q=='2')
        {
            cout << a;
        }
        if(q=='3')
        {
            string elem;
            cout<<"Adja meg a sort: "<<endl;
            cin>>i;
            cout<<"Adja meg az oszlopot: "<<endl;
            cin>>j;
            try
            {
                cout<<"matrix "<<i<<","<<j<<" eleme: "<< a.getElem(i,j) << endl;
            }
            catch(ChestTable::Exceptions ex)
            {
                if(ex == ChestTable::OUT_OF_RANGE)
                    cout<<"Out of range! "<<endl;
                else
                {
                    cout<<"Unhandled exception! "<<endl;
                }
            }
        }
        if(q=='4')
        {
            ifstream f;
            string path;

            cout << "Adja meg a masik bemeneti fájlt: ";
            cin >> path;

            cout << "A fájl helye: " << path << endl;


            f.open(path.c_str());
            if(!f)
            {
                cout << "Hibás fájl." << endl;
            }
            else
            {

                f >> b;


                f.close();
                try{
                cout << "A matrixok szorzata:" << endl;
                cout << a * b << endl;}
                             catch(ChestTable::Exceptions ex)
            {
                if(ex == ChestTable::DIFFERENT)
                    cout<<"Different! "<<endl;
                else
                {
                    cout<<"Unhandled exception! "<<endl;
                }
            }
            }
        }
        if(q=='5')
        {
            ifstream f;
            string path;

            cout << "Adja meg a masik bemeneti fájlt: ";
            cin >> path;

            cout << "A fájl helye: " << path << endl;


            f.open(path.c_str());
            if(!f)
            {
                cout << "Hibás fájl." << endl;
            }
            else
            {
                f >> b;
                f.close();
                try{
                cout << "A matrixok osszege:" << endl;
                cout << a + b << endl;}
                catch(ChestTable::Exceptions ex)
            {
                if(ex == ChestTable::DIFFERENT)
                    cout<<"Different! "<<endl;
                else
                {
                    cout<<"Unhandled exception! "<<endl;
                }
            }
            }
        }
        if (q == 'q' || q == 'Q')
        {
            kilep = true;
        }
        if (!kilep)
        {
            cout<<"nyomja meg a 'q' gombot a kilepeshez"<<endl;
        }
    }
    while(kilep==false);

    return 0;
}

