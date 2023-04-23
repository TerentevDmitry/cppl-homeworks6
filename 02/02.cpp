// Домашнее задание к занятию «STL. Часть 1»
// Задание 2. Удаление дубликатов.

#include <iostream>
#include <set>

template<class T>
void printV(const T& s0)
{
    std::cout << "\nПечать введенных данных без повторов:" << std::endl;
    for (const auto& i : s0)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    int numberOfElements = 0;
    int elements = 0;
    std::set<int, std::greater<>> s1;

    std::cout << "Введите количество элементов:>";
    std::cin >> numberOfElements;

    while (numberOfElements)
    {
        std::cout << "Введите элементы(всего " << numberOfElements << "):>";
        std::cin >> elements;
        s1.insert(elements);
        numberOfElements--;
    }

    printV(s1);

    std::cout << "Hello World!\n";
}