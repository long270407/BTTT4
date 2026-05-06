#include <iostream>
#include <iomanip>
#include "CDate.h"

using namespace std;

int main() {
    CDate d1, d2;

    cout << "--- Nhap ngay gui tien (CDate 1) ---" << endl;
    cin >> d1;
    cout << "Ngay gui: " << d1 << endl;

    cout << "\n--- Kiem tra phep toan tren CDate ---" << endl;
    cout << "Ngay gui cong them 45 ngay la: " << d1 + 45 << endl;
    cout << "Ngay gui tru di 10 ngay la: " << d1 - 10 << endl;

    CDate d_temp = d1;
    cout << "Hau to (d++): " << d_temp++ << " -> Sau do la: " << d_temp << endl;
    cout << "Tien to (++d): " << ++d_temp << endl;

    cout << "\n--- Ung dung: Tinh lai suat ngan hang ---" << endl;
    cout << "Nhap ngay rut tien (CDate 2) ---" << endl;
    cin >> d2;
    cout << "Ngay rut: " << d2 << endl;

    long soNgayGui = d2 - d1;
    cout << "-> Tong so ngay gui: " << soNgayGui << " ngay." << endl;

    double soTienGoc, laiSuatNam;
    cout << "\nNhap so tien goc (VND): ";
    cin >> soTienGoc;
    cout << "Nhap lai suat nam (%/nam): ";
    cin >> laiSuatNam;

    // Công thức tính lãi suất: Lãi = Tiền gốc * (Lãi suất năm / 100) * (Số ngày gửi / 365)
    double tienLai = soTienGoc * (laiSuatNam / 100.0) * (soNgayGui / 365.0);
    double tongTien = soTienGoc + tienLai;

    cout << fixed << setprecision(0); // Không in số thập phân cho tiền tệ
    cout << "\n======================================" << endl;
    cout << "Bang tinh lai suat:" << endl;
    cout << "- Tien goc: " << soTienGoc << " VND" << endl;
    cout << "- Thoi gian gui: " << soNgayGui << " ngay" << endl;
    cout << "- Tien lai nhan duoc: " << tienLai << " VND" << endl;
    cout << "- TONG TIEN NHAN DUOC: " << tongTien << " VND" << endl;
    cout << "======================================" << endl;

    return 0;
}