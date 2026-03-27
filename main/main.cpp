/* Task Tracker in Roadmap.sh */
#include <main/task-tracker.h>
#include <headers/Utilities.h>
#include <headers/ManageTasks.h>


int main(int argc, char* argv[]) {
    
    return TaskTracker::handle_command(argc, argv);
}










// //cout << "Welcome to Task Tracker!" << endl;
// // Estoy practicando, antes de pasar a la logica del programa.

// cout << "[" << argc << "]" << endl;

// for (int i = 0; i < argc ; i++)
// {
//     cout << "Argument " << i << ": " << argv[i] << endl;
// }




/*
    int opcion = 0;
    // Deberia mapear el json a un vector de tareas al iniciar el programa?
    InitialMappingJsontoVector();
    do
    {
        cout<< "#------Task tracker CLI------#"<<endl;
        cout<< "#----------------------------#"<<endl;
        cout<< "1. Add, Update or Delete Task" << endl;
        cout<< "2. Mark task as Complete" << endl;
        cout<< "3. See Tasks" << endl;
        cout<< "4. Exit"<< endl;
        cin>> opcion;
        if (opcion == 1)
        {
            MenuManagetask();
        }
        if (opcion == 2)
        {
            MarkTaskComplete();
        }
        if (opcion == 3)
        {
            MenuSeeTasks();
        }
        if (opcion == 4)
        {
            cout<< "Adios" << endl;
        }
        clearConsole();

    } while (opcion != 4);
    
*/