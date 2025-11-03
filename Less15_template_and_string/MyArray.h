#pragma once
#include <iostream>
template <typename T>
class MyArray
{
private:
	T* arr = nullptr;
	size_t size;
public:
	MyArray() {}
	MyArray(size_t size)
	{
		this->size = size;
		this->arr = new T[size];
	}
	MyArray(T* arr, size_t size)
	{
		this->size = size;
		this->arr = new T[size];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = arr[i];
		}
	}
	T& operator[](int index)
	{
		if (index >= 0 && index < this->size)
			return arr[index];
		throw "Index error!";
	}
	int getSize() const
	{
		return this->size;
	}
	T* getArr() const
	{
		return this->arr;
	}
	MyArray(const MyArray&) = delete;
	MyArray& operator=(const MyArray&) = delete;
	~MyArray()
	{
		if (this->arr != nullptr)
			delete[] this->arr;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MyArray<T>& obj)
{
	size_t size = obj.getSize();
	T* arr = obj.getArr();
	for (int i = 0; i < size; ++i)
	{
		out <<arr[i] << std::endl;
	}
	return out;
}