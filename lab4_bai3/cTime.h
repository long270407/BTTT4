#ifndef CTIME_H
#define CTIME_H
#include <iostream>

class CTime {
private:
    int iGio, iPhut, iGiay;
    void ChuanHoa(); // Hàm hỗ trợ đưa thời gian về định dạng chuẩn (0-23h, 0-59p, 0-59s)

public:
    CTime(int gio = 0, int phut = 0, int giay = 0);

    // Phép toán cộng, trừ với một số nguyên giây
    CTime operator+(int giay_them) const;
    CTime operator-(int giay_bot) const;

    // Phép toán ++, -- (thêm/bớt 1 giây)
    CTime& operator++();    // Tiền tố (++t)
    CTime operator++(int);  // Hậu tố (t++)
    CTime& operator--();    // Tiền tố (--t)
    CTime operator--(int);  // Hậu tố (t--)

    // Nạp chồng nhập/xuất
    friend std::istream& operator>>(std::istream& is, CTime& t);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);

    // Hàm ứng dụng
    void HienThiDongHo() const;
};

#endif