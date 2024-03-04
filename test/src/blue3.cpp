#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Có n môn học, môn thứ i sẽ có ci chương. Devu mong muốn học hết tất cả
// các môn học.
// Ở môn đầu tiên Devu học trong x giờ. Nhưng sau khi học xong môn đầu tiên
// môn tiếp theo cậu sẽ học nhanh hơn bình thường 1 giờ. Tuy vậy, mỗi chương
// Devu vẫn cần ít nhất 1 giờ để học qua các chương.
// Nhiệm vụ của bạn là tính thời gian tối thiểu mà Devu cần để học xong n
// môn học đã cho.
long long seftLearning(vector<int>& v,int x ){
    // vector v chua gom n mon hoc va x la thoi gian de doc xong 1 chuong 
    // xong 1 mon dau tien la mon sau nhanh hon 1 h 
    // sap xep lai so chuong theo chieu tang dan 
    sort(v.begin(), v.end());
    long long min_time = 0;
    for (int i = 0; i < v.size(); i++){
        // thoi gian toi thieu bang so chuong nhan voi so gio doc
        min_time += v[i] * x;
        // check case neu xong mon dau tien
        // thi so gio se doc n -1 mon tiep theo giam 1 gio 
        //nhung so gio van luon lon hon 1
        if (x > 1){
            x--;
        }
    }
    return min_time;
}
int main(){
    int n;
    cout << "Nhap so mon hoc cua devu: ";
    cin >> n;
    int x;
    cout << "Nhap so gio doc 1 chuong ban dau: ";
    cin >> x;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
    long long result = seftLearning(v, x);
    cout << result << endl;
    return 0;

}