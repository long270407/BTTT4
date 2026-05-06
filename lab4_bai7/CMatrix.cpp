#include "CMatrix.h"


void CMatrix::CapPhat(int dong, int cot) {
    iDong = dong;
    iCot = cot;
    dMat = new double* [iDong];
    for (int i = 0; i < iDong; i++) {
        dMat[i] = new double[iCot] {0};
    }
}

void CMatrix::ThuHoi() {
    if (dMat != nullptr) {
        for (int i = 0; i < iDong; i++) {
            delete[] dMat[i];
        }
        delete[] dMat;
        dMat = nullptr;
    }
}

CMatrix::CMatrix(int dong, int cot) {
    if (dong <= 0) dong = 1;
    if (cot <= 0) cot = 1;
    CapPhat(dong, cot);
}

CMatrix::CMatrix(const CMatrix& m) {
    CapPhat(m.iDong, m.iCot);
    for (int i = 0; i < iDong; i++) {
        for (int j = 0; j < iCot; j++) {
            dMat[i][j] = m.dMat[i][j];
        }
    }
}

CMatrix::~CMatrix() {
    ThuHoi();
}

CMatrix& CMatrix::operator=(const CMatrix& m) {
    if (this != &m) {
        ThuHoi();
        CapPhat(m.iDong, m.iCot);
        for (int i = 0; i < iDong; i++) {
            for (int j = 0; j < iCot; j++) {
                dMat[i][j] = m.dMat[i][j];
            }
        }
    }
    return *this;
}

CMatrix CMatrix::operator+(const CMatrix& m) const {
    if (iDong != m.iDong || iCot != m.iCot) {
        std::cerr << "\nLoi: Hai ma tran khong cung kich thuoc!" << std::endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, iCot);
    for (int i = 0; i < iDong; i++) {
        for (int j = 0; j < iCot; j++) {
            kq.dMat[i][j] = dMat[i][j] + m.dMat[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator-(const CMatrix& m) const {
    if (iDong != m.iDong || iCot != m.iCot) {
        std::cerr << "\nLoi: Hai ma tran khong cung kich thuoc!" << std::endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, iCot);
    for (int i = 0; i < iDong; i++) {
        for (int j = 0; j < iCot; j++) {
            kq.dMat[i][j] = dMat[i][j] - m.dMat[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator*(const CMatrix& m) const {
    if (iCot != m.iDong) {
        std::cerr << "\nLoi: So cot ma tran 1 phai bang so dong ma tran 2!" << std::endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, m.iCot);
    for (int i = 0; i < iDong; i++) {
        for (int j = 0; j < m.iCot; j++) {
            kq.dMat[i][j] = 0;
            for (int k = 0; k < iCot; k++) {
                kq.dMat[i][j] += dMat[i][k] * m.dMat[k][j];
            }
        }
    }
    return kq;
}

CVector CMatrix::operator*(const CVector& v) const {
    // Nhờ friend class, ta gọi trực tiếp v.iSoChieu thay vì v.getSoChieu()
    if (iCot != v.iSoChieu) {
        std::cerr << "\nLoi: Kich thuoc ma tran va vector khong hop le de nhan!" << std::endl;
        return CVector(1);
    }

    CVector kq(iDong);
    for (int i = 0; i < iDong; i++) {
        double sum = 0;
        for (int j = 0; j < iCot; j++) {
            // Nhờ friend class, ta gọi trực tiếp mảng v.dThanhPhan[j]
            sum += dMat[i][j] * v.dThanhPhan[j];
        }
        kq.dThanhPhan[i] = sum; // Gán trực tiếp vào mảng kết quả
    }
    return kq;
}

std::istream& operator>>(std::istream& is, CMatrix& m) {
    int dong, cot;
    std::cout << "Nhap so dong: "; is >> dong;
    std::cout << "Nhap so cot: "; is >> cot;

    CMatrix temp(dong, cot);
    for (int i = 0; i < temp.iDong; i++) {
        for (int j = 0; j < temp.iCot; j++) {
            std::cout << "Phan tu [" << i << "][" << j << "]: ";
            is >> temp.dMat[i][j];
        }
    }
    m = temp;
    return is;
}

std::ostream& operator<<(std::ostream& os, const CMatrix& m) {
    for (int i = 0; i < m.iDong; i++) {
        for (int j = 0; j < m.iCot; j++) {
            os << m.dMat[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}