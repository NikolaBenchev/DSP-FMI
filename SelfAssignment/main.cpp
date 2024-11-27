#include<iostream>
#include "Vector.hpp"

int main() {
    Vector<int> v;
    v.push(13);
    v.push(1);
    std::cout << v[1] << std::endl;

    v.push(24);
    v.pop();
    v.pop();
    std::cout << v.size() << std::endl;
    return 0;
}
/*
    Направи собствена структура от данни, която да поддържа полиморфен тип.
    Да може да се въвежда и извежда със stream-ове и да има сереализация във файл
*/ 