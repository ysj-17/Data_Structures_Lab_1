// Program Name: Lab1
//
// Description:  
//  Implement double-linked list and then use
//  virtual functions to implement a Stack and Queue
//  using the stanfard interface.
//
// What's on your mind about this lab?
//  I was not too sure if I had to just use one standard interface,
//  but I did my best to create overloaded virtual functions to represent
//  the actual interface for each type (List, Stack, and Queue)
//
// Author: Jason Yoon
//
// Date: 7/11/2018
//
// IDE Used: Visual Microsoft
//

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

// Function to handle printing for Linked List
template <class T>
void methodsFileList(List<T> &object);

// Function to handle printing for Stack
template <class T>
void methodsFileStack(Stack<T> &object);

// Function to handle printing for Queue
template <class T>
void methodsFileQueue(Queue<T> &object);

int main () {
	
	int option;

	List<string> object;
	Stack<string> stackObj;
	Queue<string> queueObj;

	cout << "Please indicate which process to use." << endl
		<< "1. Double Linked List  2. Stack  3. Queue" << endl;
	cin >> option;
	
	switch (option) {
		case 1:			methodsFileList(object);
			break;
		case 2:			methodsFileStack(stackObj);
			break;
		case 3:			methodsFileQueue(queueObj);
			break;
	}


	 cin.get();
	return 0;
}
/*---------------------------------------------------------------
// Function to handle printing for Linked List
----------------------------------------------------------------*/
template <class T>
void methodsFileList(List<T> &object) {
	string input;
	string FILE_NAME = "Words.txt";
	fstream stream(FILE_NAME, ios::in);

	if (!stream) {
		cout << "Error #2: Error opening file. Program aborting." << endl;
		return; // Exits main if read wrong
	}

	while (getline(stream, input)) { // Reading the txt file line by line
		if (object.add(input) == false) {
			cout << "Error #3: Error occured in reading the file." << endl;
			break;
		}
	}

	// If display function needs to be used
	object.displayList();
	cout << endl << "List has been displayed" << endl;
	cout << "Number of nodes: " << itemCountList << endl;

	// If the "isEmpty" function needs to be used 
	if (object.isEmpty() == false) {
		cout << "Linked list has been instantiated and is not empty." << endl
			<< "The count of nodes is " << itemCountList << endl;
	}
	else cout << "Linked list is empty." << endl;


	// If the search function needs to be used
	cout << "Will now run the Search function for \"the\"" << endl;
	if (object.search("the")) {
		cout << "Found the entered value in the list." << endl;
	}
	else cout << "Value not in the list or list is empty." << endl;

	// If the "remove" function needs to be used 
	cout << "Will now run the Remove function for \"would\"" << endl;
	if (object.remove("would")) {
		cout << "Entry was removed from the list." << endl;
		cout << "Number of nodes now " << itemCountList << endl;
	}
	else cout << "Entry was not found in the list." << endl;

	// If clear function needs to be used
	object.clear();
	stream.close();
	
	 cin.get();
}

/*---------------------------------------------------------------
// Function to handle printing for Stack
----------------------------------------------------------------*/

template <class T>
void methodsFileStack(Stack<T> &object) {
	string input;
	string FILE_NAME = "Words.txt";
	fstream stream(FILE_NAME, ios::in);

	if (!stream) {
		cout << "Error #2: Error opening file. Program aborting." << endl;
		return ; // Exits main if read wrong
	}

	while (getline(stream, input)) { // Reading the txt file line by line
		if (object.add(input) == false) {
			cout << "Error #3: Error occured in reading the file." << endl;
			break;
		}
	}

	// If display function needs to be used
	object.displayList();
	cout << endl << "List has been displayed" << endl;
	cout << "Number of nodes: " << itemCountStack << endl;

	// If the "isEmpty" function needs to be used 
	if (object.isEmpty() == false) {
		cout << "Linked list has been instantiated and is not empty." << endl
			<< "The count of nodes is " << itemCountStack << endl;
	}
	else cout << "Linked list is empty." << endl;


	// If the search function needs to be used
	cout << "Will now run the Search function for \"the\"" << endl;
	if (object.search("the")) {
		cout << "Found the entered value in the list." << endl;
	}
	else cout << "Value not in the list or list is empty." << endl;

	// If the "remove" function needs to be used 
	cout << "Will now run the Remove function for \"would\"" << endl;
	if (object.remove("would")) {
		cout << "Entry was removed from the list." << endl;
		cout << "Number of nodes now " << itemCountStack << endl;
	}
	else cout << "Entry was not found in the list." << endl;

	// If clear function needs to be used
	object.clear();
	stream.close();

	 cin.get();
}


/*---------------------------------------------------------------
// Function to handle printing for Queue
----------------------------------------------------------------*/
template <class T>
void methodsFileQueue(Queue<T> &object) {
	string input;
	string FILE_NAME = "Words.txt";
	fstream stream(FILE_NAME, ios::in);

	if (!stream) {
		cout << "Error #2: Error opening file. Program aborting." << endl;
		return ; // Exits main if read wrong
	}

	while (getline(stream, input)) { // Reading the txt file line by line
		if (object.add(input) == false) {
			cout << "Error #3: Error occured in reading the file." << endl;
			break;
		}
	}

	// If display function needs to be used
	object.displayList();
	cout << endl << "List has been displayed" << endl;
	cout << "Number of nodes: " << itemCountQueue << endl;

	// If the "isEmpty" function needs to be used 
	if (object.isEmpty() == false) {
		cout << "Linked list has been instantiated and is not empty." << endl
			<< "The count of nodes is " << itemCountQueue << endl;
	}
	else cout << "Linked list is empty." << endl;


	// If the search function needs to be used
	cout << "Will now run the Search function for \"the\"" << endl;
	if (object.search("the")) {
		cout << "Found the entered value in the list." << endl;
	}
	else cout << "Value not in the list or list is empty." << endl;

	// If the "remove" function needs to be used 
	cout << "Will now run the Remove function for \"would\"" << endl;
	if (object.remove("would")) {
		cout << "Entry was removed from the list." << endl;
		cout << "Number of nodes now " << itemCountQueue << endl;
	}
	else cout << "Entry was not found in the list." << endl;

	// If clear function needs to be used
	object.clear();
	stream.close();

	// cin.get();
}
