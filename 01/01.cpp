 // Домашнее задание к занятию «STL. Часть 1»
// Задание 1. Частота символов.

#include <iostream>
#include <string>
#include <map>
#include <set>

template<class T>
void printM(const T& m0, const std::string* letters)
{
    std::cout << "\nPrint Number Of Repetitions: " << *letters << std::endl;
    for (const auto& m : m0)
    {
        std::cout << m.second << ": " << m.first << '\n';
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    size_t numberOfRepetitions = 0;
    std::string letters = "HHHHello world!!";
    std::multimap<size_t, char, std::greater<size_t>> m1;
    
    //std::cout << "Введите фразу:";
    //std::getline(std::cin, letters);
    
    //создаем Ассоциативный контейнер s1
    std::set<char> s1;

    //заполняем Ассоциативный контейнер s1: char из letters
    for (size_t i = 0; i < letters.length(); i++)
    {
        s1.insert(letters[i]);
    }

    //заполняем Ассоциативный контейнер m1: ключ(кол-во повторений каждой буквы) значение сама буква
    for (const auto& i : s1)
    {
        numberOfRepetitions = std::count(letters.begin(), letters.end(), i);
        m1.emplace(numberOfRepetitions, i);
    }
    printM(m1, &letters);
}