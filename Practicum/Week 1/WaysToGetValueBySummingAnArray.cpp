#include<iostream>
#include<vector>

void pr(std::vector<int> addedNums) {
    for(int i = 0; i < addedNums.size(); i++) {
        std::cout << addedNums[i] << " ";
    }
    std::cout << std::endl;
}

void printSums(int currIndex, int value, std::vector<int> addedNums, int arr[], int size) {
    if(value < 0 || currIndex >= size)
        return;
    if(value == 0) {
        pr(addedNums);
        return;
    }
    addedNums.push_back(arr[currIndex]);
    printSums(currIndex, value - arr[currIndex], addedNums, arr, size);
    addedNums.pop_back();
    printSums(currIndex + 1, value, addedNums, arr, size);
}

void printSums(int value, int arr[], int size) {
    printSums(0, value, {}, arr, size);
}

int main() {
    //* value ?= arr
    int value, size;
    std::cin >> value >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    printSums(value, arr, size);
    return 0;
}