#include<iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 0;
    int a = 0;

    for(int i=0; i<n; i++){
        cin >> a;
        if(a % 2 == 1){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}