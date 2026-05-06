#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>

class PhanSo {
private:
    int iTu;
    int iMau;
    void RutGon(); // Hàm hỗ trợ rút gọn phân số

public:
    // Phương thức thiết lập mặc định kết hợp chuyển kiểu từ số nguyên
    PhanSo(int tu = 0, int mau = 1);

    // Nạp chồng các toán tử số học
    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;

    // Nạp chồng các toán tử so sánh
    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;

    // Nạp chồng toán tử nhập xuất
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};

#endif