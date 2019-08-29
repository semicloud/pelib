/**
 * This file includes some useful algorithms for generating permutation or combination from a given set.
 * 
 * 
 * Author: LiQinyong
 * Date: 2019-08
 * 
 * Usage:
 * 
 * 
 * */

#ifndef PELIB_PERM_COMB_H
#define PELIB_PERM_COMB_H

#include <algorithm>
#include <cassert>
#include <type_traits>
#include <vector>

namespace pelib
{

/**
 * Get the value of C_n^k
 * @params n
 * @params k
 * @return the value of C_n^k
 * */
template <typename T>
T n_choose_k(T n, T k)
{
    assert(k <= n);
    if (k == 0)
        return 1;
    else
        return (n * n_choose_k(n - 1, k - 1)) / k;
}

template <typename T>
T n_permute_k(T n, T k)
{
    assert(k <= n);
    if (k == 1)
        return n;
    else
        return n * n_permute_k(n - 1, k - 1);
}

/**
 * This function gives all combinations from src and a given cnt, which cnt <= src.size()
 * 
 * @params src
 * @params cnt
 * @return
 * 
 * */
template <typename T>
std::vector<std::vector<T>> combination(std::vector<T> src, size_t cnt)
{

}

/**
 * This function gives all *permutations* from src and a given cnt, which cnt <= src.size()
 * 
 * */
template <typename T>
std::vector<std::vector<T>> permutation(std::vector<T> src, size_t cnt)
{
    
}

} // namespace pelib

#endif