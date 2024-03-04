#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int arr[2005][2005];
int prefix[2005][2005];
int m, n; // khai bao bien toan cuc 
// mang cong don 
// mang cong don tren mang 2 chieu 
void nhapMang2Chieu() {
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Nhap phan tu cua dong " << i << endl;
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            prefix[i][j] = prefix[i -1][j] + prefix[i][j - 1] - prefix[i -1][j -1] + arr[i][j];
        }
    }
}
int main(){
    // // khoi tao mang 2 chieu
    // int arr[100][100];
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    // int q;
    // cin >> q;
    // ll F[100];
    // for (int i = 0; i < n; i++){
    //     if (i == 0){
    //         F[i] = a[i];
    //     }
    //     else {
    //         // de tinh phan tu cong dong tai vi tri i trong mang cong don thi ta chi can lay phan tu truoc vi tri 
    //         // cong don can check sau do + voi phan tu cua mang a tai vi tri do 
    //         //
    //         F[i] = F[i-1] + a[i];
    //     }
    // }
    //mang cong don tren mang 2 chieu voi do phuc tap O(N * M) N hang M cot 
    // int h1, h2;
    // int c1, c2;
    // ll sum1 = 0;
    // for (int i = h1; i <= h2; i++){
    //     for (int j = c1; j <= c2; j++){
    //         sum1 += a[i][j]; // do phuc tap O(N *M)  
    //     }
    // }

    // while (q--){
    //     int l; 
    //     int r;
    //     cin >> l >> r;
    //     // dung de tinh tu cho l toi cho r nao do tren mang 
    //     // do muon su dung la vi tri tren mang nen soi voi so truyen vao ta se phai tru di 1 
    //     l--;
    //     r--;
        // ll sum = 0;
        // // duyet tuan tu qua cac phan tu trong mang 
        // // do phuc tap se la O(N) do duyet quq mang gom n phan tu 
        // for (int i = l; i <= r; i++){
        //     sum += a[i];
        // }
        // cout << sum << endl;
        // do phuc tap O(1)
        // if (l == 0){
        //     cout << F[r] << endl;
        // }
        // else{
        //     cout << F[r] - F[l - 1] << endl;
        // }


    // }
    nhapMang2Chieu();
    int q;
    cin >> q;
    while (q--) {
        int h1, h2;
        int c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        cout << prefix[h2][c2] - prefix[h1 -1][c2] - prefix[h2][c1 -1] + prefix[h1 -1][c1 -1] << endl;
    }




    return 0;
}
