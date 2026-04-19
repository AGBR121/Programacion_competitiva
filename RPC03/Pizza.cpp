#include<iostream>
#include<string>

using namespace std;

int main(){
    int numberPizzas = 0;
    int s = 0;
    int m = 0;
    int l = 0;

    cin >> numberPizzas;

    for(int i = 0; i < numberPizzas+1; i++){
        string si = "";
        getline(cin, si);
        if(si[0] == 'S'){
            s += stoi(si.substr(2, si.length() - 1));
        } else if(si[0] == 'M'){
            m += stoi(si.substr(2, si.length() - 1));;
        } else if(si[0] == 'L'){
            l += stoi(si.substr(2, si.length() - 1));;
        }
    }

    int sBoxes = (s+5)/6;
    int mBoxes = (m+11)/12;
    int lBoxes = (l+11)/12;
    cout << sBoxes + mBoxes + lBoxes << endl;

    return 0;
}