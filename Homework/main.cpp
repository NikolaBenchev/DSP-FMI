#include<iostream>

void printBoard(char** board, int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}



int main() {
    int N, M, teacherArrivalTime, revisionTime;
    std::cin >> N >> M >> teacherArrivalTime >> revisionTime;
    char** board = new char*[N];

    for(int i = 0; i < N; i++) {
        board[i] = new char[M];
        for(int j = 0; j < M; j++) {
            board[i][j] = 'O';
        }
    }

    int B;
    std::cin >> B;
    for(int i = 0; i < B; i++) {
        int brokenSeatNumber;
        std::cin >> brokenSeatNumber;
        brokenSeatNumber -= 1;
        int x = brokenSeatNumber % M,
            y = brokenSeatNumber / N;

        board[y][x] = 'B';
    }

    printBoard(board, N, M);

    return 0;
}