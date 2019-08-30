#ifndef PELIB_PRIME_H
#define PELIB_PRIME_H

#include <cmath>

namespace pelib
{

template <typename T>
bool is_prime(T t)
{
    T i, sq;
    if (t == 1)
        return false;
    if (t == 2)
        return true;
    if (t % 2 == 0)
        return false;
    sq = std::sqrt(t);
    for (i = 2; i <= sq; i++)
        if (t % i == 0)
            return false;
    return true;
}
} // namespace pelib

#endif
