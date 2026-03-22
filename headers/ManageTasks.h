#include <iostream>
#include <fstream>
#include <vector>
#include <headers/Lexer.h>

using namespace std;

void MenuManagetask();
void AddTask();
void ModifyTask();
void DeleteTask();

void MarkTaskComplete();

void MenuSeeTasks();

// Funciones de debug, luego seran reemplazadas por funciones relacionadas

void addTaskToVector(Task task);

void printVector();