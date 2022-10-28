#include "IntegerArray.h"
#include <iostream>

class BadRange : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Bad Range";
	}
};

class BadLength : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Bad Length";
	}
};

	IntegerArray::IntegerArray(int count) : _count(count)
	{

		if (count < 0)
		{
			throw BadLength();
		}

		array = new int[count];
	}

	void IntegerArray::InsertElementByIndex(int index, int newElement)
	{
		if (index < 0 || index > _count)
		{
			throw BadRange();
		}

		_count += 1;
		int* tempArray = new int[_count];

		for (int i = 0; i < index; ++i)
		{
			tempArray[i] = array[i];
		}

		tempArray[index] = newElement;

		for (int i = index + 1; i < _count; ++i)
		{
			tempArray[i] = array[i - 1];
		}

		delete[] array;
		array = tempArray;
	}

	void IntegerArray::DeleteElementByIndex(int index)
	{
		if (index < 0 || index > _count)
		{
			throw BadRange();
		}

		_count -= 1;
		int* tempArray = new int[_count];
		for (int i = 0; i < index; ++i)
		{
			tempArray[i] = array[i];
		}

		for (int i = index; i < _count; ++i)
		{
			tempArray[i] = array[i + 1];
		}

		delete[] array;
		array = tempArray;
	}

	const int IntegerArray::GetElementbyIndex(int index) const
	{
		return array[index];
	}

	const int IntegerArray::GetLength() const
	{
		return _count;
	}

	void IntegerArray::SetSizeOfArray(int newSize)
	{
		if (newSize < 0)
		{
			throw BadLength();
		}

		int* tempArray = new int[newSize];

		for (int i = 0; i < newSize; ++i)
		{
			tempArray[i] = array[i];
		}

		delete[] array;

		array = tempArray;
		_count = newSize;
	}

	void IntegerArray::PushBack(int newElement)
	{
		if (newElement < INT_MIN || newElement > INT_MAX) //hmmm....
		{
			throw BadRange(); // no matter
		}

		SetSizeOfArray(_count + 1);
		array[_count - 1] = newElement;
	}

	void IntegerArray::PushFront(int newElement)
	{
		_count += 1;
		int* tempArray = new int[_count];
		tempArray[0] = newElement;

		for (int i = 1; i < _count; ++i)
		{
			tempArray[i] = array[i - 1];
		}

		delete[] array;

		array = tempArray;
	}

	void IntegerArray::PopBack()
	{
		if (_count < 1)
		{
			throw BadLength();
		}

		_count -= 1;
		SetSizeOfArray(_count);
	}

	void IntegerArray::PopFront()
	{
		if (_count < 1)
		{
			throw BadLength();
		}

		_count -= 1;
		int* tempArray = new int[_count];

		for (int i = 0; i < _count; ++i)
		{
			tempArray[i] = array[i + 1];
		}

		delete[] array;

		array = tempArray;
	}

	void IntegerArray::CopyContainerTo(IntegerArray& destinationContainer)
	{

		if (destinationContainer._count != _count)
		{
			throw BadLength();
		}

		for (int i = 0; i < _count; ++i)
		{
			destinationContainer[i] = array[i];
		}
	}

	void IntegerArray::PrintContainer()
	{
		std::cout << "Count " << _count << std::endl;
		for (int i{ 0 }; i < _count; ++i)
			std::cout << array[i] << '\n';
	}

	int& IntegerArray::operator[](int index)
	{
		if (index < 0 || index > _count)
		{
			throw BadRange();
		}

		return array[index];
	}

	IntegerArray::~IntegerArray()
	{
		delete[] array;
	}