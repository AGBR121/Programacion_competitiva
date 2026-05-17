#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool found = false;
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='k' && s[i+1]=='t' && s[i+2]=='h'){
            found = true;
            break;
        }
    }
    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}