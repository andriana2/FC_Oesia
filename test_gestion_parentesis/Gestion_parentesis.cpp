#include <iostream>
#include <string>
#include <vector>

using namespace std;

void get_error_parentesis(string const &str)
{
    int num_abierto{0};
    int num_cerrado{0};
    int flag_parentesis{0};
    if (str.at(0) != '(')
        throw invalid_argument("No inicia con parentesis");
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '(')
        {
            flag_parentesis = 1;
            num_abierto++;
        }
        else if (str.at(i) == ')')
        {
            if (flag_parentesis == 1)
                throw invalid_argument("Parentesis cerado y abierto seguido");
            num_cerrado++;
        }
        else 
        {
            if ((num_abierto - num_cerrado) == 0)
                throw invalid_argument("Hay una palabra sin parentesis");
            flag_parentesis = 0;
        }
    }
    if ((num_abierto - num_cerrado) != 0)
        throw invalid_argument("No tiene suficientes parentesis");
    if (str.at(str.size() - 1) != ')')
        throw invalid_argument("No termina en parentesis cerrado");

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

/*int main()
{
    //_________ej2__________
    vector <string> cadena soccer("((hola)(que))(tal)(estas)");
        

    return (0);
}*/
