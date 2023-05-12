#pragma once
#include <stdexcept>
#include <iostream>
#include <vector>


template<class T>
class MySTDVector
{
	T* arr_;
	size_t sizeOfVector_ = 0;
	size_t capacityOfVector_ = 0;

public:

	MySTDVector(size_t n, const T& value = T()) {};
	//MySTDVector();
	
	//empty container constructor (default constructor).Constructs an empty container, with no elements.
	//MySTDVector();
	
	MySTDVector() : sizeOfVector_(0), capacityOfVector_(0), arr_(new T[1]) {};
	
	//copy constructor. �onstructs a container with a copy of each of the elements in x, in the same order.
	MySTDVector(const MySTDVector& other) : sizeOfVector_(other.size()), capacityOfVector_(other.capacity())
	{
		//������� ����� ������2 ������� ��� ������1(other) � �������� ��������.
		arr_ = new T [other.size()] {};

		//�������� �������� �� ������1(other) � ������2
		for (size_t i = 0; i <= other.sizeOfVector_-1; i++)
		{
			this->arr_[i] = other.arr_[i];
		}
		
		std::cout << std::endl;
	};
	
	//fill constructor. Constructs a container with n elements. Each element is a copy of val.
	//MySTDVector(size_t n, const T& value = T()) : sizeOfVector_(n), capacityOfVector_(9), arr_(new T[n]) {};
	
	//move constructor.Constructs a container that acquires the elements of x.
	//MySTDVector(MySTDVector&& x) {};

	//�������� []
	T& operator[](size_t i) { return arr_[i]; };

	// ����� at � ��������� ������� �� out_of_range
	T& at(size_t i) 
	{ 
		if (i >= sizeOfVector_) throw std::out_of_range("out_of_range");
		return arr_[i];
	};

	//�������� () ��������
	T& operator()(size_t i) = delete;

	//�������� ������� ����������� ������ ������� � ������
	T& operator=(const MySTDVector& other) = delete;

	//����������� �������� []
	const T& operator[](size_t i) const { return arr_[i]; };

	// ����������� ����� at � ��������� ������� �� out_of_range
	const T& at(size_t i) const
	{
		if (i >= sizeOfVector_) throw std::out_of_range("out_of_range");
			return arr_[i];
	};

	size_t size() const noexcept
	{
		return sizeOfVector_;
	};

	//void resize(size_t n) {};

	size_t capacity() const noexcept
	{
		return capacityOfVector_;
	};

	void reserve(const size_t newCapacityOfVector)
	{
		if (newCapacityOfVector <= capacityOfVector_) return;

		T* newarr = reinterpret_cast<T*>(new std::byte[newCapacityOfVector * sizeof(T)]);
		try
		{ 
		std::uninitialized_copy(arr_, arr_ + sizeOfVector_, newarr);
		}
		catch (...)
		{
			delete[] reinterpret_cast<std::byte*>(arr_);
			throw;
		}

		for (size_t i = 0; i < sizeOfVector_; ++i)
		{
			(arr_ + i)->~T();
		}
		delete[] reinterpret_cast<int8_t*>(arr_);
		arr_ = newarr;
		capacityOfVector_ = newCapacityOfVector;
	}

		//delete[] reinterpret_cast<std::byte*>(this->arr_);
		//this->arr_ = newarr;
		
	
	void push_back(const T& value)
	{
		if (capacityOfVector_ == 0) reserve(++capacityOfVector_);
		if (sizeOfVector_ >= capacityOfVector_) reserve(2 * capacityOfVector_);
		new(arr_ + sizeOfVector_) T(value);
		++sizeOfVector_;
	};

	void pop_back()
	{
		if (sizeOfVector_ == 0) throw std::out_of_range("there_are_no_values_in_the_vector");
		(arr_ + sizeOfVector_ - 1)->~T();
		--sizeOfVector_;
	};
};

template<class T>
void printVector(const MySTDVector<T>& v0)
{
	
	std::cout << "capacity() = " << v0.capacity() << std::endl;

	std::cout << "size() = " << v0.size() << std::endl;
	
	
	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0[i] << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;
};