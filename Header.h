#ifndef XeBuss_H
#define XeBuss_H

#include <iostream>
#include <string>

using namespace std;

struct TuyenXe {
    int maTuyen;
    string tenTuyen;
    string diemDau;
    string diemCuoi;
    float cuLy;
    TuyenXe* next;
};

struct CongTy {
    int maCongTy;
    string tenCongTy;
    string diaChi;
    TuyenXe* danhSachTuyen;
    CongTy* next;
};

class QuanLyXeBus {
public:
    QuanLyXeBus();
    ~QuanLyXeBus();

    void ThemCongTy();
    void ThemTuyenXe(int maCongTy);
    void XoaCongTy(int maCongTy);
    void XoaCongTy(string tenCongTy);
    TuyenXe* TimTuyenXe(string tenTuyen);
    TuyenXe* TimTuyenXe(int maTuyen);
    void HienThiDanhSachCongTy();
    void HienThiDanhSachTuyenXe(int maCongTy);

private:
    CongTy* danhSachCongTy;

    CongTy* TimCongTy(int maCongTy);
    CongTy* TimCongTy(string tenCongTy);
};

#endif // THUVIEN_H
