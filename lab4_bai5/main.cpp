#include <iostream>
#include "CDaThuc.h"

using namespace std;

int main() {
    CDaThuc A, B;

    cout << "--- Nhap Da Thuc A ---" << endl;
    cin >> A;
    cout << "--- Nhap Da Thuc B ---" << endl;
    cin >> B;

    cout << "\nDa thuc A: " << A << endl;
    cout << "Da thuc B: " << B << endl;

    cout << "\n--- Cac phep toan ---" << endl;
    CDaThuc Tong = A + B;
    CDaThuc Hieu = A - B;
    CDaThuc Tich = A * B;

    cout << "A + B = " << Tong << endl;
    cout << "A - B = " << Hieu << endl;
    cout << "A * B = " << Tich << endl;

    double x;
    cout << "\nNhap gia tri x de tinh A(x): ";
    cin >> x;
    cout << "A(" << x << ") = " << A.TinhGiaTri(x) << endl;

    return 0;
}