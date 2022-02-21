#include <iostream>
#include <string>
//string ���� insert�� �ð����⵵�� O(n)�̶� insert�� �����ϴ� �� �Լ������� ��︮�� ���� ���� insert�� �ð����⵵�� O(1)�� ���� list�� �����(1406.cpp)//
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