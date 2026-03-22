#include <headers/ManageTasks.h>

vector<Task> tasks;

void MenuManagetask(){
    int opcion;
    do
    {
    cout<<"Elige: "<<endl;
    cout<<"1. Agregar tarea"<<endl;
    cout<<"2. Modificar tarea"<<endl;
    cout<<"3. Borrar tarea"<<endl;
    cin>>opcion;
    if (opcion == 1)
    {
        AddTask();
    }
    if (opcion == 2)
    {
        ModifyTask();
    }
    if (opcion == 3)
    {
        DeleteTask();
    }
    if (opcion == 4)
    {
        cout<< "Adios" << endl;
    }
    else
    {
        cout<< "Opcion no valida, intente de nuevo" << endl;
    }
    } while (opcion != 4);
    
}

void AddTask(){
    // Funcion relacionada
}

void ModifyTask(){
    // Funcion relacionada
}

void DeleteTask(){
    // Funcion relacionada
}

void MarkTaskComplete(){
    // Funcion relacionada
}

void MenuSeeTasks(){
    int opcion;
    do
    {
    cout<<"Elige: "<<endl;
    cout<<"1. Ver tareas completas"<<endl;
    cout<<"2. Ver tareas incompletas"<<endl;
    cout<<"3. Ver todas las tareas"<<endl;
    cout<<"4. Volver al menu principal"<<endl;
    cin>>opcion;
    if (opcion == 1)
    {
        // Funcion relacionada
    }
    else if (opcion == 2)
    {
        
        // Funcion relacionada
    }
    else if (opcion == 3)
    {
        // Funcion relacionada
        string jsonText;
        ifstream archivo_tarea("..\\task\\task1.json");
        if (archivo_tarea.is_open())
        {
            while (getline(archivo_tarea, jsonText))
            {
                searchValue(jsonText);
                //cout << jsonText << endl;
            }
            // Puedo acceder a mi Struct MapOfTask desde aqui?

            // esto cambiara por una funcion que pregunte si el MapOfTask ya esta lleno
            addTaskToVector(GetTask());
            archivo_tarea.close();
        }
    
    }
    else if (opcion == 4 )
    {
        cout<< "Adios" << endl;
    }
    else
    {
        cout<< "Opcion no valida, intente de nuevo" << endl;
    }
    } while (opcion != 4);
    
}

void addTaskToVector(Task task){
    tasks.emplace_back(task);
};