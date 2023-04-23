 // 01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>

template<class T>
void printM(const T& m0)
{
    std::cout << "\nprintM0\n";
    for (const auto& m : m0)
    {
        std::cout << m.first << ": " << m.second << '\n';
    }
}

template<class T>
void printV(const T& v0)
{
    std::cout << "\nprintV0\n";
    for (const auto& v : v0)
    {
        std::cout << v << '\n';
    }
}


int main()
{
    setlocale(LC_ALL, "ru");

    int numberOfRepetitions = 0;
    std::string letters = "HHHHHHHello wwwwOERLDDDD";
    std::map<char, int> m1;
    
    std::cout << "Введите фразу:";
    //std::getline(std::cin, letters);
    
    /*std::vector<char> vc1;

    for (size_t i = 0; i < letters.length(); i++)
    {
        vc1.emplace_back(letters[i]);
       
    }*/
    


    for (size_t i = 0; i < letters.length(); i++)
    {
        numberOfRepetitions = std::count(letters.begin(), letters.end(), letters[i]);
        m1.emplace(letters[i], numberOfRepetitions);
    }

    std::cout << std::endl << "letters.length() = " << letters.length();
    std::cout << std::endl << "letters.size() = " << letters.size();

    std::cout << std::endl << "Сортир M по значению " << letters.length();
    printM(m1);
}