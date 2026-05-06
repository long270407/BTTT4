#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>

class CVector {
private:
    int iSoChieu;
    double* dThanhPhan;

public:
    // Nhóm Big Three quản lý bộ nhớ
    CVector(int n = 1);
    CVector(const CVector& v);
    ~CVector();
    CVector& operator=(const CVector& v);

    // Các phép toán trên vector
    CVector operator+(const CVector& v) const;
    CVector operator-(const CVector& v) const;
    double operator*(const CVector& v) const;      // Tích vô hướng của 2 vector
    CVector operator*(double k) const;             // Nhân vector với một số vô hướng

    // Nhập xuất
    friend std::istream& operator>>(std::istream& is, CVector& v);
    friend std::ostream& operator<<(std::ostream& os, const CVector& v);
};

#endif