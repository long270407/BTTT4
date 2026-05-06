#include "SoPhuc.h"

// Cài đặt phương thức thiết lập
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double mauSo = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    double thucMoi = (dThuc * sp.dThuc + dAo * sp.dAo) / mauSo;
    double aoMoi = (dAo * sp.dThuc - dThuc * sp.dAo) / mauSo;
    return SoPhuc(thucMoi, aoMoi);
}

bool SoPhuc::operator==(const SoPhuc& sp) const {
    return (dThuc == sp.dThuc && dAo == sp.dAo);
}

bool SoPhuc::operator!=(const SoPhuc& sp) const {
    return !(*this == sp);
}

std::istream& operator>>(std::istream& is, SoPhuc& sp) {
    std::cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    std::cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}

std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
    if (sp.dThuc != 0) {
        os << sp.dThuc;
        if (sp.dAo > 0) os << " + " << sp.dAo << "i";
        else if (sp.dAo < 0) os << " - " << -sp.dAo << "i";
    }
    else {
        if (sp.dAo != 0) os << sp.dAo << "i";
        else os << 0;
    }
    return os;
}