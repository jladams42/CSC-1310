
/*****************************************************************
	Title:  	ListFuncs.h 
	Date:  		09-24-2024
	Author: 	Amani Altarawneh
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains operation functions
******************************************************************/
/*****************************************************************
							List Class Functions
******************************************************************/

#include "LinkedList.h"
#include<iostream>

using namespace std;

 // Constructor to initialize the dummy head
    template <class T>
    List<T>::List() : 
    dummyHead(new Node<T>(T())) {}  // Assumes Node constructor accepts default value for T
  
//Copy Constructor
    template <class T>
    List<T>::List(const List& rhs){
    dummyHead = new Node<T>(T(), NULL);
    *this = rhs; // use operator=
}
 
// Destructor to clean up memory
   template <class T>
   List<T>::~List() {
        while (!isEmpty()) {
            Node<T>* tmp = first();
            dummyHead->next = tmp->next;
            delete tmp;
        }
        delete dummyHead;
    }
// // Destructor to clean up memory
//     template <class T>
//     List<T>::~List(){
//     makeEmpty();
//      delete dummyHead;
//   }

    
// Returns the dummy head node (zeroth node)
   template <class T>
    Node<T>* List<T>::zeroth() {
        return dummyHead;
    }
// Returns the first node in the list
    template <class T>
    Node<T>* List<T>::first() {
        return dummyHead->next;
    }

// Const version of first() function (for const objects)
    template <class T>
    const Node<T>* List<T>::first() const {
        return dummyHead->next;
    }

// Checks if the list is empty
    template <class T>
    bool List<T>::isEmpty() const {
        return first() == NULL;  // If first() is NULL, the list is empty
}

// insertion function, insert a node anywhere in the list 
    template <class T>
    void List<T>::insert(const T& data, Node<T>* p) {
    // now p should not be NULL. To insert to the
    // first position, it should point to dummy head
    Node<T>* newNode = new Node<T>(data, p->next);
    p->next = newNode;
}

//  Find a node
    template <class T>
    Node<T>* List<T>::find(const T& data) {
    Node<T>* p = first();
    while (p) {
    if (p->element == data)
      return p;
    p = p->next;
    }
    return NULL;
}
//Find previous node
    template <class T>
    Node<T>* List<T>::findPrevious(const T& data) {
     Node<T>* p = zeroth();

     while (p->next) {
       if (p->next->element == data)
         return p;
       p = p->next;
      }
      return NULL;
}
// Remove node
template <class T>
    void List<T>::remove(const T& data) {
     Node<T>* p = findPrevious(data);

     if (p) {
      Node<T>* tmp = p->next;
      p->next = tmp->next;
       delete tmp;
     }
}

// print all elements 
template <class T>
void List<T>::print() const {
  const Node<T>* p = first();

  while(p) {
    cout << p->element <<" |";
    p = p->next;
  }
}
//make empty list using the functions: isempty(), remove(), and first()
template <class T>
void List<T>::makeEmpty() {
  Node<T>* p= first();  // Assuming first() returns a Node pointer
    while (p != nullptr) {
        remove(p->element);  // Correct usage
        p = p->next;  // Move to the next node
    }
}
// Assining function =
template <class T>
List<T>& List<T>::operator=(const List& rhs) {
  if (this != &rhs) {
    makeEmpty();
    const Node<T>* r = rhs.first();
    Node<T>* p = zeroth();
    
    while (r) {
       insert(r->element, p);
       r = r->next;
       p = p->next;
    }
  }
  return *this;
  }


