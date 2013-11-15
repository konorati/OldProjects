#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

template <typename T>
class ListNode
{
	public: 
		ListNode (T newData, ListNode<T> *newPtr = NULL);
		ListNode (ListNode<T> &newNode);
		~ListNode();
		ListNode<T> & operator=(const ListNode<T> &rhs);

		T getData (void) const;
		void setData (T newData);
	
	private:
		T mData;
};
//class List; //forward declaration

/*class ListNode
{
	friend class List;
	public:
		//Constructors/Destructors
		ListNode(int data = 0);
		ListNode(ListNode &obj);
		~ListNode();
		ListNode & operator=(ListNode &rhs);

		//Get/Set functions
		int getData() const;
		ListNode *getNext() const;
		void setData(int data);
		void setNext(ListNode *next);

	private:
		int mData;
		ListNode *mpNext;
};*/


#endif