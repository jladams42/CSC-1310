
/*****************************************************************
	Title:  	LinkedList.h 
	Date:  		09-24-2024
	Author: 	Amani Altarawneh
	Purpose:	A Singly-Linked List implemented in a
				LinkedList class that contains operation functions
******************************************************************/


/*****************************************************************
							Node Class
******************************************************************/

template <class T>
class Node {
public:
    T element;           // element stored in the node
    Node* next;       // Pointer to the next node in the list

    // Constructor
    Node(const T& e = T(), Node *n = NULL) : element(e), next(n) {}  // Initialize element and next pointer
};
/*****************************************************************
							List Class
******************************************************************/


template <class T>
class List {

private:
    Node<T>* dummyHead;  // Sentinel (dummy) head node

public:
    
    List();// Constructor to initialize the dummyhead  
    List(const List& rhs); // Copy Constructor
    ~List(); // Destructor to clean up memory
    Node<T>* zeroth(); // Returns the dummy head node (zeroth node)
    Node<T>* first(); // Returns the first node in the list
    const Node<T>* first() const; // Const version of first() function (for const objects)    
    bool isEmpty() const; // Checks if the list is empty
    void insert(const T& data, Node<T>* p);
    Node<T>* find(const T& data); //  find an element, we must loop through all elements until we find the element or we reach the end
    Node<T>* findPrevious(const T& data);
   void remove(const T& data);
   void print() const; 
   void makeEmpty();
   List& operator=(const List& rhs);
}; 
