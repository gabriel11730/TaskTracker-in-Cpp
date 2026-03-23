#include <iostream>
#include <string>

using namespace std;

#ifndef MI_ESTRUCTURA_H
#define MI_ESTRUCTURA_H

struct Task
{
    string id;
    string status;
    string description;
    string createdAt;
    string updatedAt;
};

#endif // MI_ESTRUCTURA_H

bool searchValue(string cadena);
string extractValue(string cadena, int posicion);

Task GetTask();