#include <iostream>

int main(){
    int x,y,w,h;
    std::cin >> x >> y >> w >> h;
    int a[4] = {x, y, w - x, h - y};
    int min = 10000;
    for (int i = 0; i < 4; ++i){
        if (a[i] < min){
            min = a[i];
        }
    }

    std::cout << min << std::endl;
}