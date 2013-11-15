#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "QueueNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Queue
{
	public:
		Queue();
		Queue(Queue &rhs);
		~Queue();
		Queue & operator=(Queue &rhs);
		bool enqueue(string newData);
		string dequeue();
		void printQueue();

	private:
		QueueNode *mpHead;
		QueueNode *mpTail;
		int mSize;
};

#endif
