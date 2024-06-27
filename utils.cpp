#include "utils.h"

using namespace std;

void get_error_parentesis(string const &str)
{
    int num_abierto{0};
    int num_cerrado{0};
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
        {
            num_abierto++;
        }
        else if (str.at(i) == ')')
        {
            num_cerrado++;
        }
    }
    if ((num_abierto - num_cerrado) != 0)
        throw invalid_argument("No tiene suficientes parentesis");

}

void get_error_letras(string const &str)
{
    int flag_parentesis{0};
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
        {
            flag_parentesis = 1;
        }
        else if (str.at(i) == ')')
        {
            if (flag_parentesis == 1)
                throw invalid_argument("Parentesis cerado y abierto seguido");
        }
        else 
            flag_parentesis = 0;

    }
}


vector <string> GestionParentesis(string const &str)
{
    get_error_parentesis(str);
    //get_error_letras(str);
    vector <string> resultado;
    int num_abierto{0};
    bool flag_abierto{0};
    int num_cerrado{0};
    int abierto_inicio;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
        {
            flag_abierto = 1;
            num_abierto++;
            if (num_abierto == 1)
            {
                abierto_inicio = i;
            }
        }
        if (str.at(i) == ')')
        {
            if(flag_abierto == 1 && num_abierto == 1)
            {
                num_abierto = 0;
                flag_abierto = 0;
                //cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));
            }
            num_cerrado++;
            if ((num_abierto - num_cerrado) == 0)
            {
                num_abierto = 0;
                num_cerrado = 0;
                //cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));

            }
        }
    }
    return (resultado);
    
}


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

string vector_separar_string(string const &linea)
{
    int i{0};
    int valor{0};
    while (i < linea.size())
    {
        if (linea.at(i) == ')')
            valor = i;
        i++;
    }
    string nueva_linea = linea.substr(valor + 1, linea.size() - valor);
    return (nueva_linea);
}