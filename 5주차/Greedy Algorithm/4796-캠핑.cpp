#include <iostream>

int main(){
    int l,p,v;
    int ans;
    int i = 1;
    while(true){
        ans = 0;
        std::cin >> l >> p >> v;
        if(!l && !p && !v){
            break;
        }
        ans += (v / p) * l;
        if(v % p >= l){
            ans += l;
        } 
        else{ ans += v % p; }
        std::cout << "Case " << i << ":" << " " << ans << '\n';
        i++;
    }

    return 0;
}