#include <iostream>
#include <list>
#include <string>

int main(){
    std::list<char> lst;
    std::string input;
    std::cin >> input;
    int n;
    char in;
    for(int i = 0; i < input.size(); i++){
        lst.push_back(input[i]);
    }
    std::list<char>::iterator itr = lst.end();
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> in;
        if(in == 'P'){
            char temp;
            std::cin >> temp;
            lst.insert(itr, temp);
        }
        else if(in == 'L'){
            if(itr != lst.begin()){
                itr--;
            }
        }
        else if(in == 'D'){
            if(itr != lst.end()){
                itr++;
            }
        }
        else if(in == 'B'){
            if(itr != lst.begin()){
                if(itr == lst.end()){
                    lst.pop_back();
                }
                else{
                    itr--;
                    itr = lst.erase(itr);
                }

            }
        }
    }

    for (const auto& elem : lst) {
    std::cout << elem;
    }

    
    return 0;
}