#pragma once
#if !defined(_GQ_UTILITIES_H_)
#define _GQ_UTILITIES_H_

#include<type_traits>
#include<utility>
#include<functional>


namespace gq_utilities {

	// PI constant (50 decimal places)
	constexpr double PI{ 3.14159265358979323846264338327950288419716939937510 };

	// Integrand
	template<typename T,typename ...Ts>
	using IntegratingFun = std::function<T(Ts...)>;

	// n-point
	enum class NPoint {
		_2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12,
		_13, _14, _15, _16, _17, _18, _19, _20, _21
	};

	// kind
	enum class Kind { _1st, _2nd };


	// Integration domain
	template<typename T = double,
		typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
		class Range {
		private:
			T low_, high_;
		public:
			Range(T low, T high)
				:low_{ low }, high_{ high } {}
			Range()
				:low_{ T{} }, high_{ T{} } {}

			virtual ~Range() {}

			Range(Range<T> const &copy)
				:low_{ copy.low_ }, high_{ copy.high_ } {}

			Range(Range<T> &&other)noexcept
				:low_{ std::move(other.low_) },
				high_{ std::move(other.high_) } {}

			Range& operator=(Range<T> const &copy) {
				if (this != &copy) {
					low_ = copy.low_;
					high_ = copy.high_;
				}
				return *this;
			}

			Range& operator=(Range<T> &&other)noexcept {
				if (this != &other) {
					low_ = std::exchange(other.low_, T{});
					high_ = std::exchange(other.high_, T{});
				}
				return *this;
			}

			inline T low()const { return low_; }
			inline T high()const { return high_; }
			inline T spread()const { return (high_ - low_); }
			inline T mid()const { return (0.5*(high_ + low_)); }

	};



}






#endif ///_GQ_UTILITIES_H_


