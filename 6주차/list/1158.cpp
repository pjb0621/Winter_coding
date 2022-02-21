#include <iostream>
#include <vector>

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> vec;
    for (int i = 0; i < n; i++){
        vec.push_back(i + 1);
    }
    int i = k - 1;
    std::cout << "<";
    while(n){
        if(n == 1){
            std::cout << vec[0];
            break;
        }
        if(i < n){
            std::cout << vec[i] << ", ";
            vec.erase(vec.begin() + i);
            n = n - 1;
        }
        else{
            i = i % n;
            std::cout << vec[i] << ", ";
            vec.erase(vec.begin() + i);
            n = n - 1;
        }
        i += k - 1;
    }
    std::cout << ">";

    return 0;
}