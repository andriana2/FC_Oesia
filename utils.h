#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string const &str, char separador);
vector<string> GestionParentesis(string const &str);
string vector_separar_string(string const &linea);
// void get_error_parentesis(string const &str);
// void get_error_letras(string const &str);


#endif