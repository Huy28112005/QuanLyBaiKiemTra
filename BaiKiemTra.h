#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define endl "\n"
#define rows2 "\n\n"

class BaiKiemTra
{
protected:
	unsigned int maMonHoc;
	unsigned int thoiGian;
public:
	BaiKiemTra() : maMonHoc(0), thoiGian(0){}
	BaiKiemTra(unsigned int maMonHoc, unsigned int thoiGian) : maMonHoc(maMonHoc),thoiGian(thoiGian){}
	~BaiKiemTra() = default;
	// getter setter
	void setMaMonHoc(unsigned int maMHoc) { maMonHoc = maMHoc; }
	unsigned int getMaMonHoc() const { return maMonHoc; }

	void setThoiGian(unsigned int tGian) { thoiGian = tGian; }
	unsigned int getThoiGian() const { return thoiGian; }
	// nhap xuat
	virtual void nhap() {
		cout << "\nNhap Ma Mon Hoc: "; cin >> maMonHoc;
		cout << "\nNhap Thoi Gian lam bai: "; cin >> thoiGian;
	}
	virtual void xuat() const {
		cout << "\nMa Mon Hoc: " << maMonHoc << rows2;
		cout << "Thoi gian lam bai: " << thoiGian << " phut" << rows2;
	}
	virtual BaiKiemTra* clone() const {
		return new BaiKiemTra(*this);
	}
	virtual float getDiemKiemTra() const {
		return 0.0f;
	}
};

