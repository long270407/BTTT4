#ifndef CDATE_H
#define CDATE_H
#include <iostream>

class CDate {
private:
    int iNgay, iThang, iNam;

    // Các hàm bổ trợ
    bool KiemTraNamNhuan(int nam) const;
    int NgayTrongThang(int thang, int nam) const;
    long SoNgayTuNam0() const; // Tính tổng số ngày từ 01/01/0000 để phục vụ tính khoảng cách

public:
    CDate(int ngay = 1, int thang = 1, int nam = 2000);

    // Phép toán cộng, trừ với một số ngày
    CDate operator+(int ngay_them) const;
    CDate operator-(int ngay_bot) const;

    // Phép toán ++, -- (thêm/bớt 1 ngày)
    CDate& operator++();    // Tiền tố
    CDate operator++(int);  // Hậu tố
    CDate& operator--();    // Tiền tố
    CDate operator--(int);  // Hậu tố

    // Khoảng cách giữa 2 ngày (tính bằng ngày)
    long operator-(const CDate& ngay_khac) const;

    // Nạp chồng nhập/xuất
    friend std::istream& operator>>(std::istream& is, CDate& d);
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
};

#endif