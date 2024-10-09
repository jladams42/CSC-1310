#include <iostream>
#include "List.h"

using namespace std;

int main() {
    LinkedList list;

    // Does all the appending, inserting and printing of the methods for the LinkedList class
    cout << "The linked list has been created.\n";
    cout << "\nI am appending several strings to the list.\n";\
    list.appendNode("boogeyman");
    list.appendNode("ghost");
    list.appendNode("scarecrow");
    list.appendNode("witch");
    list.appendNode("zombie");
    list.displayList();

    cout << "\nI am inserting vampire in the list.\n";
    list.insertNode("vampire");
    list.displayList();

    
    cout << "\nI am deleting ghost from the list.\n";
    list.deleteNode("ghost");
    list.displayList();
    

    return 0;
}