// Задание 3*. Аналог std::vector.
// Задача 3*. Аналог std::vector.


#include "MySTDVector.h"



int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "v1 = ";
    MySTDVector<int> v1;
    v1.push_back(111);
    printVector(v1);
    v1.push_back(122);
    printVector(v1);
    v1.push_back(133);
    v1.push_back(144);
    printVector(v1);
    v1.push_back(155);
    printVector(v1);
    v1.pop_back();
    printVector(v1);

    try
    {
        std::cout << "v1[0] = " << v1[0] << '\t';
        std::cout << "v1(0) = " << v1.at(0) << '\t';
        std::cout << "v1(1) = " << v1.at(v1.size() / 2) << '\t';
        std::cout << "v1(10) = " << v1.at(10) << '\t';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "v1(-10) = " << v1.at(-10) << '\t';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl << std::endl;
    }

    std::cout << "v2 = ";
    MySTDVector<int> v2(v1);
    v2.push_back(211);
    v2.push_back(222);
    v2.push_back(233);
    printVector(v2);
    v2.pop_back();
    printVector(v2);
    
    std::cout << "v3 = ";
    MySTDVector<double> v3;
    v3.push_back(311.1);
    v3.push_back(322.2);
    v3.push_back(333.3);
    printVector(v3);
    v3.pop_back();
    printVector(v3);

    std::cout << "v4 = ";
    MySTDVector<std::string> v4;
    v4.push_back("AAA");
    v4.push_back("BBB");
    v4.push_back("ЦЦЦ");
    printVector(v4);
    v4.pop_back();
    printVector(v4);

    //move constr
    std::cout << "v5 = ";
    MySTDVector<int> v5(std::move(v1));
    printVector(v5);
    
    //copy metod 
    std::cout << "v6 = ";
    MySTDVector<int> v6;
    std::cout << "v6 = v5 = ";
    v6 = v5;
    printVector(v6);

    ////move assigment 
    std::cout << "v6(v2) = ";
    v6 = std::move(v2);
    printVector(v6);

   std::cout << "Hello World!\n";
}