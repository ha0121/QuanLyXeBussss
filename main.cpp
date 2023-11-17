#include "Header.h"


int main() {
    QuanLyXeBus quanLy;

    int luaChon;

    do {
        cout << "\n===== QUAN LY XE BUS =====\n";
        cout << "1. Them Cong Ty\n";
        cout << "2. Them Tuyen Xe\n";
        cout << "3. Xoa Cong Ty\n";
        cout << "4. Tim Tuyen Xe\n";
        cout << "5. Hien Thi Danh Sach Cong Ty\n";
        cout << "6. Hien Thi Danh Sach Tuyen Xe\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            quanLy.ThemCongTy();
            break;
        case 2:
            // Nhap ma Cong Ty va them Tuyen Xe
            int maCongTy;
            cout << "Nhap ma Cong Ty: ";
            cin >> maCongTy;
            quanLy.ThemTuyenXe(maCongTy);
            break;
        case 3:
            // Xoa Cong Ty
            cout << "1. Xoa theo Ma Cong Ty\n";
            cout << "2. Xoa theo Ten Cong Ty\n";
            int luaChonXoa;
            cin >> luaChonXoa;
            if (luaChonXoa == 1) {
                int maCongTyXoa;
                cout << "Nhap ma Cong Ty can xoa: ";
                cin >> maCongTyXoa;
                quanLy.XoaCongTy(maCongTyXoa);
            }
            else if (luaChonXoa == 2) {
                string tenCongTyXoa;
                cout << "Nhap ten Cong Ty can xoa: ";
                cin.ignore(); // Đọc newline còn tồn đọng từ trước
                getline(cin, tenCongTyXoa);
                quanLy.XoaCongTy(tenCongTyXoa);
            }
            else {
                cout << "Lua chon khong hop le.\n";
            }
            break;
        case 4:
            // Tim Tuyen Xe
            cout << "1. Tim theo Ma Tuyen Xe\n";
            cout << "2. Tim theo Ten Tuyen Xe\n";
            int luaChonTim;
            cin >> luaChonTim;
            if (luaChonTim == 1) {
                int maTuyenTim;
                cout << "Nhap ma Tuyen Xe can tim: ";
                cin >> maTuyenTim;
                quanLy.TimTuyenXe(maTuyenTim);
            }
            else if (luaChonTim == 2) {
                string tenTuyenTim;
                cout << "Nhap ten Tuyen Xe can tim: ";
                cin.ignore(); // Đọc newline còn tồn đọng từ trước
                getline(cin, tenTuyenTim);
                quanLy.TimTuyenXe(tenTuyenTim);
            }
            else {
                cout << "Lua chon khong hop le.\n";
            }
            break;
        case 5:
            quanLy.HienThiDanhSachCongTy();
            break;
        case 6:
            // Hien thi danh sach Tuyen Xe cua Cong Ty
            int maCongTyHienThi;
            cout << "Nhap ma Cong Ty can hien thi: ";
            cin >> maCongTyHienThi;
            quanLy.HienThiDanhSachTuyenXe(maCongTyHienThi);
            break;
        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}
