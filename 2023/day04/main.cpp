#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

int part1() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    int sum = 0;
    std::string line;

    while(std::getline(input, line)) {
        std::string word;
        int game_id;

        std::istringstream iss{line};
        iss >> word >> game_id;
        iss.ignore(1);

        std::string winning_numbers_str;
        std::getline(iss, winning_numbers_str, '|');
        std::istringstream iss2(winning_numbers_str);
        std::vector<int> winning_numbers_vec;

        int num;
        while (iss2 >> num) {
            winning_numbers_vec.emplace_back(num);
        }

        std::string my_numbers_str;
        std::getline(iss, my_numbers_str);
        std::istringstream iss3(my_numbers_str);
        std::vector<int> my_numbers_vec;

        while (iss3 >> num) {
            my_numbers_vec.emplace_back(num);
        }

        // Sort both vectors for efficient comparison
        std::sort(winning_numbers_vec.begin(), winning_numbers_vec.end());
        std::sort(my_numbers_vec.begin(), my_numbers_vec.end());

        // Count the number of matching elements
        int number_of_wins = std::set_intersection(winning_numbers_vec.begin(), winning_numbers_vec.end(),
                                                 my_numbers_vec.begin(), my_numbers_vec.end(),
                                                 my_numbers_vec.begin()) - my_numbers_vec.begin();

        sum += static_cast<int>(std::pow(2, number_of_wins - 1));
    }
    return sum;
}

int main() {
    std::cout << "The result of part 1: " << part1() << '\n';

    return 0;
}
