#include <iostream>
#include <fstream>
#include <vector>
#include <headers/Utilities.h>
#include <headers/Lexer.h>

using namespace std;

extern vector<Task> tasks; // Declaración externa del vector global

void InitialMappingJsontoVector();

void MenuManagetask();
void AddTask(string description);
void ModifyTask(string id, string newDescription);
void DeleteTask(string id);

void UpdateStatus(string newStatus, string id);
void RefreshUpdateAtField(int index);

void MenuSeeTasks();

void filterTasksByStatus(const string& status);

void overwriteTasksinJson(const vector<Task>& tasks);

void addTaskToVector(Task task);

void printAllTaskInVector();
