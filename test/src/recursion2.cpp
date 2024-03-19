#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;
int Tohop(int n, int k){
    if (n == k || k == 0){
        return 1;
    }
    else {
        return Tohop(n - 1, k - 1) + Tohop(n - 1, k);
    }
}
//todo: Chuyen tu he co so n sang he nhi phan 
void dec_to_bin(long long n){
    if (n < 2){
        printf("%d", n);
    }
    else {
        dec_to_bin(n / 2);
        cout << n % 2;
    }
}
void dec_to_hex(long long n){
    if (n < 16){
        if (n < 10){
            cout << n;
        }
        else {
            //todo: do chu cai trong bang ki tu bat dau tu 55 
            cout << char(n + 55);
        }
    }
    else {
        dec_to_hex(n /16);
        int r = n % 16;
        if (r < 16){
            if (r < 10){
                cout << r;
            }
            else {
                cout << char(r + 55);
            }
        }
    }

}
//? dem chu so cua 1 so nguyen duong n 
int Countso(int n){
    if (n < 10){
        return 1;
    }
    else {
        return 1 + Countso(n / 10);
    }
}
// tinh tong chu so cua o so n
//todo: khong dung de quy 
int Norecursion(int n){
    int sum= 0;
    while(n > 10){
        sum += n % 10;
        n/=10;
    }
}
//todo: dung de quy 
int RCScnt(int n){
    int sum = 0;
    if (n < 10){
        return n;
    }
    else {
        //? goi lai va giam so do di 
        return n % 10 + RCScnt(n/10);
    }
}
// tim chu so lon nhat cua so n
int max1(ll n){
    if (n < 10){
        return n;
    }
    else {
        return max(n % 10, max1(n/10));
    }
}
//todo: tong cac chu so tu 1 toi n
int sum1ton(ll n){
    if (n == 1){
        return 1;
    }
    else{
        return n + sum1ton(n -1);
    }
}
//todo: tong binh phuong tu 1 toi n
int sum1ton2(ll n){
    if (n == 1){
        return 1;
    }
    else {
        return n * n + sum1ton2(n - 1);
    }
}
//todo: tong cua 1/.i toi 1/n
int sum1phan(ll n){
    if (n == 1){
        return 1;
    }
    else {
        return 1/n + sum1phan(n -1);
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    int ans = Tohop(n, k);
    cout << "To hop chap k cua n la : " << ans << endl;
    cout << "2609 = "; dec_to_hex(2609);
    return 0;

}