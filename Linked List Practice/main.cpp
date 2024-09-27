/*****************************************************************
	Title:  	main.cpp - Class Specification File for 
				both the ListNode Class and LinkedList Class
	Date:  		09-24-2024
	Author: 	Amani Altarawneh
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains operation functions
******************************************************************/

/*****************************************************************
							Main Function
******************************************************************/


#include<iostream>
#include "LinkedList-Operations.h"

int main() {
    List<int> myList;
    int x = 0;

    std::cout << std::endl<<"*********************************************"<< std::endl;
    std::cout << "Start the linkedlist operations: "<< std::endl;
    std::cout << std::endl<<"*********************************************"<< std::endl;
    // Check if the list is empty
    if (myList.isEmpty()) {
        std::cout << "List is empty." << std::endl;
    }
    std::cout << std::endl<< "*********************************************"<< std::endl;

    // Insert and manipulate list nodes as needed
    myList.insert(0, myList.zeroth());
    Node<int>* p = myList.first();

    for (int i = 1; i <= 10; ++i)
    {
        myList.insert(i, p);
        p = p->next;
    }
    // Print the list   
    std::cout << "printing original list" << std::endl;
    myList.print();

std::cout << std::endl<< "*********************************************"<< std::endl;

    for (int i = 0; i <= 10; ++i){
        if (i % 2 == 0)
         myList.remove(i);
    }

std::cout << std::endl<< "printing odd number list" << std::endl; myList.print();

std::cout << std::endl<< "*********************************************"<< std::endl;


List<int> list2 = myList;
cout << "printing copy constructed list" << endl;
list2.print();

std::cout << std::endl<< "*********************************************"<< std::endl;
List<int> list3;
list3 = myList;
cout << "printing assigned list" << endl;
list3.print();

std::cout << std::endl<< "*********************************************"<< std::endl;
myList.makeEmpty();
cout << std::endl << "printing emptied list" << endl;

myList.print(); cout<<std::endl;

for (int i = 0; i <= 10; ++i) {
  if (i % 2 == 0) {
    if (list2.find(i) == NULL)
      cout << "could not find element " << i << endl;
  }
  else {
    if (list2.find(i) != NULL)
      cout << "found element " << i << endl;
  }
}
list2.print(); cout<<std::endl;
myList.print(); cout<<std::endl;

std::cout << std::endl<< "*********************************************"<< std::endl;
    return 0;
}
