#include <iostream>

/*
2단계 시험성적 문제
https://www.acmicpc.net/problem/9498
*/

int main (){

    int score;
    std::cin >> score;
    switch(score/10){
        case 10: std::cout << "A" << std::endl; break;
        case 9: std::cout << "A" << std::endl; break;
        case 8 :std::cout << "B" << std::endl; break;
        case 7 : std::cout << "C" << std::endl; break;
        case 6: std::cout << "D" << std::endl; break;
        default:
        std::cout << "F" << std::endl;
        break;
    }
}


