#include <iostream>
#include <string>

std::string arr[100];
int memoziation[100]; //i번째 인덱스부터 채울 수 있는가?//

int canmake(int n, std::string str,int index){
    if(memoziation[index] != -1){
        return memoziation[index];
    }
    if(index ==int(str.length())){
        return 1;
    }
    for (int i = 0; i < n; i++){
        if(int(str.find(arr[i], index)) == index){ //아 여기서 find(str, pos) 안쓰고 그냥 find(str)썻다가 계속 틀림//
            if(canmake(n, str, index + arr[i].length())){
                memoziation[index + arr[i].length()] = 1;
                return 1;
            };
        }
    }
    memoziation[index] = 0;
    return 0;
}

int main(){
    int n;
    std::string str1;
    std::cin >> str1;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for (int i = 0; i < 100; i++){
        memoziation[i] = -1;
    }
    std::cout << canmake(n, str1, 0) << std::endl;
}