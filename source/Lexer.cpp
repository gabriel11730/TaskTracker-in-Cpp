#include <headers/Lexer.h>

Task MapOfTask;

string extractValue(string cadena, int posicion){
    string StringValue = "";
    int pos = posicion;

    while (pos < cadena.size())
    {
        char letter = cadena[pos];
        if (letter == '"')
        {
            if (StringValue == "id")
            {
                MapOfTask.id = extractValue(cadena,pos+3);
            }
            else if (StringValue == "status")
            {
                MapOfTask.status = extractValue(cadena,pos+3);
            }
            else if (StringValue == "description")
            {
                MapOfTask.description = extractValue(cadena,pos+3);
            }
            else if (StringValue == "createdAt")
            {
                MapOfTask.createdAt = extractValue(cadena,pos+3);
            }
            else if (StringValue == "updatedAt")
            {
                MapOfTask.updatedAt = extractValue(cadena,pos+3);
            }
            else
            {
                return StringValue;
            }
        }
        if (letter == '\\')
        {
            pos++;
            if (pos < cadena.size()) 
            {
                StringValue += cadena[pos];
            }
        }
        else
        {
            StringValue += letter;
        }
        pos++;
        
    }
    
    return StringValue;
}

bool searchValue(string cadena){
    int pos = 0;
    for (char letter : cadena)
    {
        if (letter == '}')
        {
            return true;
        }
        if (letter == '"'){
            pos++;
            extractValue(cadena,pos);
            return false;
        }
        pos++;
    }
    return false;
}

Task GetTask(){
    return MapOfTask;
}