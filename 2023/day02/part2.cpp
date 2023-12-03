#include <iostream>
#include <fstream>
#include <sstream>
#include "solutions.h"

int part02() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    int sum = 0;
    std::string line;

    while (std::getline(input, line)) {
        int game_id, nbr_of_cubes, red = 0, green = 0, blue = 0;
        std::string word;

        std::istringstream iss{line};
        iss >> word >> game_id;
        iss.ignore(1);

        while (iss >> nbr_of_cubes) {
            iss >> word;
            if (word.at(0) == 'r')
                red = std::max(red, nbr_of_cubes);
            else if (word.at(0) == 'g')
                green = std::max(green, nbr_of_cubes);
            else if (word.at(0) == 'b')
                blue = std::max(blue, nbr_of_cubes);
        }
        sum += (red * green * blue);
    }
    input.close();
    std::cout << "Part 2 result: " << sum;

    return 0;
}