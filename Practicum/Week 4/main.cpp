#include<iostream>

struct Position {
    int x, y, distance;
};

int getShortestPath(Position startPos, Position endPos, int n) {
    
    auto getShortestPath = []() -> int {

    };
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