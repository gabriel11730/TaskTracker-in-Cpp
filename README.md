# TaskTracker-in-Cpp
Training how handle files .json in c++ through a TaskTracker

## Idea Principal

- No codificare un Lexer ni un Parser Genericos, los hare a la medida del ejercicio.  
- Uso Programacion Funcional, he evitado deliberadamente la POO.
- Un ``struct`` es usado para mapear los pares de cada tarea, usando una sintaxis predefinida, omitiendo el tratamiento de edge-cases (Casos limites o casos fuera de lo esperado)
- Uso un ``vector <Task>`` para guardar cada tarea individualmente

## Pendientes

- Algun metodo para llenar el vector una sola vez y poder consultarlo con confianza luego, sin sobreescribirlo si no es necesario.

## Pensamientos

puedo crear una funcion en ``ManageTask.cpp`` que pida el ``struct`` y de algun modo enviar el ``struct`` como argumento en una funcion desde ``Lexer.cpp`` hacia ``ManageTask.cpp``