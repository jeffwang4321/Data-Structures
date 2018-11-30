/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: June, 29, 2017
 * Author: Jeff Wang 301309384 & Chao Chun Lai 301218471.
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
// and it means: do not include me more than once.
#pragma once

template<class ElementType>
class Node
{
public:
	// Public attributes - Why are the attributes public?
	//Event data;     // The data in the node
    ElementType data;
	Node<ElementType>* next;   // Pointer to next node
	
	// Constructors
	Node();
	Node(ElementType theData);
	Node(ElementType theData, Node<ElementType>* theNextNode);

}; // end Node


/////////////////////////////////////////Node.cpp////////////////////////////////////
#include <cstdio>
#include "Node.h"

//Constructors
template<class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

template<class ElementType>
Node<ElementType>::Node(ElementType theData, Node<ElementType>* theNextNode)
{
	data = theData;
	next = theNextNode;
}

// end Node.cpp