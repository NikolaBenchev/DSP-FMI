#include<iostream>
#include<queue>
#include<map>

int main() {
    std::map<char, bool> m;
    std::queue<char> q;
    while(true) {
        char a;
        std::cin >> a;
        if(a == '0') break;

        q.push(a);
        if(m.find(a) == m.end())
            m.insert({a, false});
        else
            m[a] = true;
        
        char front = q.front();
        while(!q.empty() && m[front]) {
            q.pop();
            front = q.front();
        }

        if(q.empty())
            std::cout << "out: " << -1 << std::endl;
        else
            std::cout << "out: " << front << std::endl;
    }

    return 0;
}