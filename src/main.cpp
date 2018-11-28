#include <iostream>

#include "gennex.hpp"

int main()
{
    std::cout << "Parse file..." << std::endl;

    auto [a, err] = gennex::pevak::parse_file("a.txt");

    if (err)
    {
        std::cout << "Parse error! Invalid file." << std::endl;
        return -1;
    }

    gennex::pevak::uint256_t b = {
        34590, 51983, 48540, 42271,
        17834, 9045, 4521, 42720,
        23199, 36483, 57851, 43904,
        29973, 11883, 21338, 44104
    };

    gennex::pevak::uint256_t c = gennex::pevak::sub(b, a);

    std::string flag;

    std::cout << "Flag: ";
    for (auto & v : c)
    {
        flag += static_cast<char>(v);
    }

    std::cout << flag;

    return 0;
}