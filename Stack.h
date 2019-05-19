#ifndef LAB1_LIST_STACK
#define LAB1_LIST_STACK
#include "List.h"


// Global variable aviable throughout the program
int itemCountStack = 0;


template <class T>
class TreeNode<T> {
public:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};


template <class T>
class Stack : public TreeNode<T> {

private:
	Node<T> *top;
	Node<T> *head;
	T value;


public:
	Stack();
	void clear();
	bool add(T newEntry);
	bool remove(T anEntry);
	bool isEmpty();
	bool search(T anEntry);
	bool displayList();

};


template <class T>
Stack<T>::Stack() {
	top = nullptr;
}

// Clear is the Destructor
template <class T>
void Stack<T>::clear() {
	Node<T> *nodePtr = head;
	Node<T> *n;
	while (nodePtr) {
		n = nodePtr->prev;
		delete nodePtr; // delete Dynamic memory
		nodePtr = n;
		itemCountStack--;
	}
	head = nullptr; // point head to null 
	cout << "List has been cleared!" << endl;
}


// Using virtual functions from standard interface
// Function will act like the push function
template <class T>
bool Stack<T>::add(T newEntry) {
	Node<T> *newNode = new Node<T>;
	newNode->item = newEntry;
	
	if (isEmpty() == true) {
		top = newNode;
		newNode->next = nullptr;
		itemCountStack++;
	}
	else {
		newNode->next = top;
		top = newNode;
		itemCountStack++;
	}
	return true;
}

// Using virtual functions from standard interface
// This function acts like pop function
template <class T>
bool Stack<T>::remove(T anEntry) {
	if (isEmpty() == true) {
		cout << "The list is empty!" << endl;
		return false;
	}
	else {
		if (isEmpty() == false) {
			Node<T> *rover = top;
			Node<T> *nodePtr = rover->next;
			while (nodePtr != NULL) { // Rover goes until it hits the end of the list
				if (nodePtr->item == anEntry) {
					itemCountStack--;
					rover->next = nodePtr->next;
					delete nodePtr;
					return true;
				}
				else nodePtr = nodePtr->next; // Setting rover to the previous
			}
			return false;
		}
	}
	cout << "Error #1 has Occured: Remove function" << endl;
	return false;
}

template <class T>
bool Stack<T>::isEmpty() {
	if (!top) 
		return true;
	else  return false;
}

// Using virtual functions from standard interface
// Function not in the standard interface
template <class T>
bool Stack<T>::search(T anEntry) {
	// Rover will go through the list one by one
	Node<T> *rover = top;
	while (rover != NULL) { // Rover goes until it hits the end of the list
		if (rover->item == anEntry)
			return true;
		// Setting rover to the previous
		else rover = rover->next;
	}

	return false;
}


// Using code from book form of Pop
template <class T>
bool Stack<T>::displayList() {
	// Rover will go through the list one by one
	Node<T> *rover = top;
	if (isEmpty() == true) {
		return false;
	}
	else {
		while (rover) // Rover goes until it hits the end of the list
		{
			cout << rover->item << endl;
			rover = rover->next;
			// delete top;
			// top = rover;
			// No deletion here since wanted to be handled by clear or remove function
		}
		return true;
	}
}


#endif