#include <iostream>
#include <fstream>
#include <sstream>
#include "solutions.h"

int part01() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    int sum = 0;
    std::string line;

    while(std::getline(input, line)) {
        int game_id, nbr_of_cubes;
        std::string word;

        std::istringstream iss{line};
        iss >> word >> game_id;
        iss.ignore(1);

        bool is_possible = true;

        while(iss >> nbr_of_cubes) {
            iss >> word;
            if ((word.at(0) == 'r' && nbr_of_cubes > 12) ||     // Red
                (word.at(0) == 'g' && nbr_of_cubes > 13) ||        // Green
                (word.at(0) == 'b' && nbr_of_cubes > 14)) {        // Blue
                is_possible = false;
                break;
            }
        }
        if(is_possible)
            sum += game_id;
    }
    input.close();
    std::cout << "Part 1 result: " << sum << '\n';

    return 0;
}
