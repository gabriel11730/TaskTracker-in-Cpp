
#include <headers/Utilities.h>


void clearConsole(){
    //cin.ignore(1000, '\n'); 
    //cin.get(); 
    cout << "\033[2J\033[1;1H";
}