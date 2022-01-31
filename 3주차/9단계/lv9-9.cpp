#include <iostream>

int main(){
    int len[3];
    int index;
    while(1){
        int max = 0;
        std::cin >> len[0] >> len[1] >> len[2];
        if(!len[0] || !len[1] || !len[2]){
            return 0;
        }
        for (int i = 0; i < 3; i++){
           if(len[i] > max){
                max = len[i];
               index = i;
            }
        }
        len[index] = len[2];
        len[2] = max;
        if(max * max == len[0] * len[0]+ len[1] * len[1]){
            std::cout << "right" << '\n';
        }
        else{
           std::cout << "wrong" << '\n';
        }
    }
}