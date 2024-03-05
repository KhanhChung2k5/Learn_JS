#include <iostream>
using namespace std;
int giaithua(int n){
    int gt = 1;
    if (n <=1){
        return 1;
    }
    else {
        gt = n * giaithua(n - 1);
    }
    return gt;
}
int sumn(int n){
    int sum = 0;
    if (n <= 1){
        return n;
    }
    else {
        sum += n + sumn(n - 1);
    }
    return sum;

}
//1 + 1/2 + 1/3 +....+ 1/n
double fractionsum(int n){
    double sum = 0;
    if (n <=1){
        return 1.0;
    }
    else {
        sum += 1.0/n + fractionsum(n - 1);
    }
    return sum;
}
//S(n) = 1*2 + 2*3+ 3*4 + 4*5 +.....+ n(n+1)
double tichsum(int n){
    if (n == 1){
        return 2;
    }
    else{
        return n*( n + 1) + tichsum(n - 1);
    }
}
double csc(double a, double r, double n ){
    if(n == 1){
        return a;
    }
    else{
        return a * csc(a, n - 1, r);
    }
}
double csn(double a, double q,double n){
    if (n == 1){
        return a;
    }
    else {
        return q * csn(a, n -1, q);
    }
}
double an(int a, int n){
    // 1, 0 , -1
    if (n == 0){
        return 1;
    }
    else if (n == 1) {
        return 0;
    }
    else if (n == 2){
        return -1;
    }
    else {
        return 2*an(a, n - 1) - 3*an(a, n - 2) - an(a, n - 3);
    }
}
// dem so chu so cua so nguyen duong n
int count(int n){
    if (n < 10){
        return 1;
    }
    return 1 + count(n/10);
}

int main(){
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    sumn(n);
    cout << "Tong tu 1 toi n la: " << sumn(n) << endl;
    cout << "tong cua giai thua la: " << giaithua(n) << endl;
    fractionsum(n);
    double fsum = fractionsum(n);
    cout << "tong cua 1/n la: " << fsum << endl;
    tichsum(n);
    double tsum = tichsum(n);
    cout << tsum << endl;
    return 0;
}