#pragma once
#include <MinLib/Algorithm.hpp>

namespace Aiva::MinLib
{
    template <typename Type, typename... Types>
    constexpr Type Min(Type const& value, Types const&... values)
    {
        Type min = value;

        if constexpr (sizeof...(values) > 0)
        {
            const Type tmp = Min(values...);
            min = min < tmp ? min : tmp;
        }

        return min;
    }

    template <typename Type, typename... Types>
    constexpr Type Max(Type const& value, Types const&... values)
    {
        Type max = value;

        if constexpr (sizeof...(values) > 0)
        {
            const Type tmp = Max(values...);
            max = max > tmp ? max : tmp;
        }

        return max;
    }

    constexpr uintptr_t GetStringLength(char const*const string)
    {
        auto length = uintptr_t{};

        while (string[length] != '\0')
            length++;

        return length;
    }
}
// namespace Aiva::MinLib
