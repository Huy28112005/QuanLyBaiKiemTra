#pragma once
#include "BaiKiemTra.h"

class TracNghiem : public BaiKiemTra
{
private:
	unsigned int tongSoCau;
	unsigned int soCauDung;
public:
	TracNghiem() : BaiKiemTra(), tongSoCau(0), soCauDung(0){}
	TracNghiem(unsigned int tongSoCau, unsigned soCauDung, unsigned int maMonHoc, unsigned int thoiGian)
		: BaiKiemTra(maMonHoc, thoiGian), tongSoCau(tongSoCau), soCauDung(soCauDung) {}
	~TracNghiem() = default;
	// getter setter
	void setTongSoCau(unsigned int soCau) { tongSoCau = soCau; }
	unsigned int getTongSoCau() const { return tongSoCau; }

	void setSoCauDung(unsigned int cauDung) { soCauDung = cauDung; }
	unsigned int getSoCauDung() const { return soCauDung; }
	// nhap xuat
	void nhap() override {
		BaiKiemTra::nhap();
		cout << "\nNhap Tong So Cau hoi: "; cin >> tongSoCau;
		cout << "\nNhap So Cau Dung: "; cin >> soCauDung;
	}
	void xuat() const override {
		BaiKiemTra::xuat();
		cout << "Tong so Cau hoi: " << tongSoCau << rows2;
		cout << "So cau lam dung: " << soCauDung << rows2;
		cout << "Diem kiem tra: " << getDiemKiemTra() << rows2;
	}
	float getDiemKiemTra() const {
		return float(soCauDung) / tongSoCau * 10.0f;
	}
	TracNghiem* clone() const override {
		return new TracNghiem(*this);
	}
};

