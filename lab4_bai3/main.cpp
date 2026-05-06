#include <iostream>
#include <Windows.h>
#include "CTime.h"

using namespace std;

int main() {
    CTime t1;

    cout << "--- Nhap thoi gian ban dau ---" << endl;
    cin >> t1;
    cout << "\nThoi gian vua nhap: " << t1 << endl;

    cout << "\n--- Kiem tra phep toan (+, - n giay) ---" << endl;
    cout << "Thoi gian cong them 100 giay: " << t1 + 100 << endl;
    cout << "Thoi gian tru di 50 giay: " << t1 - 50 << endl;

    cout << "\n--- Kiem tra phep toan (++, --) ---" << endl;
    CTime t2 = t1;
    cout << "t2 ban dau: " << t2 << endl;
    cout << "Hau to (t2++): " << t2++ << " -> Sau do t2 la: " << t2 << endl;
    cout << "Tien to (++t2): " << ++t2 << endl;

    cout << "\n--- Ung dung Dong Ho ---" << endl;
    cout << "Nhan Enter de bat dau dong ho (Bam Ctrl+C de thoat)...";
    cin.ignore();
    cin.get();

    system("cls"); // Xóa màn hình

    CTime clock = t1;
    while (true) {
        clock.HienThiDongHo();
        Sleep(1000); // Ngưng 1 giây (1000 milisecond)
        clock++;     // Tăng 1 giây
    }

    return 0;
}