#ifndef __Queue_H__
#define __Queue_H__


#include "SLinkedList.h"


template<class TYPE>
class Queue
{
public:


	unsigned int size() const //get size
	{
		return list.size();
	}

	
	void push(const TYPE& item) //push new item
	{
		list.push_back(item);
	}

	
	bool pop(TYPE& item) //deletes item from the list
	{
		return list.pop_front(item);
	}

	
	const TYPE* peek() const //reads next value to pop
	{
		return list.front();
	}

	
	void clean() //cleaning the queue
	{
		list.clear();
	}

	
	bool empty() // check if it's empty
	{
		return list.empty();
	}

private:
	List<TYPE> list;

};
#endif //Queue_H__