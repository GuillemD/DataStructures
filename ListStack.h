#ifndef _LISTSTACK_H_
#define _LISTSTACK_H_

#include "SLinkedList.h"

template<class type>
class Stack2
{
public:

	uint size() const
	{
		return data.size();
	}

	void push(const type& element)
	{
		data.push_back(element);
	}

	bool pop(type& result)
	{
		return data.pop_back(result);
	}

	const type* peek() const
	{
		return data.back();
	}

	void clear()
	{
		data.clear();
	}

	bool empty()
	{
		return data.empty();
	}

private:

	List<type> data;
};


#endif