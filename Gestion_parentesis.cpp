#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> soccer(string str)
{
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
                cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));
            }
            num_cerrado++;
            if ((num_abierto - num_cerrado) == 0)
            {
                num_abierto = 0;
                num_cerrado = 0;
                cout << str.substr(abierto_inicio + 1, i - abierto_inicio - 1)<< endl;
                resultado.push_back(str.substr(abierto_inicio + 1, i - abierto_inicio - 1));

            }
        }
    }
    return (resultado);
    
}

int main()
{
    //_________ej2__________
    vector <string> cadena(soccer("((hola)(que))(tal)(estas)"));
        

    return (0);
}
