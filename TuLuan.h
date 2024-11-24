#pragma once
#include "BaiKiemTra.h"

class TuLuan : public BaiKiemTra
{
private:
	float diemKiemTra;
public:
	TuLuan() : BaiKiemTra(), diemKiemTra(0.0f){}
	TuLuan(float diemKiemTra, unsigned int maMonHoc, unsigned int thoiGian)
		: BaiKiemTra(maMonHoc,thoiGian), diemKiemTra(diemKiemTra){}
	~TuLuan() = default;
	// getter setter
	void setDiem(float diemKtra) { diemKiemTra= diemKtra; }
	float getDiemKiemTra() const { return diemKiemTra; }
	// nhap xuat
	void nhap() override {
		BaiKiemTra::nhap();
		cout << "\nNhap diem kiem tra: "; cin >> diemKiemTra;
	}
	void xuat() const override {
		BaiKiemTra::xuat();
		cout << setprecision(2) << fixed;
		cout << "Diem Kiem Tra: " << diemKiemTra << rows2;
	}
	TuLuan* clone() const override {
		return new TuLuan(*this);
	}
};

