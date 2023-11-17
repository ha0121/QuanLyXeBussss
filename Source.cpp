#include "Header.h"


QuanLyXeBus::QuanLyXeBus() {
    danhSachCongTy = nullptr;
}

QuanLyXeBus::~QuanLyXeBus() {
    CongTy* currentCongTy = danhSachCongTy;
    while (currentCongTy != nullptr) {
        TuyenXe* currentTuyenXe = currentCongTy->danhSachTuyen;
        while (currentTuyenXe != nullptr) {
            TuyenXe* nextTuyenXe = currentTuyenXe->next;
            delete currentTuyenXe;
            currentTuyenXe = nextTuyenXe;
        }
        CongTy* nextCongTy = currentCongTy->next;
        delete currentCongTy;
        currentCongTy = nextCongTy;
    }
}

void QuanLyXeBus::ThemCongTy() {
    CongTy* newCongTy = new CongTy;
    cout << "Nhap Ma Cong Ty: ";
    cin >> newCongTy->maCongTy;
    cout << "Nhap Ten Cong Ty: ";
    cin.ignore();
    getline(cin, newCongTy->tenCongTy);
    cout << "Nhap Dia Chi Cong Ty: ";
    getline(cin, newCongTy->diaChi);
    newCongTy->danhSachTuyen = nullptr;
    newCongTy->next = danhSachCongTy;
    danhSachCongTy = newCongTy;
}

void QuanLyXeBus::ThemTuyenXe(int maCongTy) {
    CongTy* congTy = TimCongTy(maCongTy);
    if (congTy != nullptr) {
        TuyenXe* newTuyenXe = new TuyenXe;
        cout << "Nhap Ma Tuyen Xe: ";
        cin >> newTuyenXe->maTuyen;
        cout << "Nhap Ten Tuyen Xe: ";
        cin.ignore();
        getline(cin, newTuyenXe->tenTuyen);
        cout << "Nhap Diem Dau: ";
        getline(cin, newTuyenXe->diemDau);
        cout << "Nhap Diem Cuoi: ";
        getline(cin, newTuyenXe->diemCuoi);
        cout << "Nhap Cu Ly: ";
        cin >> newTuyenXe->cuLy;

        newTuyenXe->next = congTy->danhSachTuyen;
        congTy->danhSachTuyen = newTuyenXe;
    }
    else {
        cout << "Khong tim thay Cong Ty co ma " << maCongTy << endl;
    }
}

void QuanLyXeBus::XoaCongTy(int maCongTy) {
    CongTy* prevCongTy = nullptr;
    CongTy* currentCongTy = danhSachCongTy;

    while (currentCongTy != nullptr && currentCongTy->maCongTy != maCongTy) {
        prevCongTy = currentCongTy;
        currentCongTy = currentCongTy->next;
    }

    if (currentCongTy == nullptr) {
        cout << "Khong tim thay Cong Ty co ma " << maCongTy << endl;
        return;
    }

    TuyenXe* currentTuyenXe = currentCongTy->danhSachTuyen;
    while (currentTuyenXe != nullptr) {
        TuyenXe* nextTuyenXe = currentTuyenXe->next;
        delete currentTuyenXe;
        currentTuyenXe = nextTuyenXe;
    }

    if (prevCongTy == nullptr) {
        danhSachCongTy = currentCongTy->next;
    }
    else {
        prevCongTy->next = currentCongTy->next;
    }

    delete currentCongTy;
    cout << "Xoa Cong Ty thanh cong.\n";
}

void QuanLyXeBus::XoaCongTy(string tenCongTy) {
    CongTy* prevCongTy = nullptr;
    CongTy* currentCongTy = danhSachCongTy;

    while (currentCongTy != nullptr && currentCongTy->tenCongTy != tenCongTy) {
        prevCongTy = currentCongTy;
        currentCongTy = currentCongTy->next;
    }

    if (currentCongTy == nullptr) {
        cout << "Khong tim thay Cong Ty co ten " << tenCongTy << endl;
        return;
    }

    TuyenXe* currentTuyenXe = currentCongTy->danhSachTuyen;
    while (currentTuyenXe != nullptr) {
        TuyenXe* nextTuyenXe = currentTuyenXe->next;
        delete currentTuyenXe;
        currentTuyenXe = nextTuyenXe;
    }

    if (prevCongTy == nullptr) {
        danhSachCongTy = currentCongTy->next;
    }
    else {
        prevCongTy->next = currentCongTy->next;
    }

    delete currentCongTy;
    cout << "Xoa Cong Ty thanh cong.\n";
}

TuyenXe* QuanLyXeBus::TimTuyenXe(string tenTuyen) {
    for (CongTy* currentCongTy = danhSachCongTy; currentCongTy != nullptr; currentCongTy = currentCongTy->next) {
        for (TuyenXe* currentTuyenXe = currentCongTy->danhSachTuyen; currentTuyenXe != nullptr; currentTuyenXe = currentTuyenXe->next) {
            if (currentTuyenXe->tenTuyen == tenTuyen) {
                return currentTuyenXe;
            }
        }
    }

    cout << "Khong tim thay Tuyen Xe co ten " << tenTuyen << endl;
    return nullptr;
}

TuyenXe* QuanLyXeBus::TimTuyenXe(int maTuyen) {
    for (CongTy* currentCongTy = danhSachCongTy; currentCongTy != nullptr; currentCongTy = currentCongTy->next) {
        for (TuyenXe* currentTuyenXe = currentCongTy->danhSachTuyen; currentTuyenXe != nullptr; currentTuyenXe = currentTuyenXe->next) {
            if (currentTuyenXe->maTuyen == maTuyen) {
                return currentTuyenXe;
            }
        }
    }

    cout << "Khong tim thay Tuyen Xe co ma " << maTuyen << endl;
    return nullptr;
}

void QuanLyXeBus::HienThiDanhSachCongTy() {
    cout << "===== DANH SACH CONG TY =====\n";
    for (CongTy* currentCongTy = danhSachCongTy; currentCongTy != nullptr; currentCongTy = currentCongTy->next) {
        cout << "Ma Cong Ty: " << currentCongTy->maCongTy << "\n";
        cout << "Ten Cong Ty: " << currentCongTy->tenCongTy << "\n";
        cout << "Dia Chi: " << currentCongTy->diaChi << "\n\n";
    }
}

void QuanLyXeBus::HienThiDanhSachTuyenXe(int maCongTy) {
    CongTy* congTy = TimCongTy(maCongTy);
    if (congTy != nullptr) {
        cout << "===== DANH SACH TUYEN XE CUA CONG TY " << congTy->tenCongTy << " =====\n";
        for (TuyenXe* currentTuyenXe = congTy->danhSachTuyen; currentTuyenXe != nullptr; currentTuyenXe = currentTuyenXe->next) {
            cout << "Ma Tuyen Xe: " << currentTuyenXe->maTuyen << "\n";
            cout << "Ten Tuyen Xe: " << currentTuyenXe->tenTuyen << "\n";
            cout << "Diem Dau: " << currentTuyenXe->diemDau << "\n";
            cout << "Diem Cuoi: " << currentTuyenXe->diemCuoi << "\n";
            cout << "Cu Ly: " << currentTuyenXe->cuLy << "\n\n";
        }
    }
    else {
        cout << "Khong tim thay Cong Ty co ma " << maCongTy << endl;
    }
}

CongTy* QuanLyXeBus::TimCongTy(int maCongTy) {
    for (CongTy* currentCongTy = danhSachCongTy; currentCongTy != nullptr; currentCongTy = currentCongTy->next) {
        if (currentCongTy->maCongTy == maCongTy) {
            return currentCongTy;
        }
    }
    return nullptr;
}

CongTy* QuanLyXeBus::TimCongTy(std::string tenCongTy) {
    for (CongTy* currentCongTy = danhSachCongTy; currentCongTy != nullptr; currentCongTy = currentCongTy->next) {
        if (currentCongTy->tenCongTy == tenCongTy) {
            return currentCongTy;
        }
    }
    return nullptr;
}
