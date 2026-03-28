#include <headers/ManageTasks.h>

void InitialMappingJsontoVector(vector<Task>& tasks){
    string jsonText;
    ifstream archivo_tarea("tasks.json");
    if (archivo_tarea.is_open())
    {
        while (getline(archivo_tarea, jsonText))
        {
            if (searchValue(jsonText))
            {
                tasks.emplace_back(GetTask());
            }
        }
        
        archivo_tarea.close();
    }
    else
    {
        cerr << "Task.json was not found, a new file will be created!" << endl;
    }
}


void AddTask(vector<Task>& tasks, const string& description){
    Task newTask;

    if (tasks.empty())
    {
        newTask.id = "1";
    }
    else
    {
        const Task& lastTask = tasks.back();
        int newLastId = stoi(lastTask.id) + 1;
        newTask.id = to_string(newLastId);
    }
    newTask.description = description;
    newTask.status = "todo";
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    newTask.createdAt = 
    to_string(ahora->tm_mday) +  "/" +
    to_string(ahora->tm_mon + 1) + "/" + 
    to_string(ahora->tm_year + 1900);
    newTask.updatedAt = newTask.createdAt;

    tasks.emplace_back(newTask);
    cout<< "Task added successfully (ID: " << newTask.id << ")" << endl;
}

void UpdateDescription(vector<Task>& tasks, const string& id, const string& newDescription){
    if (tasks.empty())
    {
        cout<< "There are no saved task" << endl;
        return;
    }

    bool found = false;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i].id == id)
        {
            tasks[i].description = newDescription;
            RefreshUpdateAtField(tasks, static_cast<int>(i));
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout<< "No task was found with that ID" << endl;
    }
}

void DeleteTask(vector<Task>& tasks, const string& id){
    if (tasks.empty())
    {
        cout<< "There are no tasks to delete." << endl;
        return;
    }

    auto it = remove_if(tasks.begin(), tasks.end(), [&id](const Task& task) {
        return task.id == id;
    });

    if (it != tasks.end())
    {
        tasks.erase(it, tasks.end());
        cout<< "Task deleted" << endl;
    }
    else
    {
        cout<< "No task was found with that ID." << endl;
    }
}

void UpdateStatus(vector<Task>& tasks, const string& newStatus, const string& id){
    if (tasks.empty())
    {
        cout<< "There are no saved task" << endl;
        return;
    }

    bool found = false;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i].id == id)
        {
            tasks[i].status = newStatus;
            RefreshUpdateAtField(tasks, static_cast<int>(i));
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout<< "No task was found with that ID." << endl;
    }
}

void RefreshUpdateAtField(vector<Task>& tasks, int index)
{
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    if (index >= 0 && index < static_cast<int>(tasks.size()))
    {
        tasks[index].updatedAt = 
        to_string(ahora->tm_mday) +  "/" +
        to_string(ahora->tm_mon + 1) + "/" + 
        to_string(ahora->tm_year + 1900);
    }
    else
    {
        cout<< "Invalid Index" << endl;
    }
}

void filterTasksByStatus(const vector<Task>& tasks, const string& status)
{
    if (tasks.empty()) {
        cout << "There are no task to show." << endl;
    } else {
        cout << "Tasks "<< status << ":" << endl;
        for (const auto& task : tasks) {
            if (task.status == status) {
                cout << "ID: " << task.id << endl;
                cout << "Description: " << task.description << endl;
                cout << "Created At: " << task.createdAt << endl;
                cout << "Updated At: " << task.updatedAt << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
}

void printAllTaskInVector(const vector<Task>& tasks){
    cout << " Saved Task:" << endl;
    cout << "-----------------------------" << endl;
    for (const auto& task : tasks) {
        cout << "ID: " << task.id << endl;
        cout << "Status: " << task.status << endl;
        cout << "Description: " << task.description << endl;
        cout << "Created At: " << task.createdAt << endl;
        cout << "Updated At: " << task.updatedAt << endl;
        cout << "-----------------------------" << endl;
    }
}


void overwriteTasksinJson(const std::vector<Task>& tasks) {
    ofstream archivo("tasks.json");

    if (!archivo.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    archivo << "[\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        archivo << "  {\n";
        archivo << "    \"id\":\"" << tasks[i].id << "\",\n";
        archivo << "    \"status\":\"" << tasks[i].status << "\",\n";
        archivo << "    \"description\":\"" << tasks[i].description << "\",\n";
        archivo << "    \"createdAt\":\"" << tasks[i].createdAt << "\",\n";
        archivo << "    \"updatedAt\":\"" << tasks[i].updatedAt << "\"\n";
        archivo << "  }";

        if (i < tasks.size() - 1) {
            archivo << ",\n";
        } else {
            archivo << "\n";
        }
    }
    archivo << "]\n";
    archivo.close();
}