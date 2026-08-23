#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0; cin >> n;
    
    set<int> intercepts;
    
    double minor = 100000;
    bool valid = 0;
    
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2, b = 0, m = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        
        m = (y2 - y1)/(x2 - x1);
        b = (y1 - m*x1);
        
        if (b < minor && b > 0 && (((x1 >= 0 && x2<= 0) || (x1 <= 0 && x2 >= 0) && (y1 >= 0 || y2 >= 0)))){
            valid = 1;
            minor = b;
        }
    }
    
    if(minor != 100000 && valid) cout << minor << endl;
    else cout << -1.0 << endl;
    
    
    return 0;
}