#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

class List
{
	public:
		List();
		~List();
		ListNode * makeNode(int data);
		bool insertInOrder(int data);
		void printList(ListNode *next);
		int deleteEndNode();


	private:
		ListNode *mpList;
		void destroyList();
};


#endif