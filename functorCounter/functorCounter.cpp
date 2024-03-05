#include <iostream>
#include <vector>

class SumFunctor {
public:
    SumFunctor(const std::vector<int>& vec) : _vec(vec) {}

    int operator()() const // Функтор
    { 
        int sum = 0;
        for (const auto& elem : _vec)
        {
            sum += elem;
        }
        return sum; 
    }

private:
    std::vector<int> _vec;
};

class CountFunctor {
public:
    CountFunctor(const std::vector<int>& vec) : _vec(vec) {}

    int operator()() const // Функтор
    {
        int count = 0;
        for (const auto& elem : _vec)
        {
            if (elem % 3 == 0)
                ++count;
        }
        return count;
    }

private:
    std::vector<int> _vec;
};

int main()
{
    std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
    SumFunctor get_sum(vec);
    CountFunctor get_count(vec);
    std::cout << "Sum:\t" << get_sum() << std::endl;
    std::cout << "Count:\t" << get_count() << std::endl;
}