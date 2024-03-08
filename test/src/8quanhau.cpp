#include <iostream>
using namespace std;
// todo ta se dat tam quan hau vao ban co vua nhu 1 mang 2  chieu co kich thuoc 8x8
// todo thuat toan chinh cua bai la dat 8 quan hau sao cho khong co quan hau nao co 
// todo an quan hau khac theo quy tac di chuyen cua co vua 
//? ta se xep cac quan hau sao cho khong co quan hau nao cung nam tren 1 cot or 1 hang 
//? khong co quan hau nam tren cung 1 duong cheo 
int n;
int *a = new int[n];
int *cot = new int[n];
int *d1 = new int[n];
int *d2 = new int[n];
//? exam: x[i] thi dg cheo chinh se quan ly phan tu dg cheo chinh theo cthuc (i - j + n)
//todo dg cheo phu se la i + j - 1
void inkq(){
    for (int i = 1; i <= n;i++){
        cout << "con hau nam o hang thu: " << i << " " << "cot thu: " << a[i] << endl;
    }
}
void Try(int i){
    for (int j = 1; i <= n; j++){
        //todo check xem o cot j duong cheo chinh va dg cheo phu con rong hay khong 
        if (cot[j] == 1 && d1[i - j + 1] == 1 && d2[i - j + n] == 1){
            //? neu ca 3 dieu kien deu thoa thi gan a[i] = j
            a[i] = j;
            // gan lai bang 0 de danh dau ta da su dung 
            cot[j] ==d1[i - j + 1] == d2[i - j + n] == 0;
            if (i == n){
                inkq();
            }
            else {
                Try(i + 1);
            }
            //todo backtrack de tiep tuc dung nhung case nay de check tiep 
            cot[j] ==d1[i - j + 1] == d2[i - j + n] == 1;
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);
    return 0;
}