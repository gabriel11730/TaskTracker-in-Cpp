#include <headers/Utilities.h>
#include <functional>
#include <unordered_map>
#include <main/task-tracker.h>

namespace TaskTracker
{
    int add_task(int, char**);
    int update_task(int, char**);
    int delete_task(int, char**);
    int mark_task_complete(int, char**);
    int list_all_tasks(int, char**);
    int list_done_tasks(int, char**);
    int list_todo_tasks(int, char**);
    int list_in_progress_tasks(int, char**);

    static unordered_map<string, function<int(int, char**)>> command_map = {
        {"add", add_task},
        {"update", update_task},
        {"delete", delete_task},
        {"mark-complete", mark_task_complete},
        {"list-all", list_all_tasks},
        {"list-done", list_done_tasks},
        {"list-todo", list_todo_tasks},
        {"list-in-progress", list_in_progress_tasks}
    };

}

int TaskTracker::handle_command(int argc, char* argv[]){
    if (argc < 2) {
        cout << "No command provided." << endl;
        cout << "Usage: " << argv[0] << " help " << endl;
        return 1;
    }
    const string command = argv[1];
    auto it = command_map.find(command);
    if (it != command_map.end()) {
        return it->second(argc, argv);
    } else {
        cout << "Unknown command: " << command << endl;
        cout << "Usage: " << argv[0] << " help " << endl;
        return 1;
    }
}