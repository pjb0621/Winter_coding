#include <iostream>

int recurcount(int n, int count){
    if(n == 1){
        count++;
        return count;
    }
    count = 2 * recurcount(n - 1, count) + 1;
    return count;
}

void recurhanoy(int n, int count, int now, int to){
    if(n == 1){
        std::cout << now << ' ' << to << '\n';
        return;
    }
    int tempto = 6 - (now + to);
    
    recurhanoy(n - 1, count, now, tempto);
    std::cout << now << ' ' << to << '\n';
    recurhanoy(n - 1, count, tempto, to);
}

int main(){
    int n; 
    int count = 0;
    int to = 3;
    int now = 1;
    std::cin >> n;
    std::cout << recurcount(n, count) << '\n';
    recurhanoy(n, count, now, to);
}