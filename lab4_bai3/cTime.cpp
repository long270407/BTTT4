#include "CTime.h"
#include <iomanip>
#include <Windows.h>

// Hàm hỗ trợ di chuyển con trỏ console (dành cho Windows)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CTime::ChuanHoa() {
    // Đưa tất cả về tổng giây để tính toán bù trừ
    long totalSeconds = iGio * 3600 + iPhut * 60 + iGiay;

    // Nếu tổng giây âm (lùi qua ngày hôm trước)
    if (totalSeconds < 0) {
        totalSeconds = (totalSeconds % 86400) + 86400;
    }

    // Giới hạn trong 1 ngày (24h * 60p * 60s = 86400 giây)
    totalSeconds %= 86400;

    iGio = totalSeconds / 3600;
    iPhut = (totalSeconds % 3600) / 60;
    iGiay = totalSeconds % 60;
}

CTime::CTime(int gio, int phut, int giay) : iGio(gio), iPhut(phut), iGiay(giay) {
    ChuanHoa();
}

CTime CTime::operator+(int giay_them) const {
    return CTime(iGio, iPhut, iGiay + giay_them);
}

CTime CTime::operator-(int giay_bot) const {
    return CTime(iGio, iPhut, iGiay - giay_bot);
}

CTime& CTime::operator++() {
    iGiay++;
    ChuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    iGiay++;
    ChuanHoa();
    return temp;
}

CTime& CTime::operator--() {
    iGiay--;
    ChuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    iGiay--;
    ChuanHoa();
    return temp;
}

std::istream& operator>>(std::istream& is, CTime& t) {
    std::cout << "Nhap gio: "; is >> t.iGio;
    std::cout << "Nhap phut: "; is >> t.iPhut;
    std::cout << "Nhap giay: "; is >> t.iGiay;
    t.ChuanHoa(); // Đảm bảo người dùng nhập sai (ví dụ 70 giây) vẫn tự chuẩn hóa được
    return is;
}

std::ostream& operator<<(std::ostream& os, const CTime& t) {
    os << std::setfill('0') << std::setw(2) << t.iGio << ":"
        << std::setfill('0') << std::setw(2) << t.iPhut << ":"
        << std::setfill('0') << std::setw(2) << t.iGiay;
    return os;
}

void CTime::HienThiDongHo() const {
    // Lấy kích thước window console hiện tại
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Đặt con trỏ ở góc trên bên phải (trừ 8 ký tự của "HH:MM:SS" và khoảng đệm)
    gotoxy(columns - 10, 0);
    std::cout << *this;
}