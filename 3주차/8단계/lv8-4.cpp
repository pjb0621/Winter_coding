#include <iostream>

int main(){
    int a,b,v;
    int day;
    std::cin >> a >> b >> v;
    if ( (v - a) % (a - b) == 0){
        day = (v - a) / (a-b) + 1;
    }
    else{
        day = (v - a) / (a-b) + 2;
    }

    std::cout << day << std::endl;

    return 0;
}