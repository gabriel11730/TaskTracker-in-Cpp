#include <iostream>
#include <fstream>
#include <vector>
#include <headers/Utilities.h>
#include <headers/Lexer.h>

using namespace std;

void InitialMappingJsontoVector();

void MenuManagetask();
void AddTask();
void ModifyTask();
void DeleteTask();

void MarkTaskComplete();

void MenuSeeTasks();

void overwriteTasksinJson(const vector<Task>& tasks);

void addTaskToVector(Task task);

void printVector();
