#include <iostream>
#include <cmath>

int main(){
    int T,x1,y1,r1,x2,y2,r2;
    std::cin >> T;
    for(int i = 0; i < T; i++){
        float distance;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        distance = pow(pow(x1 - x2, 2) + pow(y1 - y2,2), 0.5);
        if(x1 == x2 && y1 == y2 && r1 == r2){
            std::cout << -1 << '\n';
        }
        else if(r1 + r2 > distance){
            if(r1 + distance == r2|| r2 +distance == r1){
                std::cout << 1 << '\n';
            }
            else if(r2 + distance < r1 || r1 + distance < r2){
                std::cout << 0 << '\n';
            }
            else std::cout << 2 << '\n';
        }
        else if(r1 + r2 == distance){
            std::cout << 1 << '\n';

        }
        else{
            std::cout << 0 << '\n';
        }
    }
}