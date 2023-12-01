#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    int sum = 0;
    std::string line;
    while (input >> line) {
        std::string number;
        for (int i = 0; i < line.size(); i++) {
            if(std::isdigit(line[i])) {
                number = line[i];
                break;
            }
        }

        for(int i = line.size() - 1; i >= 0 ; i--) {
            if(std::isdigit(line[i])) {
                number += line[i];
                break;
            }
        }

        sum += std::stoi(number);
    }

    std::cout << "Result: " << sum << '\n';

    return 0;
}
