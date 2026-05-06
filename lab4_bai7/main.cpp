#include <iostream>
#include "CMatrix.h"
#include "CVector.h"

using namespace std;

int main() {
    CMatrix A, B;

    cout << "--- Nhap Ma Tran A ---" << endl;
    cin >> A;
    cout << "--- Nhap Ma Tran B ---" << endl;
    cin >> B;

    cout << "\nMa Tran A:\n" << A;
    cout << "\nMa Tran B:\n" << B;

    cout << "\n--- Cac phep toan ma tran ---" << endl;
    cout << "\nA + B:\n" << A + B;
    cout << "\nA - B:\n" << A - B;
    cout << "\nA * B (Tich 2 ma tran):\n" << A * B;

    cout << "\n--- Nhan Ma Tran voi Vector ---" << endl;
    CVector V;
    cout << "Nhap Vector V:\n";
    cin >> V;

    cout << "\nVector V: " << V << endl;
    cout << "A * V = " << A * V << endl;

    return 0;
}