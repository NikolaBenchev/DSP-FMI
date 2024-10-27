#include<iostream>
#include<stack>
#include<vector>
#include<cmath>

std::stack<int> asteroidCollision(std::vector<int>& asteroids) {
    std::stack<int> leftoverAsteroids;
    for(int curr : asteroids) {
        if(leftoverAsteroids.empty()) {
            leftoverAsteroids.push(curr);
        }else if(leftoverAsteroids.top() * curr > 0 || leftoverAsteroids.top() < 0) {
            leftoverAsteroids.push(curr);
        }
        else {
            while(!leftoverAsteroids.empty()) {
                if(leftoverAsteroids.top() * curr > 0) {
                    leftoverAsteroids.push(curr);
                    break;
                }
                
                if(fabs(leftoverAsteroids.top()) < fabs(curr)) {
                    leftoverAsteroids.pop();
                    if(leftoverAsteroids.empty()) {
                        leftoverAsteroids.push(curr);
                        break;
                    }
                }
                else if(fabs(leftoverAsteroids.top()) == fabs(curr)) {
                    leftoverAsteroids.pop();
                    break;
                } else {
                    break;
                }
            }
        }
    }

    return leftoverAsteroids;
}

std::stack<int> reverse(std::stack<int> st) {
    std::stack<int> reverseSt;
    while(!st.empty()) {
        int curr = st.top();
        reverseSt.push(curr);
        st.pop();
    }

    return reverseSt;
}

int main() {
    std::vector<int> asteroids;

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int curr;
        std::cin >> curr;
        asteroids.push_back(curr);
    }

    std::stack<int> result = reverse(asteroidCollision(asteroids));

    while(!result.empty()) {
        std::cout << result.top() << " ";
        result.pop();
    }
    std::cout << std::endl;
}