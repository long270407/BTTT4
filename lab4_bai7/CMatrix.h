#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h" // Cần file CVector.h từ Bài 6

class CMatrix {
private:
    int iDong;
    int iCot;
    double** dMat;

    void CapPhat(int dong, int cot);
    void ThuHoi();

public:
    // Nhóm Big Three
    CMatrix(int dong = 1, int cot = 1);
    CMatrix(const CMatrix& m);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& m);

    // Các phép toán ma trận
    CMatrix operator+(const CMatrix& m) const;
    CMatrix operator-(const CMatrix& m) const;
    CMatrix operator*(const CMatrix& m) const; // Tích 2 ma trận

    // Tích ma trận với vector (Kích thước: Ma trận m x n nhân Vector n x 1 -> Vector m x 1)
    CVector operator*(const CVector& v) const;

    // Nhập xuất
    friend std::istream& operator>>(std::istream& is, CMatrix& m);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);
};

#endif