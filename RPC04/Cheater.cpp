#include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 0;
    cin >> a;
    cin.ignore();
    while(a--){
        string s;
        getline(cin, s);
        int n = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='.'){
                n += stoi(s.substr(i, 1));
            }
        }
        if(n%3==0 || n%3==1){
            cout << "VALID\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}