#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Queue; //forward declaration
class QueueNode
{
	friend class Queue;
	public:
		QueueNode(string newData = "");
		QueueNode(QueueNode &rhs);
		~QueueNode();
		QueueNode & operator=(QueueNode &rhs);

		void setData(string newData);
		void setNext(QueueNode *newNext);
		string getData();
		QueueNode * getNext();

	private:
		string mData;
		QueueNode *mpNext;
};




#endif