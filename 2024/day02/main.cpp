#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

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

        bool is_increasing = true;
        bool is_report_safe = true;
        if (numbers.at(0) > numbers.at(1))
            is_increasing = false;

        for (int i = 0; i < numbers.size() - 1; i++) {
            int difference = numbers.at(i + 1) - numbers.at(i);

            if ((difference < 0 && is_increasing) || (difference > 0 && !is_increasing) || std::abs(difference) > 3 || difference == 0) {
                is_report_safe = false;
                break;
            }
        }
        if (is_report_safe) safe_reports_cnt++;
    }
    std::cout << safe_reports_cnt << std::endl;
}