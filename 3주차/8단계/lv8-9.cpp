#include <iostream>

int main(){
    int T,x,y,distance,num;
    std::cin >> T;
    for (int i = 0; i < T; i++){
        long long sum = 0;
        num =  0;
        long long temp  =  0;
        std::cin >> x >> y;
        distance = y - x;
        float mid = distance / 2.0;
        while(mid >= sum){
            temp++;
            num ++;
            sum = ((temp + 1) * (temp)) / 2;
        }
        sum -= temp;
        if (sum == mid){
            std::cout << (num - 1) * 2 << std::endl;
        }
        else if ((mid - sum) * 2 <= temp ){
            std::cout << (num - 1) * 2 + 1 <<std::endl;
        }

        else{
            std::cout << (num - 1) * 2 + 2 << std::endl;
        }
    
    }

    return 0;
}