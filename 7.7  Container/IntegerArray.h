#pragma once
class IntegerArray
{
private:
	int _count;
	int* array;

public:
	IntegerArray() = default;
	IntegerArray(int count);
	const int GetLength() const;
	const int GetElementbyIndex(int index) const;
	void InsertElementByIndex(int index, int newElement);
	void DeleteElementByIndex(int index);
	void SetSizeOfArray(int newSize);
	void PushBack(int newElement);
	void PushFront(int newElement);
	void PopBack();
	void PopFront();
	void CopyContainerTo(IntegerArray& destinationContainer);
	void PrintContainer();
	int& operator[](int index);
	~IntegerArray();
};