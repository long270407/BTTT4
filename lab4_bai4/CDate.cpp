#include "CDate.h"
#include <cmath>
#include <iomanip>

bool CDate::KiemTraNamNhuan(int nam) const {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int CDate::NgayTrongThang(int thang, int nam) const {
    switch (thang) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return KiemTraNamNhuan(nam) ? 29 : 28;
    default:
        return 31;
    }
}

long CDate::SoNgayTuNam0() const {
    long tongNgay = iNam * 365 + iNgay;
    // Cộng dồn ngày của các tháng trước đó trong cùng năm
    for (int i = 1; i < iThang; i++) {
        tongNgay += NgayTrongThang(i, iNam);
    }
    // Cộng thêm số ngày nhuận của các năm trước
    int namTruoc = iNam - 1;
    tongNgay += (namTruoc / 4) - (namTruoc / 100) + (namTruoc / 400);
    return tongNgay;
}

CDate::CDate(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) {}

CDate CDate::operator+(int ngay_them) const {
    CDate kq = *this;
    kq.iNgay += ngay_them;
    while (kq.iNgay > kq.NgayTrongThang(kq.iThang, kq.iNam)) {
        kq.iNgay -= kq.NgayTrongThang(kq.iThang, kq.iNam);
        kq.iThang++;
        if (kq.iThang > 12) {
            kq.iThang = 1;
            kq.iNam++;
        }
    }
    return kq;
}

CDate CDate::operator-(int ngay_bot) const {
    CDate kq = *this;
    kq.iNgay -= ngay_bot;
    while (kq.iNgay <= 0) {
        kq.iThang--;
        if (kq.iThang < 1) {
            kq.iThang = 12;
            kq.iNam--;
        }
        kq.iNgay += kq.NgayTrongThang(kq.iThang, kq.iNam);
    }
    return kq;
}

CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int) {
    CDate temp = *this;
    *this = *this + 1;
    return temp;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
    *this = *this - 1;
    return temp;
}

long CDate::operator-(const CDate& ngay_khac) const {
    return std::abs(this->SoNgayTuNam0() - ngay_khac.SoNgayTuNam0());
}

std::istream& operator>>(std::istream& is, CDate& d) {
    std::cout << "Nhap ngay: "; is >> d.iNgay;
    std::cout << "Nhap thang: "; is >> d.iThang;
    std::cout << "Nhap nam: "; is >> d.iNam;
    return is;
}

std::ostream& operator<<(std::ostream& os, const CDate& d) {
    os << std::setfill('0') << std::setw(2) << d.iNgay << "/"
        << std::setfill('0') << std::setw(2) << d.iThang << "/"
        << d.iNam;
    return os;
}