#include "PhanSo.h"
#include <cmath>

// Hàm tìm UCLN
int UCLN(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void PhanSo::RutGon() {
    if (iTu == 0) {
        iMau = 1;
        return;
    }
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
    // Đưa dấu trừ lên tử số nếu mẫu số âm
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Cài đặt phương thức thiết lập
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau) {
    if (iMau == 0) {
        iMau = 1; // Tránh lỗi chia cho 0 khi khởi tạo
    }
    RutGon();
}

PhanSo PhanSo::operator+(const PhanSo& ps) const {
    int tuMoi = iTu * ps.iMau + ps.iTu * iMau;
    int mauMoi = iMau * ps.iMau;
    return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator-(const PhanSo& ps) const {
    int tuMoi = iTu * ps.iMau - ps.iTu * iMau;
    int mauMoi = iMau * ps.iMau;
    return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator*(const PhanSo& ps) const {
    int tuMoi = iTu * ps.iTu;
    int mauMoi = iMau * ps.iMau;
    return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator/(const PhanSo& ps) const {
    int tuMoi = iTu * ps.iMau;
    int mauMoi = iMau * ps.iTu;
    return PhanSo(tuMoi, mauMoi);
}

bool PhanSo::operator==(const PhanSo& ps) const {
    return (iTu * ps.iMau == ps.iTu * iMau);
}

bool PhanSo::operator>(const PhanSo& ps) const {
    // Vì mẫu số luôn dương sau khi rút gọn nên có thể quy đồng để so sánh
    return (iTu * ps.iMau > ps.iTu * iMau);
}

bool PhanSo::operator<(const PhanSo& ps) const {
    return (iTu * ps.iMau < ps.iTu * iMau);
}

std::istream& operator>>(std::istream& is, PhanSo& ps) {
    std::cout << "Nhap tu so: ";
    is >> ps.iTu;
    do {
        std::cout << "Nhap mau so (khac 0): ";
        is >> ps.iMau;
    } while (ps.iMau == 0);
    ps.RutGon();
    return is;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    if (ps.iMau == 1 || ps.iTu == 0) {
        os << ps.iTu;
    }
    else {
        os << ps.iTu << "/" << ps.iMau;
    }
    return os;
}