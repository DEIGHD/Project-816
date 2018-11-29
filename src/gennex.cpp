#include "gennex.hpp"

gennex::pevak::uint256_t gennex::pevak::string_to_uint256(std::string_view str)
{
    std::string tmp;
    gennex::pevak::uint256_t res;
    std::size_t i = 0, j = 0;
    for (auto & c : str)
    {
        tmp += c;
        i++;
        if (res.max_size() == i)
        {
            res[j] = string_to_integer<std::uint16_t>(tmp, 2).first;
            j++;
            i = 0;
            tmp.clear();
        }
    }

    return res;
}

std::pair<gennex::pevak::uint256_t, bool> gennex::pevak::parse_file(
    std::string_view file_path
)
{
    constexpr std::size_t true_file_size = 256;

    gennex::pevak::uint256_t value;
    std::ifstream file(file_path.data());

    if (!file)
    {
        file.close();
        return { value, true };
    }

    std::string content;
    file >> content;
    if (content.size() != true_file_size)
    {
        return { value, true };
    }

    if (!file)
    {
        file.close();
        return { value, true };
    }

    file.close();

    value = gennex::pevak::string_to_uint256(content);

    return { value, false };
}

gennex::pevak::uint256_t gennex::pevak::sub(
    const gennex::pevak::uint256_t & a, 
    const gennex::pevak::uint256_t & b
)
{
    gennex::pevak::uint256_t c;

    std::uint16_t d = 0;
    std::uint32_t T = 0;
    for (std::size_t i = 0; i < c.size(); i++)
    {
        T = static_cast<std::uint64_t>(a[i]) - static_cast<std::uint64_t>(b[i]) - d;
        c[i] = static_cast<std::uint16_t>(T);
        if (static_cast<std::uint16_t>(T >> c.size()) == 0)
        {
            d = 0;
        }
        else
        {
            d = 1;
        }
    }

    return c;
}