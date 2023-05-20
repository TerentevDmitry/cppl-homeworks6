#pragma once
#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>


template<class T>
class MySTDVector
{
	T* arr_ = nullptr;
	size_t sizeOfVector_ = 0;
	size_t capacityOfVector_ = 0;

public:
	//MySTDVector(size_t n, const T& value = T()) 
	//{ arr_ = new T[n]; std::cout << "constructor(size_t) " << this << std::endl; };
		
	MySTDVector() 
	{ 
		std::cout << "constructor() " << this << std::endl;
	};
	
	//Copy constructor.
	MySTDVector(const MySTDVector& other) 
		: sizeOfVector_(other.sizeOfVector_), capacityOfVector_(other.sizeOfVector_) {
		//создаем новый массив2 длинной как массив1(other) с которого копируем.
		arr_ = new T[other.sizeOfVector_]{};

		//копируем элементы из массив1(other) в массив2
		for (size_t i = 0; i < other.sizeOfVector_; i++)
		{
			arr_[i] = other.arr_[i];
		}
		std::cout << "copy constructor(other) " << this << std::endl;
		std::cout << std::endl;
	};

	//Copy assigment operator=.
	MySTDVector& operator=(const MySTDVector& other)
	{
		if (arr_ == other.arr_)
			return *this;
		if (arr_)
			delete arr_;

		//создаем новый массив2 длинной как массив1(other) с которого копируем.
		arr_ = new T[other.sizeOfVector_]{};
		sizeOfVector_ = other.sizeOfVector_;
		capacityOfVector_ = other.sizeOfVector_;

		//копируем элементы из массив1(other) в массив2
		for (size_t i = 0; i < other.sizeOfVector_; i++)
		{
			arr_[i] = other.arr_[i];
		}
		std::cout << "copy assigment constructor(other) " << this << std::endl;
		std::cout << std::endl;
		return *this;
	}



	////move constructor.
	MySTDVector(MySTDVector&& other) noexcept : sizeOfVector_(other.sizeOfVector_), capacityOfVector_(other.capacityOfVector_) {
		
		arr_ = other.arr_;
		other.arr_ = nullptr;
		other.capacityOfVector_ = 0;
		other.sizeOfVector_ = 0;

		std::cout << "move constructor(other) " << this << std::endl;
		std::cout << std::endl;
	};

	//

	//move assigment operator=.
	MySTDVector& operator=(MySTDVector&& other) noexcept {
	
		if (arr_ == other.arr_)
			return *this;
		
		other.capacityOfVector_ = 0;
		other.sizeOfVector_ = 0;
		arr_ = other.arr_;
		other.arr_ = nullptr;
		

		std::cout << "move assigment operator= " << this << std::endl;
		std::cout << std::endl;
		return *this;
	};

	//Destructor
	~MySTDVector() 
	{
		
		sizeOfVector_ = 0;
		capacityOfVector_ = 0;
		//delete[] arr_;
		arr_ = nullptr;
		std::cout << "destructor " << this << std::endl;

	};

	//Оператор () запрещен
	T& operator()(size_t i) = delete;

	//Оператор []
	T& operator[](size_t i) { return arr_[i]; };

	//Константный Оператор []
	const T& operator[](size_t i) const { return arr_[i]; };

	// Метод at с проверкой индекса на out_of_range
	T& at(size_t i)
	{
		if (i >= sizeOfVector_) throw std::out_of_range("out_of_range");
		return arr_[i];
	};
	
	//Константный Метод at с проверкой индекса на out_of_range
	const T& at(size_t i) const
	{
		if (i >= sizeOfVector_) throw std::out_of_range("out_of_range");
			return arr_[i];
	};

	size_t size() const noexcept
	{
		return sizeOfVector_;
	};

	size_t capacity() const noexcept
	{
		return capacityOfVector_;
	};

	void reserve(const size_t newCapacityOfVector)
	{
		if (newCapacityOfVector <= capacityOfVector_) return;

		T* newarr = new T[newCapacityOfVector];

		for (size_t i = 0; i < sizeOfVector_; i++)
		{
			newarr[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = newarr;
		capacityOfVector_ = newCapacityOfVector;
	}

	void push_back(const T& value)
	{
		if (arr_ == nullptr)
		{
			capacityOfVector_ = 1;
			arr_ = new T[capacityOfVector_];
		}
		
		if (capacityOfVector_ == sizeOfVector_)
		{
			reserve(2 * capacityOfVector_);
		}
		arr_[sizeOfVector_] = value;
		++sizeOfVector_;
	};

	void pop_back()
	{
		if (sizeOfVector_ == 0) throw std::out_of_range("there_are_no_values_in_the_vector");
		--sizeOfVector_;
	};
};

template<class T>
void printVector(const MySTDVector<T>& v0)
{
	std::cout << "capacityOfVector_() = " << v0.capacity() << std::endl;
	std::cout << "sizeOfVector_ = " << v0.size() << std::endl;
	
	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0.at(i) << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;
};