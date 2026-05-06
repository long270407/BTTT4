#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo a, b;

    cout << "--- Nhap phan so A ---" << endl;
    cin >> a;
    cout << "--- Nhap phan so B ---" << endl;
    cin >> b;

    cout << "\nPhan so A: " << a << endl;
    cout << "Phan so B: " << b << endl;

    // Test phương thức thiết lập xem một số nguyên như phân số
    PhanSo c = 5;
    cout << "Phan so C (tu so nguyen 5): " << c << endl;

    cout << "\n--- Cac phep toan ---" << endl;
    cout << "Tong (A + B): " << a + b << endl;
    cout << "Hieu (A - B): " << a - b << endl;
    cout << "Tich (A * B): " << a * b << endl;

    if (b == PhanSo(0)) {
        cout << "Khong the chia cho 0!" << endl;
    }
    else {
        cout << "Thuong (A / B): " << a / b << endl;
    }

    // Test phép toán giữa phân số và số nguyên
    cout << "Tong cua A + 2 la: " << a + 2 << endl;

    cout << "\n--- So sanh ---" << endl;
    if (a == b) {
        cout << "A bang B" << endl;
    }
    else if (a > b) {
        cout << "A lon hon B" << endl;
    }
    else if (a < b) {
        cout << "A nho hon B" << endl;
    }

    return 0;
}