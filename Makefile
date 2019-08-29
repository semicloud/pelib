test.out: test.cc perm_comb.h
	g++ -std=c++0x -Wall test.cc  -o test.out