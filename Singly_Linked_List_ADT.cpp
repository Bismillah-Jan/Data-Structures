/*
Author: Bismillah Jan
Description: This program implements a singly linked list
data structure with two functions which can insert elements
at the start as well as at the end. It also prints the elements
in the list via a function call printList.
*/
#include <iostream>
#include <string>
#include "Singly_Linked_List.h"
using namespace std;

int main()
{

	LinkedList<int> myList;
	myList.insertAtStart(10);
	myList.insertAtStart(2);
	myList.insertAtStart(1);
	myList.insertAtStart(3);
	myList.insertAtStart(1);
	myList.insertAtStart(1);
	myList.printList();
	//cout<<myList.search(0)<<endl;
	//myList.deleteAkey(1);
	//myList.deleteAllOccurences(10);
	myList.insertBefore(100, 1);
	
	myList.printList();


	//myList.destroyList(); //This function is already called in the
	//destructor.No need to call it explicitly.
}
