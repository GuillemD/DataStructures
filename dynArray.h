#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#define BLOCK 10


typedef unsigned int uint;
template <class TYPE>
void SWAP(TYPE a, TYPE b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}
template <class TYPE>
class Vector
{
private:
	TYPE* vect = nullptr;
	uint capacity = BLOCK;
	uint num_elements = 0;
public:

	Vector()//empty constructor
	{
		vect = new TYPE[capacity];
	}

	Vector(const TYPE v1)//constructor
	{
		capacity = v1;
		vect = new TYPE[capacity];
	}

	Vector(const Vector& v2)//cpy constructor
	{
		num_elements = v2.num_elements;
		capacity = v2.capacity;
		vect = new TYPE[capacity];
		memcpy(v2.vect, vect, num_elements);
	}

	~Vector()//destructor
	{
		delete[] vect;
	}

	void push_back(const TYPE& val)//adding values at the end
	{
		if (num_elements == capacity)
		{
			capacity += BLOCK;
			TYPE* vect2 = new TYPE[capacity];
			for (uint i = 0; i < num_elements; ++i)
				vect2[i] = vect[i];
			delete[] vect;

			vect = vect2;
		}
		vect[num_elements++] = val;
	}


	bool pop_back(TYPE& result) //pop back
	{
		if (num_elements > 0)
		{
			result = data[--num_elements];
			return true;
		}
		return false;
	}


	void clear() //clear
	{
		num_elements = 0;
	}

	uint size() const // returning the number of elements
	{
		return num_elements;
	}

	bool empty() const //return if its empty
	{
		return num_elements == 0;
	}

	TYPE* front() // returning the first element
	{
		if (num_elements > 0)
			return &(data[0]);
		return nullptr;
	}

	const TYPE* front() const // returning the first element
	{
		if (num_elements > 0)
			return &(data[0]);
		return nullptr;
	}

	TYPE* back() //returning the last element
	{
		if (num_elements > 0)
			return &data[num_elements - 1];
		return nullptr;
	}

	const TYPE* back() const //returning the last element
	{
		if (num_elements > 0)
			return &data[num_elements - 1];
		return nullptr;
	}

	int bubble_sort()
	{
		int count_swap = 0;
		
		bool didSwap = true;
		

		while (didSwap)
		{
			
			didSwap = false;
			for (uint i = 0; i < num_elements - 2; i++)
			{
				count_swap++;
				if (vect[i] > vect[i + 1])
				{
					SWAP(vect[i], vect[i + 1]);
					didSwap = true;
				}
			}
		}
		return count_swap;
		
	}
};


#endif // !_DYNARRAY_H_