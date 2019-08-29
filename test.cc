#include "perm_comb.h"
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << pelib::n_choose_k<int>(100, 1) << std::endl;
    std::cout << pelib::n_choose_k<int>(26, 3) << std::endl;
    std::cout << pelib::n_permute_k<long>(99, 3) << std::endl;
    std::vector<std::string> src{"a", "b", "c", "d"};
    auto combinations = pelib::combination(src, 3);
    assert(combinations.size() == 4);
    auto permutations = pelib::permutation(src, 3);
    assert(permutations.size() == 24);
    std::cout << "combinations:" << std::endl;
    std::cout << pelib::vv_str(combinations);
    std::cout << "permutations:" << std::endl;
    std::cout << pelib::vv_str(permutations);
    return 0;
}