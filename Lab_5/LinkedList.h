/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   [TODAY's DATE]
	Author:         [YOU]
	Purpose:        LAB 5 - A Singly-Linked List implemented in a
				    LinkedList template class that contains a ListNode
				    structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;


template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			//STRUCTURE MEMBERS NEED TO BE ADDED HERE
			T value;
			ListNode *next;
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~LinkedList();
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------
template <typename T>
LinkedList<T>::~LinkedList() {
	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		ListNode *temp = nodePtr;
		cout << "*****DELETING the node with address: " << temp << endl;
		nodePtr = nodePtr->next;
		delete temp;
	}
}

template <typename T>
void LinkedList<T>::appendNode(T value) {
	ListNode *newNode = new ListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else{
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::deleteNode( int position) {
	if (head == nullptr) {
		cout << "The list is empty, nothing to delete." << endl;
		return;
	}

	if (position == 0) {
		ListNode *temp = head;
		cout << "-----DELETING the node with address: " << temp << endl;
		head = head->next;
		delete temp;
		if (head == nullptr) tail = nullptr;
	} else {
		ListNode *nodePtr = head;
		ListNode *previous = nullptr;
		int currentIndex = 0;

		while (nodePtr != nullptr && currentIndex < position) {
			previous = nodePtr;
			nodePtr = nodePtr->next;
			currentIndex++;
		}

		if (nodePtr == nullptr) {
			cout << "No node found at position " << position << "." << endl;
		} else {
			cout << "-----DELETING the node with address: " << nodePtr << endl;
			previous->next = nodePtr->next;
			if (nodePtr == tail) tail =  previous;
			delete nodePtr;
		}

	}
}

template <typename T>
void LinkedList<T>::displayList() const {
	if (head == nullptr) {
		cout << "There are no nodes in the list." << endl;
	} else {
		ListNode *nodePtr = head;
		while (nodePtr != nullptr) {
			cout << nodePtr->value << endl;
			nodePtr = nodePtr -> next;
		}
	}
}

#endif