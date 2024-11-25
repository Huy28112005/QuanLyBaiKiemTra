#include <iostream>
#include "TruongHoc.h"

int main() {
	TruongHoc truongHoc;
	truongHoc.nhap();
	truongHoc.xuat();
	cout << "\nTong so bai kiem tra Trac Nghiem: " << truongHoc.demBaiKiemTraTracNghiem();

	return 0;
}