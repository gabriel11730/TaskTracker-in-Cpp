#include <headers/ManageTasks.h>

vector<Task> tasks; // Vector Global, luego se usare mejores practicas

void InitialMappingJsontoVector(){
    string jsonText;
    ifstream archivo_tarea("tasks.json");
    if (archivo_tarea.is_open())
    {
        while (getline(archivo_tarea, jsonText))
        {
            if (searchValue(jsonText))
            {
                addTaskToVector(GetTask());
            }
        }
        
        archivo_tarea.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo Json!." << endl;
    }
}

void MenuManagetask(){
    int opcion;
    do
    {
    cout<<"Elige: "<<endl;
    cout<<"1. Agregar tarea"<<endl;
    cout<<"2. Modificar tarea"<<endl;
    cout<<"3. Borrar tarea"<<endl;
    cout<<"4. Volver al menu principal"<<endl;
    cin>>opcion;
    if (opcion == 1)
    {
        AddTask();
    }
    else if (opcion == 2)
    {
        ModifyTask();
    }
    else if (opcion == 3)
    {
        DeleteTask();
    }
    else if (opcion == 4)
    {
        cout<< "Adios" << endl;
    }
    else
    {
        cout<< "Opcion no valida, intente de nuevo" << endl;
    }
    overwriteTasksinJson(tasks);
    } while (opcion != 4);
    
}
// Cual es la responsabilidad de AddTask?
// 
void AddTask(){
    Task newTask;

    if (tasks.empty())
    {
        newTask.id = "1";
    }
    else
    {
        Task lastTask = tasks.back();
        int newLastId = stoi(lastTask.id) + 1;
        newTask.id = to_string(newLastId);
    }

    string taskDescription;
    cout << "Ingrese la descripcion de la tarea: " << endl;
    cin.ignore();
    getline(cin, taskDescription);
    newTask.description = taskDescription;
    newTask.status = "todo";
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    newTask.createdAt = 
    to_string(ahora->tm_mday) +  "/" +
    to_string(ahora->tm_mon + 1) + "/" + 
    to_string(ahora->tm_year + 1900);
    newTask.updatedAt = newTask.createdAt;

    tasks.emplace_back(newTask);
}

void ModifyTask(){
    if (tasks.empty())
    {
        cout<< "No hay tareas guardadas" << endl;
    }
    else
    {
        string id;
        cout<< "Ingrese ID de la tarea que desea modificar: "<< endl;
        cin>> id;
        for (auto &task : tasks)
        {
            if (task.id == id)
            {
                int opcion;
                cout<<"Que valor desea modificar?"<<endl;
                cout<<"1. Descripcion"<<endl;
                cout<<"2. Status"<<endl;
                cout<<"3. Regresar, No modificar nada"<<endl;
                cin>> opcion;
                if (opcion == 1)
                {
                    string newDescription;
                    cout<< "Ingrese la nueva descripcion: "<< endl;
                    cin.ignore();
                    getline(cin, newDescription);
                    task.description = newDescription;
                    auto it = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {
                        return t.id == task.id; // Comparación personalizada "al vuelo"
                    });

                    if (it != tasks.end()) {
                        RefreshUpdateAtField(std::distance(tasks.begin(), it));
                    }
                }
                else if (opcion == 2)
                {
                    string newStatus;
                    cout<< "Ingrese el nuevo status (todo, in-progress, done): "<< endl;
                    cin>> newStatus;
                    if (newStatus == "todo" || newStatus == "in-progress" || newStatus == "done")
                    {
                        task.status = newStatus;
                        auto it = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {
                            return t.id == task.id;
                        });
                        if (it != tasks.end()) 
                        {
                            RefreshUpdateAtField(std::distance(tasks.begin(), it));
                        }
                    }
                    else
                    {
                        cout<< "Status no valido, intente de nuevo" << endl;
                    }
                }
                else if (opcion == 3)
                {
                    cout<< "No se modifico nada" << endl;
                }
                else
                {
                    cout<< "Opcion no valida, intente de nuevo" << endl;
                }
            }
        }
    }
}

void DeleteTask(){
    if (tasks.empty())
    {
        cout<< "No hay tareas para eliminar." << endl;
    }
    else
    {
        string id;
        cout<< "Ingrese el ID de la tarea que desea eliminar: ";
        cin>> id;
        auto it = remove_if(tasks.begin(), tasks.end(), [&id](const Task& task) {
            return task.id == id;
        });
        if (it != tasks.end())
        {
            tasks.erase(it, tasks.end());
            cout<< "Tarea eliminada." << endl;
        }
        else
        {
            cout<< "No se encontró una tarea con ese ID." << endl;
        }
    }
}

void MarkTaskComplete(){
    if (tasks.empty())
    {
        cout<< "No hay tareas para marcar como completas." << endl;
    }
    else
    {
        string id;
        cout<< "Ingrese el ID de la tarea que desea marcar como completa: ";
        cin>> id;
        bool found = false;
        for (auto& task : tasks)
        {
            if (task.id == id)
            {
                task.status = "done";
                cout<< "Tarea marcada como completa." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout<< "No se encontró una tarea con ese ID." << endl;
        }
    }
}

void RefreshUpdateAtField(int index)
{
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    if (index >= 0 && index < tasks.size())
    {
        tasks[index].updatedAt = 
        to_string(ahora->tm_mday) +  "/" +
        to_string(ahora->tm_mon + 1) + "/" + 
        to_string(ahora->tm_year + 1900);
    }
    else
    {
        cout<< "Indice invalido" << endl;
    }
}

void MenuSeeTasks(){
    int opcion;
    do
    {
    cout<<"Elige: "<<endl;
    cout<<"1. Ver tareas completas"<<endl;
    cout<<"2. Ver tareas incompletas"<<endl;
    cout<<"3. Ver tareas en progreso"<<endl;
    cout<<"4. Ver todas las tareas"<<endl;
    cout<<"5. Volver al menu principal"<<endl;
    cin>>opcion;
    if (opcion == 1)
    {
        filterTasksByStatus("done");
    }
    else if (opcion == 2)
    {
        filterTasksByStatus("todo");
    }
    else if (opcion == 3)
    {
        filterTasksByStatus("in-progress");
    }
    else if (opcion == 4)
    {
        printAllTaskInVector();
    }
    else if (opcion == 5)
    {
        cout<< "Adios" << endl;
    }
    else
    {
        cout<< "Opcion no valida, intente de nuevo" << endl;
    }
    //clearConsole();
    } while (opcion != 5);
    
}

void filterTasksByStatus(const string& status)
{
    if (tasks.empty()) {
        cout << "No hay tareas para mostrar." << endl;
    } else {
        cout << "Tareas "<< status << ":" << endl;
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

void printAllTaskInVector(){
    cout << "Tareas en el vector:" << endl;
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

void addTaskToVector(Task task){
    tasks.emplace_back(task);
};

void overwriteTasksinJson(const std::vector<Task>& tasks) {
    ofstream archivo("tasks.json");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
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