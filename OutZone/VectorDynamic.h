#ifndef __VECTOR__
#define __VECTOR__

#include <assert.h>

template<class TYPE>
class Vector{
private:
	TYPE* buffer;
	unsigned int capacity = 1;
	unsigned int num_elements = 0;



public:
	Vector()
	{
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& copy)
	{
		capacity = num_elements = copy.num_elements;
		buffer = new TYPE[capacity];
		//intentar amb memcpy
		for (unsigned int i = 0; i < num_elements; ++i)
			buffer[i] = copy.buffer[i];
	}

	Vector(unsigned int size)
	{
		buffer = new TYPE[capacity = size];
	}

	~Vector()
	{
		delete[] buffer;
	}

	//Source http://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
	TYPE &operator[](const unsigned int& i)
	{
		assert(i < num_elements);
		return buffer[i];
	}

	TYPE operator[](unsigned int i)const
	{
		assert(i < num_elements);
		return buffer[i];
	}

	void push_back(const TYPE &element){

		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}

		buffer[num_elements++] = element;
	}

	void push_front(const TYPE &element)const{
		if (capacity == num_elements)
		{
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}
		num_elements++;
		for (unsigned int i = 1; i < num_elements; i++)
			buffer[i] = buffer[i - 1];
		buffer[0] = element;
	}

	void PaintVector()const
	{
		for (unsigned int i = 0; i < num_elements; i++)
			printf("%i ", buffer[i]);
		printf("\n");
	}

	bool empty()const{
		return num_elements == 0 ? 1 : 0;
	}

	void clean()const{
		num_elements = 0;
	}

	int size()const{
		return num_elements;
	}

	int capacityn()const{
		return capacity;
	}

	bool pop_back(TYPE& value)const{
		if (num_elements != 0){
			TYPE temp = buffer[num_elements - 1];
			if (num_elements-- >= 0)
				num_elements = 0;
			value = temp;
			return true;
		}
		else
			return false;
	}

	void resize(const TYPE &element)
	{
		bool flag = false;
		TYPE *temp = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++)
		{
			if (flag == false){
				if (buffer[i] == element)
				{
					flag = true;
					i--;
					--num_elements;
				}
				else
					temp[i] = buffer[i];
			}
			else
				temp[i] = buffer[i+1];
		}
		delete[] buffer;
		buffer = temp;
	}

	bool pop_back(unsigned int resize, TYPE& value)const{
		if (num_elements != 0){
			TYPE temp;
			for (resize; resize > 0; resize--){
				if (num_elements == 1)
					temp = buffer[0];
				else
					temp = buffer[num_elements - 1];

				if (num_elements == 0)
					num_elements = 0;
				else
					num_elements--;
			}
			value = temp;
			return true;
		}
		else
			return false;
	}

	void shrink_to_fit()const{
		TYPE* temp = nullptr;
		capacity = num_elements;
		temp = new TYPE[capacity];

		for (unsigned int i = 0; i < num_elements; i++)
			temp[i] = buffer[i];

		delete[] buffer;

		buffer = temp;
	}

	//at(), [] don't use assert..

};

#endif