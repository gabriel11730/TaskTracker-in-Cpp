#include <functional>
#include <unordered_map>
#include <headers/Utilities.h>
#include <headers/ManageTasks.h>
#include <main/task-tracker.h>

namespace TaskTracker
{
    static vector<Task> tasks;

    int add_task(int, char**);
    int update_description(int, char**);
    int delete_task(int, char**);
    int update_status(int, char**);
    int list_tasks(int, char**);
    int help(int, char**);

    static unordered_map<string, function<int(int, char**)>> command_map = {
        {"add", add_task},
        {"update", update_description},
        {"delete", delete_task},
        {"mark", update_status},
        {"list", list_tasks},
        {"help", help}
    };
}

int TaskTracker::handle_command(int argc, char* argv[]){
    if (argc < 2) {
        cout << "No command provided." << endl;
        cout << "Usage: " << argv[0] << " help " << endl;
        return 1;
    }
    InitialMappingJsontoVector(tasks);
    const string command = argv[1];

    if (command.rfind("mark-", 0) == 0) {
        return update_status(argc, argv);
    }

    auto it = command_map.find(command);
    if (it != command_map.end()) {
        return it->second(argc, argv);
    } else {
        cout << "Unknown command: " << command << endl;
        cout << "Usage: " << argv[0] << " help " << endl;
        return 1;
    }
}

int TaskTracker::add_task(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "Usage: " << argv[0] << " add <task description>" << endl;
        return 1;
    }
    string task_description = argv[2];
    AddTask(tasks, task_description);
    overwriteTasksinJson(tasks);
    return 0;
}

int TaskTracker::update_description(int argc, char* argv[])
{
    if (argc < 4)
    {
        cout << "Usage: " << argv[0] << " update <task id> <new description>" << endl;
        return 1;
    }
    string task_id = argv[2];
    string new_description = argv[3];
    UpdateDescription(tasks, task_id, new_description);
    overwriteTasksinJson(tasks);
    return 0;
}

int TaskTracker::delete_task(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " delete <task id>" << endl;
        return 1;
    }
    string task_id = argv[2];
    DeleteTask(tasks, task_id);
    overwriteTasksinJson(tasks);
    return 0;
}


int TaskTracker::update_status(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " mark-<NewStatus> <task id>" << endl;
        return 1;
    }
    string full_command = argv[1];
    size_t pos = full_command.find('-');
    if (pos == string::npos)
    {
        cout << "Invalid command. Expected: mark-<NewStatus>" << endl;
        return 1;
    }
    string new_status = full_command.substr(pos + 1);
    string task_id = argv[2];
    UpdateStatus(tasks, new_status, task_id);
    overwriteTasksinJson(tasks);
    return 0;
}

int TaskTracker::list_tasks(int argc, char* argv[])
{
    if (argc == 2)
    {
        printAllTaskInVector(tasks);
        return 0;
    }
    if (argc == 3 && (string(argv[2]) == "in-progress" || string(argv[2]) == "done" || string(argv[2]) == "todo"))
    {
        string status = argv[2];
        filterTasksByStatus(tasks, status);
        return 0;
    }
    else
    {
        cout << "Usage: " << argv[0] << " list [status]" << endl;
        cout << "Status can be: in-progress, done" << endl;
        return 1;
    }
}


int TaskTracker::help(int argc, char* argv[])
{
    cout << " Task Tracker CLI - Available Commands:" << endl;
    cout << "  add <description>             - Add a new task with the given description." << endl;
    cout << "  update <id> <new description> - Update the description of a task by its ID." << endl;
    cout << "  delete <id>                   - Delete a task by its ID." << endl;
    cout << "  mark-<status> <id>            - Update the status of a task (e.g., mark-in-progress, mark-done)." << endl;
    cout << "  list [status]                 - List all tasks or filter by status (in-progress, done)." << endl;
    cout << "  help                          - Show this help message." << endl;
    return 0;
}