#include <iostream>

int main(){
    int input;
    std::cin >> input;
    int n = 1;
    int count = 1;
    int ans = 0;
    int key = 0;
    while(true){
        int a = 1;
        int b = n;
        for (int i = 1;  i <= n; i++){
            if(input == count){
                if (key == 1){
                    std::cout << i << '/' << n - i + 1 << std::endl;
                    
                    return 0;
                }
                else if(key == 0){
                    std::cout << n - i + 1 << '/' << i << std::endl;
                    

                    return 0;
                }
            }
            count++;
        }
        if(key == 0){
            key = 1;
        }
        else {
            key = 0;
        }
        n++;
    }   

    return 0;
}