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

	//MySTDVector(size_t n, const T& value = T()) {};
	
	//empty container constructor (default constructor).Constructs an empty container, with no elements.
	MySTDVector() : sizeOfVector_(0), capacityOfVector_(8), arr_(new T[8]) {};
	
	//copy constructor. Сonstructs a container with a copy of each of the elements in x, in the same order.
	MySTDVector(const MySTDVector& other) : sizeOfVector_(other.size()), capacityOfVector_(other.capacity())
	{
		delete[] this->arr_;

		//создаем новый массив2 длинной как массив1(other) с которого копируем.
		arr_ = new T [this->sizeOfVector_] {};

		//копируем элементы из массив1(other) в массив2
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

	//Оператор []
	T& operator[](size_t i) { return arr_[i]; };

	// Метод at с проверкой индекса на out_of_range
	T& at(size_t i) 
	{ 
		if (i >= sizeOfVector_) throw std::out_of_range("out_of_range");
		return arr_[i];
	};

	//Оператор () запрещен
	T& operator()(size_t i) = delete;

	//Удаление функции копирования одного объекта в другой
	T& operator=(const MySTDVector& other) = delete;

	//Константный Оператор []
	const T& operator[](size_t i) const { return arr_[i]; };

	// Константный Метод at с проверкой индекса на out_of_range
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

	void reserve(const size_t n)
	{
		if (n <= capacityOfVector_) return;

		T* newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
		try
		{ 
		std::uninitialized_copy(arr_, arr_ + sizeOfVector_, newarr);
		}
		catch (...)
		{
			delete[] reinterpret_cast<int8_t*>(arr_);
			arr_ = newarr;
		}
		for (size_t i = 0; i < sizeOfVector_; ++i)
		{
			(arr_ + i)->~T();
		}
		delete[] reinterpret_cast<int8_t*>(arr_);
		arr_ = newarr;
	}

	
	void push_back(const T& value)
	{
		if (sizeOfVector_ >= capacityOfVector_) reserve(2 * capacityOfVector_);
		new(arr_ + sizeOfVector_) T(value);
		++sizeOfVector_;
	};

	void pop_back()
	{
		(arr_ + sizeOfVector_ - 1)->~T();
		--sizeOfVector_;
	};
};

template<class T>
void printVector(const MySTDVector<T>& v0)
{
	
		std::cout << "capacity() = " << v0.capacity();
		std::cout << std::endl;

		std::cout << "size() = " << v0.size();
		std::cout << std::endl;
	
	
	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0[i] << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;
};