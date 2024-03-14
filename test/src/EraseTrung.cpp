#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            v.erase(v.begin() + i);
            n--;
            i--; // Giảm lại chỉ số để xem xét phần tử tiếp theo sau khi xóa
        }
    }

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
