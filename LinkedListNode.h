#pragma once
template<typename T>
class LinkedListNode
{
public:
	LinkedListNode<T>* prevNode;
	LinkedListNode<T>* nextNode;
	T data;

	LinkedListNode();
	~LinkedListNode();
};

template<typename T>
LinkedListNode<T>::LinkedListNode()
{
	
}


template<typename T>
LinkedListNode<T>::~LinkedListNode()
{

}
