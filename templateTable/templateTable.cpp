#include <iostream>
#include <vector>

template<typename T>
class Table {
public:
    Table(size_t row, size_t col) :_row(row), _col(col), tab(_row, std::vector<T>(_col))
    {
    }

    const std::vector<T>& operator[](int index) const
    {
        if (index < 0 || index >= _row)
        {
            throw std::runtime_error("Error! Row index out of bounds");
        }
        return tab[index];
    }

    std::vector<T>& operator[](int index)
    {
        if (index < 0 || index >= _row)
        {
            throw std::runtime_error("Error! Row index out of bounds");
        }
        return tab[index];
    }

    //    void operator=(T value)
    //    {
    //        this->Tab = value;
    //    }

    Table& operator=(const Table&) = delete; // запрет копирования через оператор =


private:
    size_t _row;
    size_t _col;
    std::vector<std::vector<T>> tab;
};

int main()
{
    auto test = Table<int>(2, 3);
    try
    {
        test[0][0] = 4;
        test[1][2] = 8;
        test[1][0] = 16;
        std::cout << test[0][0] << std::endl; // выводит 4
        std::cout << test[1][2] << std::endl; // выводит 8
        std::cout << test[1][0] << std::endl; // выводит 16
    }
    catch (std::runtime_error& err)
    {
        std::cout << err.what();
    }
    return 0;
}