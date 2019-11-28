#pragma once
#if !defined(_GQ_INTERFACE_H_)
#define _GQ_INTERFACE_H_

#include"gq_utilities.h"

namespace gq_interface {

	using gq_utilities::Range;
	using gq_utilities::IntegratingFun;

	template<typename T,
			typename ...Ts>
	class Integrand {
	private:
		Range<T> xrange_;
		IntegratingFun<T, Ts...> fun_;

	public:
		Integrand(IntegratingFun<T,Ts...> const &integrand,Range<T> const &xrange)
			:fun_{integrand},xrange_{xrange}{}

		Integrand(IntegratingFun<T, Ts...> const &integrand)
			:fun_{ integrand }{}

		virtual ~Integrand(){}

		Integrand(Integrand<T,Ts...> const &copy)
			:fun_{copy.fun_},xrange_{copy.xrange_}{}

		Integrand(Integrand<T, Ts...> &&other)noexcept
			:fun_{ std::move(other.fun_) },
			xrange_{ std::move(other.xrange_) } {
		}

		Integrand& operator=(Integrand<T, Ts...> const &copy) {
			if (this != &copy) {
				fun_ = copy.fun_;
				xrange_ = copy.xrange_;
			}
			return *this;
		}

		Integrand& operator=(Integrand<T, Ts...> &&other)noexcept {
			if (this != &other) {
				fun_ = std::exchange(other.fun_, nullptr);
				xrange_ = std::exchange(other.xrange_, Range<T>());
			}
			return *this;
		}

		inline T lowerLimit()const { return xrange_.low(); }
		inline T upperLimit()const { return xrange_.high(); }
		inline T mid()const { return xrange_.mid(); }

		T operator()(Ts... args) {
			return fun_(args...);
		}

	};





}




#endif //_GQ_INTERFACE_H_