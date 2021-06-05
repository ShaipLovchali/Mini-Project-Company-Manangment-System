#pragma once

template <typename T>
class Vector {
private:
	T* contents;
	size_t size;
	size_t capacity;

	void copy(const Vector<T>&);
	void erase();
public:
	Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	const T& operator[](size_t) const;
	T& operator[](size_t);

	Vector<T> operator+(const Vector<T>&) const;
	void operator+=(const Vector<T>&);
	Vector<T> operator-(const Vector<T>&) const;
	void operator-=(const Vector<T>&);

	void push_back(T);
	void push_front(T);
	void push_by_index(T, size_t);
	void pop_back();
	void pop_front();
	void pop_by_data(T);

	size_t getCapacity() const;
	size_t getSize() const;
	void clear();

	bool isInVector(const T&);

	void printVector() const;
};
