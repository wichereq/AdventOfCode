#include "solutions.h"

int part02(const std::list<int>& left_list, const std::list<int>& right_list) {
    int similarity_score = 0;
    for (const auto number : left_list) {
        const int count = std::ranges::count(right_list, number);
        similarity_score += number * count;
    }
    return similarity_score;
}
