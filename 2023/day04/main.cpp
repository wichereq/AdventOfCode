#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <array>
#include <numeric>

std::pair<int, std::vector<int>> part1() {
    std::ifstream input("input.txt", std::ifstream::in);

    int sum = 0;
    std::string line;
    std::vector<int> cards_wins_vec; // Needed only for Part 1

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

        cards_wins_vec.emplace_back(number_of_wins); // Needed only for Part 2
        sum += static_cast<int>(std::pow(2, number_of_wins - 1));
    }
    return std::make_pair(sum, cards_wins_vec);
}

int part2(const std::vector<int>& cards_wins_vec) {
    if(cards_wins_vec.empty())
        return 1;

    std::vector<int> cards_copies = std::vector<int>(cards_wins_vec.size(), 1);

    for(int i = 0; i < cards_copies.size(); i++) {
        for(int j = 0; j < cards_copies[i]; j++) {
            int nbr_of_wins = cards_wins_vec[i];
            for(int k = i + 1; k < i  + 1 + nbr_of_wins; k++) {
                cards_copies[k]++;
            }
        }
    }
    return std::accumulate(cards_copies.begin(), cards_copies.end(), 0);
}

int main() {
    std::cout << "The result of part 1: " << part1().first << '\n';
    std::cout << "The result of part 2: " << part2(part1().second) << '\n';

    return 0;
}
