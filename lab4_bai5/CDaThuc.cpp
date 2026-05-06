#include "CDaThuc.h"
#include <cmath>
#include <algorithm>

void CDaThuc::ChuanHoa() {
    while (iBac > 0 && dHeSo[iBac] == 0) {
        iBac--;
    }
}

// Constructor khởi tạo
CDaThuc::CDaThuc(int bac) : iBac(bac) {
    if (iBac < 0) iBac = 0;
    dHeSo = new double[iBac + 1] {0}; // Khởi tạo mảng hệ số toàn 0
}

// Copy Constructor (Ngăn lỗi double-free)
CDaThuc::CDaThuc(const CDaThuc& dt) : iBac(dt.iBac) {
    dHeSo = new double[iBac + 1];
    for (int i = 0; i <= iBac; i++) {
        dHeSo[i] = dt.dHeSo[i];
    }
}

// Destructor (Giải phóng bộ nhớ)
CDaThuc::~CDaThuc() {
    delete[] dHeSo;
}

// Assignment Operator
CDaThuc& CDaThuc::operator=(const CDaThuc& dt) {
    if (this != &dt) {
        delete[] dHeSo; // Xóa mảng cũ
        iBac = dt.iBac;
        dHeSo = new double[iBac + 1];
        for (int i = 0; i <= iBac; i++) {
            dHeSo[i] = dt.dHeSo[i];
        }
    }
    return *this;
}

CDaThuc CDaThuc::operator+(const CDaThuc& dt) const {
    int bacMax = std::max(iBac, dt.iBac);
    CDaThuc kq(bacMax);
    for (int i = 0; i <= bacMax; i++) {
        double a = (i <= iBac) ? dHeSo[i] : 0;
        double b = (i <= dt.iBac) ? dt.dHeSo[i] : 0;
        kq.dHeSo[i] = a + b;
    }
    kq.ChuanHoa();
    return kq;
}

CDaThuc CDaThuc::operator-(const CDaThuc& dt) const {
    int bacMax = std::max(iBac, dt.iBac);
    CDaThuc kq(bacMax);
    for (int i = 0; i <= bacMax; i++) {
        double a = (i <= iBac) ? dHeSo[i] : 0;
        double b = (i <= dt.iBac) ? dt.dHeSo[i] : 0;
        kq.dHeSo[i] = a - b;
    }
    kq.ChuanHoa();
    return kq;
}

CDaThuc CDaThuc::operator*(const CDaThuc& dt) const {
    CDaThuc kq(iBac + dt.iBac);
    for (int i = 0; i <= iBac; i++) {
        for (int j = 0; j <= dt.iBac; j++) {
            kq.dHeSo[i + j] += dHeSo[i] * dt.dHeSo[j];
        }
    }
    kq.ChuanHoa();
    return kq;
}

double CDaThuc::TinhGiaTri(double x) const {
    double ketQua = 0;
    // Thuật toán Horner tính giá trị đa thức nhanh và tối ưu hơn
    for (int i = iBac; i >= 0; i--) {
        ketQua = ketQua * x + dHeSo[i];
    }
    return ketQua;
}

std::istream& operator>>(std::istream& is, CDaThuc& dt) {
    std::cout << "Nhap bac cua da thuc: ";
    int bac;
    is >> bac;

    // Tạo mảng mới với bậc vừa nhập
    CDaThuc temp(bac);
    for (int i = temp.iBac; i >= 0; i--) {
        std::cout << "He so x^" << i << ": ";
        is >> temp.dHeSo[i];
    }
    temp.ChuanHoa();
    dt = temp; // Gọi operator=
    return is;
}

std::ostream& operator<<(std::ostream& os, const CDaThuc& dt) {
    bool isZero = true;
    for (int i = dt.iBac; i >= 0; i--) {
        if (dt.dHeSo[i] != 0) {
            isZero = false;
            if (i < dt.iBac && dt.dHeSo[i] > 0) os << " + ";
            else if (dt.dHeSo[i] < 0) os << " - ";

            double val = std::abs(dt.dHeSo[i]);
            if (val != 1 || i == 0) os << val;

            if (i > 0) os << "x";
            if (i > 1) os << "^" << i;
        }
    }
    if (isZero) os << "0";
    return os;
}