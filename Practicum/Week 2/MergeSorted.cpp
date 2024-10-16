#include<iostream>
#include<vector>

std::vector<int> mergeSorted(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> result;
    int firstIndex = 0, secondIndex = 0;
    while(firstIndex < first.size() || secondIndex < second.size()) {
        if(firstIndex == first.size()) {
            result.push_back(second[secondIndex]);
            secondIndex += 1;
            continue;
        }

        if(secondIndex == second.size()) {
            result.push_back(first[firstIndex]);
            firstIndex += 1;
            continue;
        }

        if(first[firstIndex] < second[secondIndex]) {
            result.push_back(first[firstIndex]);
            firstIndex += 1;
        } else {
            result.push_back(second[secondIndex]);
            secondIndex += 1;
        }
    }
    return result;
}

int main () {
    std::vector<int> first;
    first.push_back(1);
    first.push_back(1);
    first.push_back(1);
    first.push_back(1);
    first.push_back(13);
    first.push_back(17);
    std::vector<int> second;
    second.push_back(3);
    second.push_back(3);
    second.push_back(3);
    second.push_back(3);
    second.push_back(3);
    second.push_back(3);
    second.push_back(30);
    second.push_back(33);
    std::vector<int> result = mergeSorted(first, second);

    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}