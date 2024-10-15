#include<iostream>

const int maxN = 8;
bool foundPath = false;



void printBoard(int arr[maxN][maxN]) {
    for(int i = 0; i < maxN; i++) {
        for(int j = 0; j < maxN; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void searchBoard(int x, int y, int numberOfSteps, int arr[maxN][maxN]) {
    if(foundPath)
        return;
    if(x < 0 || y < 0 || x >= maxN || y >= maxN)
        return;
    if(arr[y][x] != 0)
        return;
    
    arr[y][x] = numberOfSteps;
    if(numberOfSteps == maxN * maxN) {
        printBoard(arr);
        foundPath = true;
        return;
    }

    searchBoard(x - 1, y - 2, numberOfSteps + 1, arr);
    searchBoard(x - 1, y + 2, numberOfSteps + 1, arr);
    searchBoard(x + 1, y - 2, numberOfSteps + 1, arr);
    searchBoard(x + 1, y + 2, numberOfSteps + 1, arr);
    searchBoard(x - 2, y - 1, numberOfSteps + 1, arr);
    searchBoard(x - 2, y + 1, numberOfSteps + 1, arr);
    searchBoard(x + 2, y - 1, numberOfSteps + 1, arr);
    searchBoard(x + 2, y + 1, numberOfSteps + 1, arr);
    if(!foundPath)
        arr[y][x] = 0;
}

void searchBoard(int x, int y) {
    int arr[maxN][maxN] = {{0}};
    searchBoard(x, y, 1, arr);
}

int main() {
    //* Horse path
    searchBoard(0, 0);
    return 0;
}