#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() {
    SoPhuc a, b;

    cout << "--- Nhap so phuc A ---" << endl;
    cin >> a;
    cout << "--- Nhap so phuc B ---" << endl;
    cin >> b;

    cout << "\nSo phuc A: " << a << endl;
    cout << "So phuc B: " << b << endl;

    // Test phương thức thiết lập xem một số thực như số phức đặc biệt
    SoPhuc c = 5.5;
    cout << "So phuc C (tu so thuc 5.5): " << c << endl;

    cout << "\n--- Cac phep toan ---" << endl;
    cout << "Tong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;

    // Kiểm tra chia cho 0 (mẫu số bằng 0 khi cả thực và ảo của b đều bằng 0)
    if (b != SoPhuc(0, 0)) {
        cout << "Thuong: " << a / b << endl;
    }
    else {
        cout << "Khong the chia cho so phuc 0!" << endl;
    }

    cout << "\n--- So sanh ---" << endl;
    if (a == b) {
        cout << "A bang B" << endl;
    }
    else if (a != b) {
        cout << "A khac B" << endl;
    }

    return 0;
}