#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> split(string const &str, char separador)
{
    vector <string> resultado;
    string temp{""};
    bool flag_palabra{0};
    for (int i{0}; i < str.size(); i++)
    {
        if (str.at(i) == separador)
        {
            if (flag_palabra == 1)
            {
                resultado.push_back(temp);
                temp = "";
            }
            flag_palabra = 1;
        }
        else if (flag_palabra = 1)
        {
            temp = temp + str.at(i);
        }
    }
    if (temp != "")
        resultado.push_back(temp);
    return (resultado);
}