#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0; cin >> n;

    set<string> cosas_in;
    set<string> deleted;
    bool valid = 1;

    for (int i = 0; i < n; i++) {
        string in; cin >> in;
        string cosa; cin >> cosa;
        if(in == "pickup"){
            if(cosas_in.contains(cosa) || deleted.contains(cosa)){
                valid = 0;
                break;
            }
            cosas_in.insert(cosa);
        }else{
            if(cosas_in.contains(cosa)){
                cosas_in.erase(cosa);
                deleted.insert(cosa);
            }else{
                valid = 0;
                break;
            }
        }
    }



    if(cosas_in.size() != 0 || !valid){
        cout << "no" << endl;
    }else{
        cout << "yes" << endl;
    }

    return 0;
}
