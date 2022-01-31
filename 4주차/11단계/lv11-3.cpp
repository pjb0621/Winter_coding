#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int inf[n][2];
    for (int i = 0; i < n; i++){
        std::cin >> inf[i][0] >> inf[i][1];
    }
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if(inf[i][0] < inf[j][0] && inf[i][1] < inf[j][1] ){
                ++count;
            }
        }
        std::cout << count + 1 << ' ';
    }

    return 0;
}