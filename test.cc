#include "perm_comb.h"
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << pelib::n_choose_k<int>(100, 1) << std::endl;
    std::cout << pelib::n_choose_k<int>(26, 3) << std::endl;
    std::cout << pelib::n_permute_k<long>(99, 3) << std::endl;
    return 0;
}