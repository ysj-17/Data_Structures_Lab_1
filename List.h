#ifndef LAB1_LIST
#define LAB1_LIST

template <class T>
class Node
{
public:
	T  item;
	Node *prev;
	Node *next;
	Node *head;
	Node *tail;
};

// Generic Class List - Barely used
// Had problems establishing Class hierarchy 
template <class T> class ListInterface : public Node<T>
{
public:

	virtual bool isEmpty() { return true; };
	virtual bool add(T newEntry) { return true; };
	virtual bool remove(T anEntry) { return true; };
	virtual void clear() { cout << "Error in ListInterface Class"; };
	virtual bool search(T anEntry) { return true; };
	virtual bool displayList() { return true; };
};

// Global variable aviable throughout the program
 int itemCountList = 0;


template <class T> class List : public ListInterface<T>
{
private:
	using Node<T>::head;
	using Node<T>::tail;
	// Using variable from base class
//	Node<T> * head;
//	int itemCount = 0;

public:
	List() { head = nullptr; }

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else { return false; }
	}


	bool add(T newEntry) {
		Node<T> *newNode = new Node<T>;
		newNode->item = newEntry;
		newNode->head = NULL;
		newNode->tail = NULL;

		if (isEmpty() == true) {
			head = newNode;
			tail = newNode;
			itemCountList++;
		}
		else {
			newNode->prev = head->prev;
			head->prev = newNode;
			newNode->next = head;
			itemCountList++;
		}

		return true;
	}

	bool remove(T anEntry) {
		if (isEmpty() == true) {
			cout << "The list is empty!" << endl;
			return false;
		}
		else {
			if (isEmpty() == false) {
				Node<T> *rover = head;
				Node<T> *nodePtr = rover->prev;
				while (nodePtr != NULL) { // Rover goes until it hits the end of the list
					if (nodePtr->item == anEntry) {
						rover->prev = nodePtr->prev;
						delete nodePtr;
						itemCountList--;
						return true;
					}
					else nodePtr = nodePtr->prev; // Setting rover to the previous
				}
				return false;
			}
		}
		cout << "Error #1 has Occured: Remove function" << endl;
		return false;
	}

	void clear() {
		Node<T> *nodePtr = head;
		Node<T> *n;
		while (nodePtr) {
			n = nodePtr->prev;
			delete nodePtr; // delete Dynamic memory
			nodePtr = n;
			itemCountList--;
		}
		head = nullptr; // point head to null 
		cout << "List has been cleared!" << endl;
	}



	bool search(T anEntry) {
		// Rover will go through the list one by one
		Node<T> *rover = head;
		while (rover != NULL) { // Rover goes until it hits the end of the list
			if (rover->item == anEntry)
				return true;
			// Setting rover to the previous
			else rover = rover->prev;
		}

		return false;
	}


	bool displayList()
	{
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
				rover = rover->prev;
			}
			return true;
		}
	}

};





#endif