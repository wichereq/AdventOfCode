#include "solutions.h"
#include <numeric>
#include <cmath>

int part01(const std::list<int>& left_list, const std::list<int>& right_list) {
    std::list<int> distances;
    auto it1 = left_list.begin();
    auto it2 = right_list.begin();

    for (; it1 != left_list.end() && it2 != right_list.end(); ++it1, ++it2) {
        distances.push_back(std::abs(*it1 - *it2));
    }
    return std::accumulate(distances.begin(), distances.end(), 0);
}
