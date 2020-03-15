#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <utility>

namespace OK
{
template<typename T>
class vector
{
	private:
	T* m_data {nullptr};
	size_t m_capacity {4ULL};
	size_t m_size {0ULL};

	public:
	vector();
	explicit vector(size_t size);
	vector(size_t size, const T val);
	vector(std::initializer_list<T>);
	vector(const vector&);
	vector(vector&&);
	~vector();

	size_t size() const;
	size_t length() const;
	size_t capacity() const;
	bool empty() const;

	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;
	T* data();
	const T* data() const;

	void push_back(const T&);
	void push_back(T&&);
	void pop_back();

	void clear();
	void reserve(size_t size);

	// TODO insert
	// TODO delete / erase
	// TODO resize
	// TODO comparison operators, maybe spaceship?
};

}	 // namespace OK

#endif	  // VECTOR_HPP
