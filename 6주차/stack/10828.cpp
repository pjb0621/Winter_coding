#include <iostream>
#include <list>
#include <string>

int main(){
    int n;
    std::string s;
    std::list<int> lst;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> s;
        if(s == "push"){
            int input;
            std::cin >> input;
            lst.push_back(input);
        }
        else if(s == "pop"){
            if(!lst.size()){
                std::cout << -1 << '\n';
                continue;
            }
            std::cout << lst.back() << '\n';
            lst.pop_back();
        }
        else if(s == "size"){
            std::cout << lst.size() << '\n';
        }
        else if(s == "empty"){
            if(lst.size()){
                std::cout << 0 << '\n';
            }
            else{
                std::cout << 1 << '\n';
            }
        }
        else if(s == "top"){
            if(lst.size()){
                std::cout << lst.back() << '\n';
            }
            else{
                std::cout << -1 << '\n';
            }
        }
    }
}