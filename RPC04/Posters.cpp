#include <bits/stdc++.h>
using namespace std;

int main(){
    int P, H, T;
    cin >> P >> H >> T;
    int posters = 0;
    if(P > H){
        T -= H;
        posters = T/P;
    }else{
        T -= P;
        posters = T/H;
    }
    cout << posters << endl;
}