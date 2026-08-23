#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0; cin >> n;
    vector<int> numbers(50, 0);

    for (int i = 0; i < n*10; i++) {
        for (int i = 0; i < 5; i++) {
            int num; cin >> num; 
            numbers[num-1]++;
        }
    }

    int cont = 0;
    vector<int> sols;
    for (int i = 0; i < 50; i++) {
        if(numbers[i] > 2*n){
            cont++;
            sols.push_back(i+1);
        }
    }

    if(!cont) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < sols.size()-1; i++) {
        cout << sols[i] << " ";
    }

    cout << sols[sols.size()-1];
    cout << endl;

    return 0;
}

