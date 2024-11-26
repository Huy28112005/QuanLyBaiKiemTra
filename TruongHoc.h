#pragma once
#include "BaiKiemTra.h"
#include <string>
#include <vector>
#include <cctype>
#include "Utility.h"

class TruongHoc
{
private:
	unsigned int soLuong;
	BaiKiemTra** baiKiemTra;

	void clear() {
		for (unsigned int i = 0; i < soLuong; ++i)
			delete baiKiemTra[i];
		delete[] baiKiemTra;
		baiKiemTra = nullptr;
	}

	string toLower(const string& str) {
		string lowerStr = str;
		transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](char x) {
			return tolower(x);
			});
		return lowerStr;
	}
public:
	TruongHoc() : soLuong(0), baiKiemTra(nullptr){}
	TruongHoc(unsigned int soLuong, BaiKiemTra** kiemTra) : soLuong(soLuong) {
		baiKiemTra = new BaiKiemTra * [soLuong];
		transform(kiemTra, kiemTra + soLuong, baiKiemTra, [](BaiKiemTra* ptr) {
			return ptr->clone();
			});
	}
	// copy
	TruongHoc(const TruongHoc& truong) : soLuong(truong.soLuong) {
		baiKiemTra = new BaiKiemTra * [soLuong];
		transform(truong.baiKiemTra, truong.baiKiemTra + soLuong, baiKiemTra, [](BaiKiemTra* a) {
			return a->clone();
			});
	}
	TruongHoc& operator=(const TruongHoc& truong) {
		if (this != &truong) {
			clear();
			soLuong = truong.soLuong;
			baiKiemTra = new BaiKiemTra * [soLuong];
			transform(truong.baiKiemTra, truong.baiKiemTra + soLuong, baiKiemTra, [](BaiKiemTra* a) {
				return a->clone();
				});
		}
		return *this;
	}
	~TruongHoc() {
		clear();
	}
	// getter setter
	void setSoLuong(unsigned int sl) { soLuong = sl; }
	unsigned int getSoLuong() const {
		return soLuong;
	}

	void setBaiKiemTra(unsigned int sl, BaiKiemTra** kiemTra) {
		clear();
		soLuong = sl;
		baiKiemTra = new BaiKiemTra * [soLuong];
		for (unsigned int i = 0; i < soLuong; ++i)
			baiKiemTra[i] = kiemTra[i]->clone();
	}
	BaiKiemTra** getBaiKiemTra() const { return baiKiemTra; }
	// nhap xuat
	void nhap() {
		cout << "\nNhap so luong bai kiem tra: "; cin >> soLuong;
		if (soLuong == 0) return;
		baiKiemTra = new BaiKiemTra * [soLuong];
		for (int i = 0; unsigned int(i) < soLuong; ++i) {
			cin.ignore();
			string loai;
			cout << "\nNhap loai bai kiem tra: ";
			getline(cin, loai);
			loai = toLower(loai);
			if (loai == "trac nghiem") {
				baiKiemTra[i] = new TracNghiem();
			}
			else if (loai == "tu luan") {
				baiKiemTra[i] = new TuLuan();
			}
			else {
				cout << "\nNhap sai loai bai kiem tra!";
				--i;
				continue;
			}
			baiKiemTra[i]->nhap();
		}
	}

	void xuat() const {
		cout << "\nSo luong bai kiem tra: " << soLuong << rows2;
		for (unsigned int i = 0; i < soLuong; ++i) {
			baiKiemTra[i]->xuat();
			cout << "-----------------" << rows2;
		}
	}

	unsigned int demBaiKiemTraTracNghiem() const {
		if (soLuong == 0) return 0;
		unsigned int dem = 0;
		for (unsigned int i = 0; i < soLuong; ++i) {
			TracNghiem* tn = Utility::toTracNghiem(baiKiemTra[i]);
			if (tn != nullptr) {
				++dem;
			}
		}
		return dem;
	}
};