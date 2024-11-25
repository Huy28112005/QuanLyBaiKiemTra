#pragma once
#include "BaiKiemTra.h"
#include "TracNghiem.h"
#include "TuLuan.h"
class Utility
{
public:
	static TracNghiem* toTracNghiem(BaiKiemTra* baiKiemTra) {
		return dynamic_cast<TracNghiem*>(baiKiemTra);
	}

	static TuLuan* toTuLuan(BaiKiemTra* baiKiemTra) {
		return dynamic_cast<TuLuan*>(baiKiemTra);
	}
};

