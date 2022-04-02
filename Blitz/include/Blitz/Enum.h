#pragma once

#include <type_traits>
#include <initializer_list>

namespace Blitz {

template<typename E, typename I = std::underlying_type<E>>
class Enum
{
public:
	E value;

	inline constexpr Enum():
		value(static_cast<E>(0))
	{}

	inline constexpr Enum(E value) :
		value(value)
	{}

	inline constexpr Enum(I value) :
		value(static_cast<E>(value))
	{}

	inline constexpr Enum& operator=(E v) { value = v; return *this; }
	inline constexpr Enum& operator=(I v) { value = v; return *this; }

	inline constexpr I AsInt() const { return static_cast<I>(value); }
	inline constexpr I& AsInt() { return static_cast<I>(value); }
	inline constexpr E AsEnum() const { return value; }
	inline constexpr E& AsEnum() { return value; }

	inline constexpr operator I() const { return AsInt(); }
	inline constexpr operator I& () { return AsInt(); }
	inline constexpr operator E() const { return value; }
	inline constexpr operator E& () const { return value; }
};

template<typename E, typename I = std::underlying_type<E>>
class Flags : public Enum<E, I>
{
public:
	using Enum<E, I>::Enum;

	inline constexpr Flags(std::initializer_list<E> flags)
	{
		I& v = this->AsInt();
		for (auto flag : flags)
			v |= static_cast<I>(flag);
	}

	inline constexpr Flags& operator
};

}