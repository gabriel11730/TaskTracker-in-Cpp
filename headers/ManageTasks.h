#include <iostream>
#include <fstream>
#include <vector>
#include <headers/Utilities.h>
#include <headers/Lexer.h>

using namespace std;

void InitialMappingJsontoVector(vector<Task>& tasks);

void AddTask(vector<Task>& tasks, const string& description);
void UpdateDescription(vector<Task>& tasks, const string& id, const string& newDescription);
void DeleteTask(vector<Task>& tasks, const string& id);
void UpdateStatus(vector<Task>& tasks, const string& newStatus, const string& id);
void RefreshUpdateAtField(vector<Task>& tasks, int index);

void filterTasksByStatus(const vector<Task>& tasks, const string& status);
void overwriteTasksinJson(const vector<Task>& tasks);

void printAllTaskInVector(const vector<Task>& tasks);
