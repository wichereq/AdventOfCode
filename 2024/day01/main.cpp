#include <iostream>
#include <fstream>
#include <sstream>
#include "solutions.h"

int main() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    std::list<int> left_list;
    std::list<int> right_list;

    std::string line;
    while (std::getline(input, line)) {
        int left_num, right_num;

        std::istringstream iss{line};
        iss >> left_num >> right_num;

        left_list.push_back(left_num);
        right_list.push_back(right_num);
    }

    left_list.sort();
    right_list.sort();

    std::cout << "Part 1 solution: " << part01(left_list, right_list) << '\n';
    std::cout << "Part 2 solution: " << part02(left_list, right_list) << '\n';

    return 0;
}