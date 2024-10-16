#include<iostream>
#include<vector>
#include<algorithm>

template <typename T> std::vector<T> append(const std::vector<T>& first, const std::vector<T>& second) {
    std::vector<T> result;
    for(int i = 0; i < first.size(); i++) {
        result.push_back(first[i]);
    }

    for(int i = 0; i < second.size(); i++) {
        result.push_back(second[i]);
    }
    return result;
}

template <typename T> std::vector<T> unionCustom(const std::vector<T>& first, const std::vector<T>& second) {
    std::vector<T> result;
    for(int i = 0; i < first.size(); i++) {
        if(std::find(result.begin(), result.end(), first[i]) == result.end())
            result.push_back(first[i]);
    }

    for(int i = 0; i < second.size(); i++) {
        if(std::find(result.begin(), result.end(), second[i]) == result.end())
            result.push_back(second[i]);
    }
    return result;
}

template <typename T> std::vector<T> intersection(const std::vector<T>& first, const std::vector<T>& second) {
    std::vector<T> result;
    std::vector<int> addedIndexes;
    for(int i = 0; i < first.size(); i++) {
        int index = 0;
        for(int j = 0; j < second.size(); j++) {
            if(first[i] == second[j] && std::find(addedIndexes.begin(), addedIndexes.end(), j) == addedIndexes.end()) {
                result.push_back(first[i]);
                addedIndexes.push_back(j);
                break;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> first;
    first.push_back(2);
    first.push_back(2);
    first.push_back(2);

    std::vector<int> second;
    second.push_back(2);
    second.push_back(4);
    second.push_back(5);

    std::vector<int> result = intersection<int>(first, second);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
    
    return 0;
}