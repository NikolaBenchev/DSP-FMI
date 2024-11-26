#include<iostream>

unsigned int kittens(const std::string& cards, unsigned int players) {
    int defuses[players] = {0};
    int index = 0; 
    for(const char& c : cards) {
        while(defuses[index] < 0)
            index++;
        if(c == 'S')
            defuses[index] += 1;
        else if(c == 'B')
            defuses[index] -= 1;

        index += 1;
        if(index >= players)
            index = 0;
    }

    return index + 1;
}

int main() {
    std::string cards;
    unsigned int players;

    std::cin >> cards >> players;
    std::cout << kittens(cards, players) << std::endl;
    return 0;
}