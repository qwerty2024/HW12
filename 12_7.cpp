#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

bool IsKPeriodic(const string &str)
{
    int n = str.size();
    bool rez = false;

    for (int i = 1; i <= n / 2; ++i) // нам нужно хотя бы 2 повторения подстроки, т.е. максимальный размер подстроки равен половине строки...
    {
        if (n % i == 0) // если строка не кратна количеству символов в подстроке, то сразу мимо
        {
            // выделяем подстроку
            string tmp = str.substr(0, i); // выделим подстроку 
            //cout << tmp << endl;
            rez = true;

            // состоит ли строка из подстрок, если да то ретерн тру, иначе идем искать дальше на некст кратность
            for (int j = 1; j < n / i; ++j)
            {
                if (tmp != str.substr(i * j, i))
                {
                    rez = false;
                    break;
                }
            }
        }

        if (rez == true) // если не нашли несовпадений, значит мы нашли период!
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string str;
    
    while(1)
    {
        cout << "Enter str (q - exit): ";
        cin >> str;

        if (str == "q") break;

        if (IsKPeriodic(str))   cout << "Is Periodic!\n";
        else                    cout << "No Periodic!\n";
    }

    return 0;
}

