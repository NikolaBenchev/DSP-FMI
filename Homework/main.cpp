#include<iostream>
#include<stack>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<queue>
#include<vector>
#include<algorithm>

struct Pos{
    int x, y;
};

struct BoardState {
    int numberOfStudents;
    std::stack<Pos> studentPositions;
};

struct Student {
    int facultyNumber, startTime, timeNeeded;
};

void printBoard(char** board, int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

char** setBoard(std::stack<Pos> takenSeats, char** board, int N, int M) {
    char** newBoard = new char*[N];
    for(int i = 0; i < N; i++) {
        newBoard[i] = new char[M];
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'B')
                newBoard[i][j] = 'B';
            else
                newBoard[i][j] = 'F';
        }
    }

    while(!takenSeats.empty()) {
        Pos currSeat = takenSeats.top();
        for(int i = -1; i < 2; i++) {
            int y = currSeat.y + i;
            if(y < 0 || y >= N)
                continue;
            for(int j = -1; j < 2; j++) {
                int x = currSeat.x + j;
                if(x < 0 || x >= M)
                    continue;
                newBoard[y][x] = 'O';
            }
        }
        takenSeats.pop();
    }

    return newBoard;
}

BoardState findOptimalDistribution(int x, int y, BoardState currBoardState, char** board, int N, int M) {
    currBoardState.numberOfStudents += 1;
    currBoardState.studentPositions.push(Pos{x, y});
    
    char** currBoard = setBoard(currBoardState.studentPositions, board, N, M);
    BoardState optBoardState = currBoardState;
    for(int i = y; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(currBoard[i][j] != 'F')
                continue;

            BoardState newBoardState = findOptimalDistribution(j, i, currBoardState, currBoard, N, M);
            if(optBoardState.numberOfStudents < newBoardState.numberOfStudents)
                optBoardState = newBoardState;
        }
    }

    delete[] currBoard;

    return optBoardState;
}


std::stack<Pos> findOptimalDistribution(char** board, int N, int M) {
    BoardState optBoardState = BoardState{0, std::stack<Pos>()};

    Pos startingPosition = Pos{-1, -1};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] != 'F')
                continue;
            startingPosition = Pos{i, j};
            break;
        }
        if(startingPosition.x != -1)
            break;
    }

    for(int y = startingPosition.y - 1; y < startingPosition.y + 1; y++) {
        if(y < 0 || y >= N)
            continue;
        for(int x = startingPosition.x - 1; x < startingPosition.x + 1; x++) {
            if(x < 0 || x >= M)
                continue;
            if(board[y][x] != 'F')
                continue;
            BoardState newBoardState = findOptimalDistribution(x, y, BoardState{0, std::stack<Pos>()}, board, N, M);
            if(optBoardState.numberOfStudents < newBoardState.numberOfStudents)
                optBoardState = newBoardState;
        }
    }

    return optBoardState.studentPositions;
}

int main() {
    int N, M, teacherArrivalTime, revisionTime;
    std::ifstream input;
    input.open("input.txt");
    input >> N >> M >> teacherArrivalTime >> revisionTime;

    char** board = new char*[N];

    for(int i = 0; i < N; i++) {
        board[i] = new char[M];
        for(int j = 0; j < M; j++) {
            board[i][j] = 'F';
        }
    }

    int B;
    input >> B;
    
    for(int i = 0; i < B; i++) {
        int brokenSeatNumber;
        input >> brokenSeatNumber;
        brokenSeatNumber -= 1;
        int x = brokenSeatNumber % M,
            y = brokenSeatNumber / N;

        board[y][x] = 'B';
    }

    std::stack<Pos> optStudentPositions = findOptimalDistribution(board, N, M);
    std::queue<Student> waitingStudents[3];
    std::stack<int> examsToGrade, gradedExams;
    std::vector<Student> writingStudents;

    std::string line;
    
    while(std::getline(input, line)) {
        int currTime, facultyNumber, timeNeeded, studentYear;
        char* stringParts = strtok(line.data(), " ");

        if(line == "end")
            break;

        for(int i = 0; stringParts != NULL; i++) {
            switch(i) {
                case 1:
                    currTime = std::stoi(stringParts);
                    break;
                case 2:
                    facultyNumber = std::stoi(stringParts);
                    break;
                case 3:
                    timeNeeded = std::stoi(stringParts);
                    break;
                case 4:
                    //? kurs: 2 -> 0, 3 -> 1, 4 -> 2
                    studentYear = std::stoi(stringParts) - 2;
                    break;
                default:
                    break;
            }
            stringParts = strtok(NULL, " ");   
        }

        waitingStudents[studentYear].push(Student{facultyNumber, currTime, timeNeeded});

        for(std::vector<Student>::iterator it = writingStudents.begin(); it != writingStudents.end(); it++) {
            if(teacherArrivalTime + gradedExams.size() * revisionTime < currTime && !examsToGrade.empty()) {
                gradedExams.push(examsToGrade.top());
                examsToGrade.pop();
            }
            if(it->startTime + it->timeNeeded >= currTime)
                break;
            examsToGrade.push(it->facultyNumber);
            writingStudents.erase(it);
        }

        for(int i = 2; i >= 0 && writingStudents.size() < optStudentPositions.size(); i--) {
            while(!waitingStudents[i].empty() && writingStudents.size() < optStudentPositions.size()) {
                if(waitingStudents[i].front().startTime < currTime)
                    waitingStudents[i].front().startTime = currTime;

                writingStudents.push_back(waitingStudents[i].front());
                waitingStudents[i].pop();

                int currIndex = writingStudents.size() - 1;
                while(
                    currIndex != 0 && 
                    writingStudents[currIndex].startTime + writingStudents[currIndex].timeNeeded < 
                    writingStudents[currIndex - 1].startTime + writingStudents[currIndex - 1].timeNeeded
                ) {
                    Student temp = writingStudents[currIndex];
                    writingStudents[currIndex] = writingStudents[currIndex - 1];
                    writingStudents[currIndex - 1] = temp;
                    currIndex -= 1;
                }
            }
        }

        delete stringParts;
    }

    while(!writingStudents.empty()) {
        std::vector<Student>::iterator it = writingStudents.begin();
        int currTime = it->startTime + it->timeNeeded;
        if(teacherArrivalTime + gradedExams.size() * revisionTime < currTime) {
            gradedExams.push(examsToGrade.top());
            examsToGrade.pop();
        }

        examsToGrade.push(it->facultyNumber);
        writingStudents.erase(it);

        for(int i = 2; i >= 0 && writingStudents.size() < optStudentPositions.size(); i--) {
            while(!waitingStudents[i].empty() && writingStudents.size() < optStudentPositions.size()) {
                writingStudents.push_back(waitingStudents[i].front());
                int currIndex = writingStudents.size() - 1;
                while(
                    currIndex != 0 && 
                    writingStudents[currIndex].startTime + writingStudents[currIndex].timeNeeded < 
                    writingStudents[currIndex - 1].startTime + writingStudents[currIndex - 1].timeNeeded
                ) {
                    Student temp = writingStudents[currIndex];
                    writingStudents[currIndex] = writingStudents[currIndex - 1];
                    writingStudents[currIndex - 1] = temp;
                    currIndex -= 1;
                }
                waitingStudents[i].pop();
            }
        }
    }

    while(!optStudentPositions.empty()) {
        Pos currPos = optStudentPositions.top();
        optStudentPositions.pop();
        board[currPos.y][currPos.x] = 'O';
    }

    printBoard(board, N, M);

    while(!examsToGrade.empty()) {
        gradedExams.push(examsToGrade.top());
        examsToGrade.pop();
    }

    while(!gradedExams.empty()) {
        std::cout << gradedExams.top() << std::endl;
        gradedExams.pop();
    }

    delete[] board;
    input.close();

    return 0;
}