#pragma once

#include <Blitz/Common.h>

namespace Blitz {

template<typename T>
struct Rect
{
	T x, y, w, h;

	inline constexpr Rect(T x, T y, T w, T h):
		x(x), y(y), w(w), h(h)
	{}
};

}