#include "vector.hpp"

namespace OK
{
template<typename T>
vector<T>::vector()
{
	this->m_data = new T[this->m_capacity];
}

template<typename T>
vector<T>::vector(size_t size)
{
	this->m_capacity = size * 2UL;
	this->m_data = new T[this->m_capacity];
	for(size_t i = 0ULL; i < size; ++i)
		this->m_data[i] = T();
	this->m_size = size;
}

template<typename T>
vector<T>::vector(size_t size, const T val)
{
	this->m_capacity = size * 2UL;
	this->m_data = new T[this->m_capacity];
	for(size_t i = 0ULL; i < size; ++i)
		this->m_data[i] = val;
	this->m_size = size;
}

template<typename T>
vector<T>::vector(std::initializer_list<T> list)
{
	this->m_capacity = list.size();
	this->m_data = new T[this->m_capacity];
	for(const auto& elem: list)
		this->data[this->m_size++] = elem;
}

template<typename T>
vector<T>::vector(const vector& other)
{
	this->m_capacity = other.m_capacity;
	this->m_data = new T[this->m_capacity];
	for(size_t i = 0ULL; i < other.m_size; ++i)
		this->m_data[i] = other.m_data[i];
	this->m_size = other.m_size;
}

template<typename T>
vector<T>::vector(vector&& other)
{
	this->m_capacity = other.m_capacity;
	this->m_data = new T[this->m_capacity];
	for(size_t i = 0ULL; i < other.m_size; ++i)
		this->m_data[i] = std::move(other.m_data[i]);
	this->m_size = other.m_size;
}

template<typename T>
vector<T>::~vector()
{
	delete[] this->m_data;
}

template<typename T>
size_t vector<T>::size() const
{
	return this->m_size;
}

template<typename T>
size_t vector<T>::length() const
{
	return this->m_size;
}

template<typename T>
size_t vector<T>::capacity() const
{
	return this->m_capacity;
}

template<typename T>
bool vector<T>::empty() const
{
	return this->m_size == 0ULL;
}

template<typename T>
T& vector<T>::operator[](size_t index)
{
	return this->m_data[index];
}

template<typename T>
const T& vector<T>::operator[](size_t index) const
{
	return this->m_data[index];
}

template<typename T>
T& vector<T>::front()
{
	return this->m_data[0];
}

template<typename T>
T& vector<T>::back()
{
	return this->m_data[this->m_size - 1];
}

template<typename T>
const T& vector<T>::front() const
{
	return this->m_data[0];
}

template<typename T>
const T& vector<T>::back() const
{
	return this->m_data[this->m_size - 1];
}

template<typename T>
T* vector<T>::data()
{
	return this->m_data;
}

template<typename T>
const T* vector<T>::data() const
{
	return this->m_data;
}

template<typename T>
void vector<T>::push_back(const T& val)
{
	if(this->m_size >= this->m_capacity)
	{
		this->m_capacity *= 2ULL;
		T* temp = new T[this->m_capacity];
		memcpy(temp, this->m_data, this->m_size * sizeof(T));
		delete[] this->m_data;
		this->m_data = temp;
	}
	this->m_data[this->m_size++] = val;
}

template<typename T>
void vector<T>::push_back(T&& val)
{
	if(this->m_size >= this->m_capacity)
	{
		this->m_capacity *= 2ULL;
		T* temp = new T[this->m_capacity];
		memcpy(temp, this->m_data, this->m_size * sizeof(T));
		delete[] this->m_data;
		this->m_data = temp;
	}
	this->m_data[this->m_size++] = std::move(val);
}

template<typename T>
void vector<T>::pop_back()
{
}

template<typename T>
void vector<T>::clear()
{
}

template<typename T>
void vector<T>::reserve(size_t size)
{
}

}	 // namespace OK
