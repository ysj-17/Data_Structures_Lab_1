#ifndef LAB1_LIST_QUEUE
#define LAB1_LIST_QUEUE
#include "List.h"

// Global variable aviable throughout the program
int itemCountQueue = 0;


template <class T>
class Queue : public List<T> {
private:
	using Node<T>::head; // Head is the FRONT
	using Node<T>::tail; // Tail is the END
	T value;
//	int itemCount = 0;

public:
	Queue();
	void clear();
	bool add(T newEntry);
	bool remove(T anEntry);
	bool isEmpty();
	bool search(T anEntry);
	bool displayList();
	//int count();
};

template <class T>
Queue<T>::Queue() {
	head = nullptr;
	tail = nullptr;
}

// Clear is the Destructor
template <class T>
void Queue<T>::clear() {
	Node<T> *nodePtr = head;
	Node<T> *n;
	while (nodePtr) {
		n = nodePtr->next;
		delete nodePtr; // delete Dynamic memory
		nodePtr = n;
		itemCountQueue--;
	}
	head = nullptr; // point head to null 
	cout << "List has been cleared!" << endl;
}


// Add is Push interface
// Using virtual functions from standard interface
template <class T>
bool Queue<T>::add(T newEntry) {
	Node<T> *newNode = new Node<T>;
	Node<T> *nodePtr = head;
	newNode->item = newEntry;
	newNode->head = NULL;
	newNode->tail = NULL;

	if (isEmpty() == true) {
		head = newNode;
		tail = newNode;
		itemCountQueue++;
	}
	else {

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		newNode->tail = tail;
		itemCountQueue++;
	}
	return true;
}

// Remove is something like Pop interface
// Using virtual functions from standard interface
template <class T>
bool Queue<T>::remove(T anEntry) {
	if (isEmpty() == true) {
		cout << "The list is empty!" << endl;
		return false;
	}
	else {
		if (isEmpty() == false) {
			Node<T> *rover = head;
			Node<T> *nodePtr = rover->next;
			while (nodePtr != NULL) { // Rover goes until it hits the end of the list
				if (nodePtr->item == anEntry) {
					rover->next = nodePtr->next;
					itemCountQueue--;
					delete nodePtr;
					return true;
				}
				else nodePtr = nodePtr->next; // Setting rover to the next
			}
		}
	}
	cout << "Error #1 has Occured: Remove function" << endl;
	return false;
}

// Using virtual functions from standard interface
template <class T>
bool Queue<T>::isEmpty() {
	if (head == NULL) {
		return true;
	}
	else { return false; }
}


// Using virtual functions from standard interface
template <class T>
bool Queue<T>::search(T anEntry) {
	// Rover will go through the list one by one
	Node<T> *rover = head;
	while (rover != NULL) { // Rover goes until it hits the end of the list
		if (rover->item == anEntry)
			return true;
		// Setting rover to the previous
		else rover = rover->next;
	}

	return false;
}

// Using virtual functions from standard interface
template <class T>
bool Queue<T>::displayList() {
	// Rover will go through the list one by one
	Node<T> *rover;
	rover = head;
	if (isEmpty() == true) {
		return false;
	}
	else {
		while (rover) // Rover goes until it hits the end of the list
		{
			cout << rover->item << endl;
			// Setting rover to the previous
			rover = rover->next;
		}
		return true;
	}
}



#endif