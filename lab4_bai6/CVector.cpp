#include "CVector.h"

// Constructor
CVector::CVector(int n) : iSoChieu(n) {
    if (iSoChieu <= 0) iSoChieu = 1; // Mặc định ít nhất 1 chiều
    dThanhPhan = new double[iSoChieu] {0};
}

// Copy Constructor
CVector::CVector(const CVector& v) : iSoChieu(v.iSoChieu) {
    dThanhPhan = new double[iSoChieu];
    for (int i = 0; i < iSoChieu; i++) {
        dThanhPhan[i] = v.dThanhPhan[i];
    }
}

// Destructor
CVector::~CVector() {
    delete[] dThanhPhan;
}

// Assignment Operator
CVector& CVector::operator=(const CVector& v) {
    if (this != &v) {
        delete[] dThanhPhan;
        iSoChieu = v.iSoChieu;
        dThanhPhan = new double[iSoChieu];
        for (int i = 0; i < iSoChieu; i++) {
            dThanhPhan[i] = v.dThanhPhan[i];
        }
    }
    return *this;
}

// Phép cộng 2 vector
CVector CVector::operator+(const CVector& v) const {
    if (iSoChieu != v.iSoChieu) {
        std::cerr << "\nLoi: Hai vector khong cung so chieu!" << std::endl;
        return CVector(0);
    }
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        kq.dThanhPhan[i] = dThanhPhan[i] + v.dThanhPhan[i];
    }
    return kq;
}

// Phép trừ 2 vector
CVector CVector::operator-(const CVector& v) const {
    if (iSoChieu != v.iSoChieu) {
        std::cerr << "\nLoi: Hai vector khong cung so chieu!" << std::endl;
        return CVector(0);
    }
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        kq.dThanhPhan[i] = dThanhPhan[i] - v.dThanhPhan[i];
    }
    return kq;
}

// Tích vô hướng (Dot product)
double CVector::operator*(const CVector& v) const {
    if (iSoChieu != v.iSoChieu) {
        std::cerr << "\nLoi: Hai vector khong cung so chieu, khong the tinh tich vo huong!" << std::endl;
        return 0;
    }
    double kq = 0;
    for (int i = 0; i < iSoChieu; i++) {
        kq += dThanhPhan[i] * v.dThanhPhan[i];
    }
    return kq;
}

// Nhân vector với một số thực
CVector CVector::operator*(double k) const {
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; i++) {
        kq.dThanhPhan[i] = dThanhPhan[i] * k;
    }
    return kq;
}

std::istream& operator>>(std::istream& is, CVector& v) {
    std::cout << "Nhap so chieu cua vector: ";
    int n;
    is >> n;

    // Khởi tạo một đối tượng tạm với số chiều vừa nhập
    CVector temp(n);
    for (int i = 0; i < temp.iSoChieu; i++) {
        std::cout << "Nhap thanh phan thu " << i + 1 << ": ";
        is >> temp.dThanhPhan[i];
    }

    v = temp; // Gọi toán tử gán
    return is;
}

std::ostream& operator<<(std::ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.iSoChieu; i++) {
        os << v.dThanhPhan[i];
        if (i < v.iSoChieu - 1) os << ", ";
    }
    os << ")";
    return os;
}