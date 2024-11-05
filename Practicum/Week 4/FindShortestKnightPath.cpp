#include<iostream>
#include<queue>

struct Position {
    int x, y, distance;
    bool operator==(const Position& other){
        return (this->x == other.x && this->y == other.y);
    }
};

int getShortestPath (Position currPos, Position endPos, std::queue<Position> nextSteps, const int boardSize, bool isVisited[][10]) {
        if(currPos.x < 0 || currPos.y < 0 || currPos.x >= boardSize || currPos.y >= boardSize)
            return -1;
        if(isVisited[currPos.x][currPos.y])
            return -1;
        if(currPos == endPos)
            return currPos.distance;

        isVisited[currPos.x][currPos.y] = true;

        nextSteps.push(Position{currPos.x + 2, currPos.y + 1, currPos.distance + 1});
        nextSteps.push(Position{currPos.x + 2, currPos.y - 1, currPos.distance + 1});
        nextSteps.push(Position{currPos.x + 1, currPos.y + 2, currPos.distance + 1});
        nextSteps.push(Position{currPos.x + 1, currPos.y - 2, currPos.distance + 1});
        nextSteps.push(Position{currPos.x - 1, currPos.y + 2, currPos.distance + 1});
        nextSteps.push(Position{currPos.x - 1, currPos.y - 2, currPos.distance + 1});
        nextSteps.push(Position{currPos.x - 2, currPos.y + 1, currPos.distance + 1});
        nextSteps.push(Position{currPos.x - 2, currPos.y - 1, currPos.distance + 1});

        while(!nextSteps.empty()) {
            int distance = getShortestPath(nextSteps.front(), endPos, nextSteps, boardSize, isVisited);
            if(distance != -1)
                return distance;
            nextSteps.pop();
        }
        return -1;
    };

int getShortestPath(Position startPos, Position endPos, const int boardSize) {
    bool isVisited[10][10] = {false};
    return getShortestPath(startPos, endPos, std::queue<Position>{}, boardSize, isVisited);
}

int main() {
    int n, startX, startY, endX, endY;
    std::cin >> n >> startX >> startY >> endX >> endY;
    // Position startPos;
    // startPos.x = startX;
    // startPos.y = startY;
    // startPos.distance = 0;
    std::cout << getShortestPath(Position{startX, startY, 0}, Position{endX, endY, -1}, n);
    return 0;
}
