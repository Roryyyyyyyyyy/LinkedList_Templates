#include "LinkedListNode.h"
#include <Vector>
#pragma once
template<typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(std::vector<T>);
	~LinkedList();

	void Append(T);
	void Push(T);
	void PrintList();
	void RemoveFromStart();
	void RemoveFromEnd();
	
private:
	LinkedListNode<T>* head;
};

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::LinkedList(std::vector<T> _array)
{
	for (int i = 0; i < _array.size(); i++)
	{
		this->Append(_array[i]);
	}
}


template <typename T>
LinkedList<T>::~LinkedList()
{
	LinkedListNode<T>* current = head;
	LinkedListNode<T>* next;
	while (current != NULL)
	{
		next = current->nextNode;
		delete current;
		current = next;
	}
}

template<typename T>
void LinkedList<T>::Append(T _newData)
{
	//Allocate node, populate data and set next null
	LinkedListNode<T>* newNode = new LinkedListNode<T>();
	newNode->data = _newData;
	newNode->nextNode = NULL;

	//If head null, this is first node
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	//Traverse list and set next node as new node
	LinkedListNode<T>* last = head;
	while (last->nextNode != NULL)
	{
		last = last->nextNode;
	}
	//Update link on last 
	newNode->prevNode = last;
	last->nextNode = newNode;
	return;
}

template<typename T>
void LinkedList<T>::Push(T _newData)
{
	LinkedListNode<T>* newNode = new LinkedListNode<T>();
	newNode->data = _newData;
	newNode->nextNode = head;
	head->prevNode = newNode;
	head = newNode;
	newNode->prevNode = NULL;
}

template<typename T>
void LinkedList<T>::PrintList()
{
	LinkedListNode<T>* current = head;
	while (current != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->nextNode;
	}
}

template<typename T>
void LinkedList<T>::RemoveFromStart()
{
	LinkedListNode<T>* next = head->nextNode;
	next->prevNode = NULL;
	head->nextNode = NULL;
	delete(head);
	head = next;
}

template<typename T>
void LinkedList<T>::RemoveFromEnd()
{
	LinkedListNode<T>* current = head;
	while (current->nextNode != NULL)
	{
		current = current->nextNode;
	}
	current->prevNode->nextNode = NULL;
	current->prevNode = NULL;
	delete(current);
}

