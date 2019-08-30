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
#include <vector>
#include <sstream>

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
 * This function gives all *combinations* from src and a given cnt, which cnt <= src.size()
 * 
 * @params src all elements to generate *combinations*
 * @params cnt how many elements do you want per trail
 * @return how many trais do you have and how many elements in your trail
 * 
 * */
template <typename T>
std::vector<std::vector<T>> combination(const std::vector<T> &src, size_t cnt)
{
    assert(cnt <= src.size() && cnt >= 1 && src.size() > 0);
    std::vector<std::vector<T>> comb_trails;
    std::vector<bool> bitset(src.size() - cnt, false);
    bitset.resize(src.size(), true);
    do
    {
        std::vector<T> trail;
        for (std::size_t i = 0; i != src.size(); ++i)
        {
            if (bitset[i])
            {
                trail.push_back(src[i]);
            }
        }
        comb_trails.push_back(trail);
    } while (std::next_permutation(bitset.begin(), bitset.end()));
    return comb_trails;
}

/**
 * This function gives all *permutations* from src and a given cnt, which cnt <= src.size()
 * @params src all elements to generate *permutations*
 * @params cnt how many elements do you want per trail
 * @return how many trais do you have and how many elements in your trail
 * */
template <typename T>
std::vector<std::vector<T>> permutation(const std::vector<T> &src, size_t cnt)
{
    assert(cnt <= src.size() && cnt >= 1 && src.size() > 0);
    std::vector<std::vector<T>> perm_trails; // all permutations
    std::vector<bool> bitset(src.size() - cnt, false);
    bitset.resize(src.size(), true);
    do
    {
        std::vector<T> comb_trail;
        for (std::size_t i = 0; i != src.size(); ++i)
        {
            if (bitset[i])
            {
                comb_trail.push_back(src[i]);
            }
        }
        // at here a combination is selected, then we totaly permuate it
        do
        {
            perm_trails.push_back(comb_trail);
        } while (std::next_permutation(comb_trail.begin(), comb_trail.end()));
    } while (std::next_permutation(bitset.begin(), bitset.end()));
    return perm_trails;
}

/**
 * This function gives all *permutations* from src (without a given size , of course)
 * @params src all elements to generate *permutations*
 * @return how many trais do you have and how many elements in your trail
 * @remark the function is equals to pelib::permutation(src, src.size());
 * */
template <typename T>
std::vector<std::vector<T>> permutation(const std::vector<T> &src)
{
    assert(src.size() > 0);
    auto src_cp(src);
    std::vector<std::vector<T>> perm_trails;
    do
    {
        perm_trails.push_back(src_cp);
    } while (std::next_permutation(src_cp.begin(), src_cp.end()));
    return perm_trails;
}

/**
 * Convert a std::vector of a std::vector to std::string 
 * @param vv the std::vector of std::vector to represent
 * @return the string representation of the std::vector of std::vector
 * */
template <typename T>
std::string vv_str(const std::vector<std::vector<T>> &vv)
{
    std::ostringstream oss;
    for (const std::vector<T> &v : vv)
    {
        for (const T &t : v)
            oss << t << " ";
        oss << std::endl;
    }
    return oss.str();
}

} // namespace pelib

#endif