#include <iostream>
#include <vector>

template<typename T>
T& squaring(T& num)
{
    num *= num;
    return num;
}

template<>
std::vector<int>& squaring(std::vector<int>& vec)
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