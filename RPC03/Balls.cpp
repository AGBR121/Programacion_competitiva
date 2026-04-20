#include<iostream>
#include<cmath>
using namespace std;

bool isPerfectSquare(long long n, long long &root) {
    if (n < 0) return false;
    root = (long long)sqrt((double)n);
    while (root * root > n) root--;
    while ((root+1)*(root+1) <= n) root++;
    return root * root == n;
}

int main(){
    long long p = 0;
    long long q = 0;
    cin >> p >> q;

    long long br = -1;
    long long bg = -1;

    // s = r+g

    for(long long s = 2; s <=2000001; s++){
        long long num = p*s*(s-1);
        if (num % q != 0) continue;
        long long rg2 = num/q;

        long long disc = s*s-2*rg2;
        long long root;
        if(!isPerfectSquare(disc, root)){
            continue;
        }
        long long r = (s-root)/2;
        long long g = (s+root)/2;

        if ((s - root) % 2 != 0) continue;
        if (r <= 0 || g < r) continue;
        if (r > 1000000) continue;

        if (2 * r * g * q != p * s * (s - 1)) continue;

        if (br == -1 || r < br || (r == br && g < bg)) {
            br = r;
            bg = g;
        }

        break;
    }
    
    if(br == -1){
        cout << "Impossible" << endl;
    } else {
        cout << br << " " << bg << endl;
    }

    return 0;
}