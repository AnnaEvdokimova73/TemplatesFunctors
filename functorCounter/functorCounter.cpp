#include <iostream>
#include <vector>
#include <algorithm>

class Functor {
public:
    Functor() : _count{ 0 }, _sum{ 0 } {}

    void operator()(const int& elem)
    { 
        _sum += elem;
        if (elem % 3 == 0)
            ++_count;
    }

    int get_sum() const { return _sum; }
    int get_count() const { return _count; }

private:
    int _count;
    int _sum;
};


int main()
{
    std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };
    Functor functor;
    functor = std::for_each(vec.begin(), vec.end(), functor);

    std::cout << "[IN]: ";
    for (const auto& elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "[OUT]: get_sum() = " << functor.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << functor.get_count() << "\n";
}