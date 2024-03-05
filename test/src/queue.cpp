#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
//push_front(): day vao dau 
//push_back(): day vao cuoi
//pop_front(): xoa dau 
//pop_back(): xoa cuoi
// emty(): check xem co rong hay kh 
// front(): lay ra phan tu o dAU 
// back(): lay ra phan tu o cuoi 
//sliding window maximum 

int main(){
    // deque<int> q;
    // q.push_front(2);
    // q.push_back(3);
    // q.push_back(4);
    // q.push_back(5);
    // q.push_front(1);
    // cout << q.front() << endl;
    // cout << q.back() << endl;
    // int n, k;
    // n la so phan tu , k la so cua so 
    // cin >>n >>k;
    // int arr[1000];
    // for (int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    // // giai bai toan cua so hang doi
    // //sliding window maximum
    // // duyet vong for qua so lan la n - so cua so 
    // for (int i = 0; i < n - k; i++){
    //     int tmp = INT_MIN;
    //     // duyet qua pham vi cua cua so de tim maximum 
    //     for (int j = 0; j < k ; j++){
    //         tmp = max(tmp, arr[i + j]);
    //     }
    //     cout << tmp << " ";

    // }
    int n, k;
    //n la so phan tu , k la so cua so 
    cin >>n >>k;
    int arr[1000];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    deque<int> q;
    // duyet qua cac phan tu cua cua so hang doi
    for (int i = 0; i < k; i++){
        // duyet toi khi nao rong va phan tu i lon hon phan tu cuoi cua deque thi xoa
        // phan tu do 
        while(!q.empty() || arr[i] > arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // in ra so lon nhat cua hang doi
    cout << arr[q.front()] << " ";
    for (int i = k; i <= n - 1; i++){
        if (q.front() <= i - k){
            q.pop_front();
        }
        while(!q.empty() || arr[i] > arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // in ra so lon nhat cua hang doi
    cout << arr[q.front()] << " ";








    
    



    return 0;
}