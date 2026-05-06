#ifndef CDATHUC_H
#define CDATHUC_H
#include <iostream>

class CDaThuc {
private:
    int iBac;
    double* dHeSo;
    void ChuanHoa(); // Giảm bậc nếu hệ số bậc cao nhất bằng 0

public:
    // Nhóm Big Three: Constructor, Destructor, Copy Constructor, Assignment Operator
    CDaThuc(int bac = 0);
    CDaThuc(const CDaThuc& dt);
    ~CDaThuc();
    CDaThuc& operator=(const CDaThuc& dt);

    // Các phép toán
    CDaThuc operator+(const CDaThuc& dt) const;
    CDaThuc operator-(const CDaThuc& dt) const;
    CDaThuc operator*(const CDaThuc& dt) const;

    // Tính giá trị đa thức tại x
    double TinhGiaTri(double x) const;

    // Nhập xuất
    friend std::istream& operator>>(std::istream& is, CDaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const CDaThuc& dt);
};

#endif