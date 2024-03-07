#include <iostream>
using namespace std;
//? Bai Toan: Quay lui xau nhi pha co do dai N
//todo ta thay7 moi bit chi co the nhan dc 2 gia tri la 0 or 1 
int n;
int K;
int *a = new int[n];
// void inkq(){
//     for (int i = 0; i < n;i++){
//         cout << a[i];
//     }
//     cout << endl;
// }
// void Try(int i){
//     for (int j = 0; j <=1; j++){
//         a[i] = j;
//         //? check neu i da check toi bit cuoi cung cua xau nhi phan
//         if (i == n){
//             inkq();
//         }
//         else{
//             //? dung de quy de goi lai ham tiep tuc thuc thi
//             // todo duoc thuc thi theo kieu stack de check cac i 
//             // last in first out 
//             //? try(1) in front out last 
//             Try(i + 1);
//         }
//     }
// }
//todo search to hop chapn k cua n 
void inkq(){
    for (int i = 1; i <= K;i++){
        cout << a[i];
    }
    cout << endl;
}
void Try(int i){
    for (int j = a[i - 1] + 1; j <= n - k +i; j++){
        a[i] = j;
        if (i == k){
            inkq();
        }
        else {
            Try(i + 1);
        }
    }
}
int main(){
    cin >> n;
    cin >> K;
    a[0] = 0;
    Try(1);


    return 0;
}