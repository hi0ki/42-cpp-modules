#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>



class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(int ac, char *av[]);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        // Utils
            void start();
};
