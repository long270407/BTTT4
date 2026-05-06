#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
    CVector A, B;

    cout << "--- Nhap Vector A ---" << endl;
    cin >> A;
    cout << "--- Nhap Vector B ---" << endl;
    cin >> B;

    cout << "\nVector A = " << A << endl;
    cout << "Vector B = " << B << endl;

    cout << "\n--- Cac phep toan vector ---" << endl;

    CVector Tong = A + B;
    CVector Hieu = A - B;
    double TichVoHuong = A * B;

    cout << "A + B = " << Tong << endl;
    cout << "A - B = " << Hieu << endl;
    cout << "Tich vo huong A * B = " << TichVoHuong << endl;

    double k;
    cout << "\nNhap so k de nhan voi Vector A: ";
    cin >> k;
    cout << "A * " << k << " = " << A * k << endl;

    return 0;
}