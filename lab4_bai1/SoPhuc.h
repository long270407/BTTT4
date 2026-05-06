#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

class SoPhuc {
private:
    double dThuc;
    double dAo;
public:
    // Phương thức thiết lập duy nhất với tham số mặc định
    SoPhuc(double thuc = 0, double ao = 0);

    // Nạp chồng các toán tử số học
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;

    // Nạp chồng toán tử so sánh
    bool operator==(const SoPhuc& sp) const;
    bool operator!=(const SoPhuc& sp) const;

    // Nạp chồng toán tử nhập/xuất
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
};

#endif