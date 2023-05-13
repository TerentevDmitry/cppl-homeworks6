#pragma once
#include <stdexcept>
#include <iostream>
#include <vector>


template<class T>
class MySTDVector
{
	T* arr_ = nullptr;
	size_t sizeOfVector_ = 0;
	size_t capacityOfVector_ = 0;

public:
	MySTDVector(size_t n, const T& value = T()) { arr_ = new T[n]; std::cout << "constructor(size_t) " << this << std::endl;
	};
		
	MySTDVector()/* : sizeOfVector_(0), capacityOfVector_(0), arr_(nullptr)*/ { std::cout << "constructor() " << this << std::endl; };
	//
	// 
	//copy constructor. Сonstructs a container with a copy of each of the elements in x, in the same order.
	MySTDVector(const MySTDVector& other) : sizeOfVector_(other.size()), capacityOfVector_(other.capacity()) {
		//создаем новый массив2 длинной как массив1(other) с которого копируем.
		arr_ = new T [other.size()] {};

		//копируем элементы из массив1(other) в массив2
		for (size_t i = 0; i < other.sizeOfVector_; i++)
		{
			arr_[i] = other.arr_[i];
		}
		std::cout << "copy constructor(other) " << this << std::endl;
		std::cout << std::endl;
	};

	//move constructor.
	MySTDVector(MySTDVector&& other) : sizeOfVector_(other.size()), capacityOfVector_(other.capacity()) {
		
		arr_ = other.arr_;
		other.arr_ = nullptr;

		std::cout << "move constructor(other) " << this << std::endl;
		std::cout << std::endl;
	};

	

	//Деструктор
	~MySTDVector() {
		//destroys all container elements
		for (size_t i = 0; i < sizeOfVector_; ++i)
		{
			(arr_ + i)->~T();
		}

		arr_ = nullptr;
		std::cout << "destructor " << this << std::endl;

	};
	


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


	//move assigment operator=.
	MySTDVector& operator=(MySTDVector&& other) {
	
		if (arr_ == other.arr_)
			return *this;
		
		arr_ = other.arr_;
		other.arr_ = nullptr;

		std::cout << "move assigment operator= " << this << std::endl;
		std::cout << std::endl;
		return *this;
	};



	//Константный Оператор []
	const T& operator[](size_t i) const { return arr_[i]; };

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

		T* newarr = reinterpret_cast<T*>(new int8_t[newCapacityOfVector * sizeof(T)]);
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

	void push_back(const T& value)
	{
		if (arr_ == nullptr) arr_ = new T;
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
	
	std::cout << "capacityOfVector_() = " << v0.capacity() << std::endl;

	std::cout << "sizeOfVector_ = " << v0.size() << std::endl;
	
	for (size_t i = 0; i < v0.size(); i++)
	{
		std::cout << v0.at(i) << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;
};