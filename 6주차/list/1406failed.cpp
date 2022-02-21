#include <iostream>
#include <string>
//string 에서 insert의 시간복잡도는 O(n)이라서 insert를 많이하는 이 함수에서는 어울리지 않음 따라서 insert의 시간복잡도가 O(1)인 연결 list를 사용함(1406.cpp)//
int main(){
    std::string s;
    int n;
    std::cin >> s >> n;
    int index = s.size();
    for (int i = 0; i < n; i++){
        char input;
        std::cin >> input;
        if(input == 'P'){
            char inp;
            std::cin >> inp;
            s.insert(s.begin() + index, inp);
            index++;
        }
        else if(input == 'L'){
            if(index != 0){
                index--;
            }
        }
        else if(input == 'D'){
            if(index != s.size()){
                index++;
            }
        }
        else if(input == 'B'){
            if(index != 0 && s.size()){
                s.erase(index - 1, 1);
                index--;
            }
        }
    }

    std::cout << s << std::endl;
}