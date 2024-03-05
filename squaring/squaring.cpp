#include <iostream>
#include <vector>

template<typename T>
T& squaring(T& num)
{
    num *= num;
    return num;
}

template<typename T>
std::vector<T>& squaring(std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        el *= el;
    }
    return vec;
}

int main()
{
    int a = 4;
    std::vector<int> vec{ -1, 4, 8 };
    //std::vector<double> vec{ 1.1, 4.2, 8.9 };

    std::cout << "[IN]:\t" << a << std::endl;
    std::cout << "[OUT]:\t" <<  squaring(a) << std::endl;

    std::cout << "[IN]:\t";
    for (const auto& el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    squaring(vec);

    std::cout << "[OUT]:\t";
    for (const auto& el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}