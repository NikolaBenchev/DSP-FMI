#include<iostream>

int printMaximumPath(int currValue, int maxValue, int cellIndex, int rowIndex, int** arr, int n) {
    if(currValue > maxValue)
        maxValue = currValue;

    if(cellIndex >= n || rowIndex >= n) {
        return maxValue;
    }

    currValue += arr[rowIndex][cellIndex];
    int valueStraight = printMaximumPath(currValue, maxValue, cellIndex, rowIndex + 1, arr, n),
        valueDiagonal = printMaximumPath(currValue, maxValue, cellIndex + 1, rowIndex + 1, arr, n);
    return std::max(valueStraight, valueDiagonal);
}

void printMaximumPath(int n, int** arr) {
    std::cout << printMaximumPath(0, 0, 0, 0, arr, n) << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int** arr;
    arr = new int *[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[i];
        for(int j = 0; j < i + 1; j++) {
            std::cin >> arr[i][j];
        }
    }

    printMaximumPath(n, arr);
    return 0;
}

/*
    // count: 0 -> n
    cellIndex: 0 -> n
    rowIndex: 0 -> n
*/