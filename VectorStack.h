#ifndef _VECTORSTACK_H_
#define _VECTORSTACK_H_

#include "dynArray.h"

template <class type>
class Stack{

private:

	Vector<type> data;

public:


	void push(const type& value)
	{
		data.push_back(value);
	}
	bool pop(type& result)
	{
		data.pop_back(result);
	}
	const type* peek() const
	{
		return data.back();
	}

	bool empty() const
	{
		return data.empty();
	}

	uint size() const
	{
		return data.size();
	}

	void clean()
	{
		data.clear();
	}
};




#endif //! _VECTORSTACK_H_