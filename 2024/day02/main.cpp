#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

bool is_safe(const std::vector<int>& numbers) {
    if (numbers.size() < 2) {
        return true;
    }
    const bool is_increasing = numbers.at(0) <= numbers.at(1);
    for (int i = 0; i < numbers.size() - 1; i++) {
        int difference = numbers.at(i + 1) - numbers.at(i);
        if ((is_increasing && difference < 0) || (!is_increasing && difference > 0) || std::abs(difference) > 3 || difference == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream input("input.txt", std::ifstream::in);
    if (!input) {
        std::cerr << "Can't open 'input.txt' file!\n";
        return 1;
    }

    int safe_reports_cnt = 0;
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::vector<int> numbers;
        int number;

        while (iss >> number) {
            numbers.push_back(number);
        }

        bool is_report_safe = is_safe(numbers);

        if (!is_report_safe) {
            for (int i = 0; i < numbers.size(); i++) {
                std::vector<int> modified_numbers = numbers;
                modified_numbers.erase(modified_numbers.begin() + i);
                if (is_safe(modified_numbers)) {
                    is_report_safe = true;
                    break;
                }
            }
        }
        if (is_report_safe) safe_reports_cnt++;
    }

    std::cout << "Total Safe Reports: " << safe_reports_cnt << std::endl;
    return 0;
}