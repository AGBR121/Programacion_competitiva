#include<iostream>
using namespace std;

int calcularMCD(int a, int b) {
    if (b == 0)
        return a;
    return calcularMCD(b, a % b); 
}

int main(){
    long long n = 0;
    cin >> n;
    long long contador = 0;
    bool found = false;
    for(long long i = 1; i <= 89443; i++){
        for(long long j = 0; j < i; j++){
            contador++;
            if(contador == n){
                found = true;
                if(j==0){
                    cout << i << endl;
                }else{
                    long long result = calcularMCD(i, j);
                    if(result == -1){
                        cout << i << " "<< j << "/" << i << endl;
                    }else{
                        cout << i << " " << j/result << "/" << i/result << endl;
                    }
                }
            }
            if(found) break;
        }
        if(found) break;
    }
}