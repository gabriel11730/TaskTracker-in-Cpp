/* Task Tracker in Roadmap.sh */
#include <main/task-tracker.h>
#include <headers/Utilities.h>
#include <headers/ManageTasks.h>


int main(int argc, char* argv[]) {
    return TaskTracker::handle_command(argc, argv);
}
