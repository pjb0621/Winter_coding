#include <iostream>
#include <string>

std::string arr[100];
int memoziation[100]; //i��° �ε������� ä�� �� �ִ°�?//

int canmake(int n, std::string str,int index){
    if(memoziation[index] != -1){
        return memoziation[index];
    }
    if(index ==int(str.length())){
        return 1;
    }
    for (int i = 0; i < n; i++){
        if(int(str.find(arr[i], index)) == index){ //�� ���⼭ find(str, pos) �Ⱦ��� �׳� find(str)���ٰ� ��� Ʋ��//
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