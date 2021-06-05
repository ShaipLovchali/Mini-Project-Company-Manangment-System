#include "Vector.h"
#include <iostream>

template<typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->contents = new T[this->size];
	for (size_t i = 0; i < this->capacity; ++i)
	{
		this->contents[i] = other.contents[i];
	}
}

template<typename T>
void Vector<T>::erase()
{
	delete[] this->contents;
}

template<typename T>
Vector<T>::Vector()
{
	this->size = 1;
	this->capacity = 0;
	this->contents = new T[this->size];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	erase();
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
	return this->contents[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
	return this->contents[index];
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
	Vector<T> addition = *this;

	for (size_t j = 0; j < other.capacity; ++j)
	{
		addition.push_back(other.contents[j]);
	}

	return addition;
}

template<typename T>
void Vector<T>::operator+=(const Vector<T>& other)
{
	*this = *this + other;
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const
{
	Vector<T> subtraction = *this;

	for (size_t i = 0; i < other.capacity; ++i)
	{
		subtraction.pop_by_data(other.contents[i]);
	}
	return subtraction;
}

template<typename T>
void Vector<T>::operator-=(const Vector<T>& other)
{
	*this = *this - other;
}

template<typename T>
void Vector<T>::push_back(T element)
{
	if (this->size <= this->capacity) {
		this->size *= 2;
		T* newContents = new T[this->size];
		for (size_t i = 0; i < this->capacity; ++i)
		{
			newContents[i] = this->contents[i];
		}

		erase();
		this->contents = newContents;
	}

	this->contents[this->capacity++] = element;
}

template<typename T>
void Vector<T>::push_front(T element)
{
	if (this->size <= this->capacity) {
		this->size *= 2;
	}
	T* newContents = new T[this->size];
	newContents[0] = element;
	for (size_t i = 0; i < this->capacity; ++i)
	{
		newContents[i + 1] = this->contents[i];
	}

	erase();
	this->contents = newContents;
	++this->capacity;
}

template<typename T>
void Vector<T>::push_by_index(T element, size_t index)
{
	if (this->size <= this->capacity) {
		this->size *= 2;
	}

	T* newContents = new T[this->size];
	newContents[index] = element;
	for (size_t i = 0; i < index; ++i)
	{
		newContents[i] = this->contents[i];
	}
	for (size_t i = index ; i < this->capacity; ++i)
	{
		newContents[i + 1] = this->contents[i];
	}
	erase();
	this->contents = newContents;
	++this->capacity;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (this->capacity > 0) {
		T* newContents = new T[this->size];
		for (size_t i = 0; i < this->capacity - 1; ++i)
		{
			newContents[i] = this->contents[i];
		}

		erase();
		this->contents = newContents;
		--this->capacity;
	}
}

template<typename T>
void Vector<T>::pop_front()
{
	if (this->capacity > 0) {
		T* newContents = new T[this->size];
		for (size_t i = 1; i < this->capacity; ++i)
		{
			newContents[i - 1] = this->contents[i];
		}

		erase();
		this->contents = newContents;
		--this->capacity;
	}
}

template<typename T>
void Vector<T>::pop_by_data(T element)
{
	T* newContents = new T[this->size];
	int count = 0;
	int newCapacity = 0;
	for (size_t i = 0; i < this->capacity; ++i)
	{
		if (this->contents[i] != element) {
			newContents[count++] = this->contents[i];
			++newCapacity;
		}
	}

	erase();
	this->contents = newContents;
	this->capacity = newCapacity;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
size_t Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
void Vector<T>::clear()
{
	for (size_t i = 0; i < size; i++)
	{
		this->contents[i] = ' ';
	}
}

template<typename T>
bool Vector<T>::isInVector(const T& element)
{
	for (size_t i = 0; i < this->capacity; ++i)
	{
		if (this->contents[i] == element) {
			return true;
		}
	}
	return false;
}

template<typename T>
void Vector<T>::printVector() const
{
	for (size_t i = 0; i < this->capacity; ++i)
	{
		std::cout << this->contents[i];
	}
}
