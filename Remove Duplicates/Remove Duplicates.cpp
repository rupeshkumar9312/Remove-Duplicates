// Remove Duplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node * head;
public:

	LinkedList(){}
	~LinkedList(){}

	void push(int value);
	void traverseList();
	void remove(int value);
};

void LinkedList::push(int value)
{
	Node* new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;
}

void LinkedList::remove(int value)
{
	Node* current = head;
	Node* previous = NULL;
	int count = 0;
	while (current != NULL)
	{
		//current = current->next;
		if (current != NULL && current->data == value)
		{
			count++;
		}
		if (count > 1 && current->data == value)
		{

			previous->next = current->next->next;
			current = previous->next;
			continue;
		}
		previous = current;
		current = current->next;
		cout << "count " << count << endl;
	}
}
void LinkedList::traverseList()
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << "-->" << endl;
		current = current->next;
	}
	return;
}
int main()
{
	LinkedList list;
	list.push(10);
	list.push(20);
	list.push(10);
	//list.push(30);
	list.push(30);
	list.push(30);
	list.push(40);
	list.traverseList();
	cout << "-----" << endl;
	list.remove(30);
	list.traverseList();
	
    return 0;
}

