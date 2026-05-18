#include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 0;
    cin >> a;
    cin.ignore();
    int max = -1;
    while(a--){
        string s; cin >> s;
        int n = 0;
        if(s[0] == '/'){
            cout << floor(max/10)*10 + 10 << endl;
        }else{
            n = stoi(s);
            if(n > max) max = n;
            cout << n << endl;
        }
    }
    return 0;
}