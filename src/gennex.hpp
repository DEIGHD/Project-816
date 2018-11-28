#pragma once
#include <array>
#include <charconv>
#include <fstream>
#include <string>

namespace gennex::pevak
{
    typedef std::array<std::uint16_t, 16> uint256_t;

    template<class TYPE>
    std::pair<TYPE, std::errc> string_to_integer(std::string_view str, int base)
    {
        TYPE res {};
        auto[ptr, err] = std::from_chars(str.data(), str.data() + str.size(), res, base);
        return { res, err };
    }

    std::pair<uint256_t, bool> parse_file(std::string_view file_path);

    uint256_t string_to_uint256(std::string_view str);

    uint256_t sub(const uint256_t & a, const uint256_t & b);
}