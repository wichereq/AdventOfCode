#include <iostream>
#include <fstream>
#include <cctype>
#include <array>
#include <string>
#include <optional>

const std::array<std::string, 9> string_digits{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

std::optional<int> get_digit(const std::string& str, int index) {
    for(int i = 0; i < 9; i++) {
        std::string substring = str.substr(index, string_digits[i].size());
        if (substring == string_digits[i]) {
            return std::make_optional(i + 1);
        }
    }
    return std::nullopt;
}

std::optional<int> r_get_digit(const std::string& str, int index) {
    for(int i = 0; i < 9; i++) {
        int startPos = index + 1 - string_digits[i].size();
        if (startPos >= 0 && startPos < str.size()) {
            std::string substring = str.substr(startPos, string_digits[i].size());
            if (substring == string_digits[i]) {
                return std::make_optional(i + 1);
            }
        }
    }
    return std::nullopt;
}

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

        // First occurrence of digit
        for (int i = 0; i < line.size(); i++) {
            if(std::isdigit(line[i])) {
                number = line[i];
                break;
            }
            else if(get_digit(line, i).has_value()) {
                number = std::to_string(get_digit(line, i).value());
                break;
            }
        }

        // Last occurrence of digit
        for(int i = line.size() - 1; i >= 0 ; i--) {
            if(std::isdigit(line[i])) {
                number += line[i];
                break;
            }
            else if (r_get_digit(line, i)) {
                number += std::to_string(r_get_digit(line, i).value());
                break;
            }
        }
        sum += std::stoi(number);
    }
    std::cout << "Result: " << sum << '\n';

    return 0;
}
