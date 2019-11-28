#pragma once
#if !defined(_GQ_LEGENDRE_H_)
#define _GQ_LEGENDRE_H_


#include"gq_interface.h"
#include"gq_legendre_data.h"
#include<vector>

namespace gq_legendre {

	using gq_interface::Integrand;
	using gq_utilities::NPoint;

	template<NPoint points,
			typename T,
			typename ...Ts>
	class GQLegendreBuilder {
	private:
		void mapping();
	protected:
		std::vector<T> weights_;
		std::vector<T> nodes_;
		Integrand<T, Ts...> integrand_;

	public:
		GQLegendreBuilder(Integrand<T,Ts...> const &integrand)
			:integrand_{integrand}{
			mapping();
		}

		virtual T operator()() = 0;
	};



	template<NPoint points,
			typename T,
			typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	class GQLegendre : public GQLegendreBuilder<points,T,T> {
	public:
		explicit GQLegendre(Integrand<T,T> const &integrand)
			:GQLegendreBuilder<points,T,T>(integrand){}

		T operator()()override {
			std::size_t N = this->weights_.size();
			T result{};
			T low{ this->integrand_.lowerLimit() };
			T high{ this->integrand_.upperLimit() };
			T a{ 0.5*(high - low) };
			T b{ 0.5*(high + low) };
			T x{};
			for (std::size_t t = 0; t < N; ++t) {
				x = std::fma(a, this->nodes_.at(t), b);
				result += ((this->integrand_(x)) *(this->weights_.at(t)));
			}
			return (a * result);
		}
	};
	
	template<NPoint points,
			typename T,
			typename ...Ts>
	void GQLegendreBuilder<points,T,Ts...>::mapping() {
		switch (points) {
		case NPoint::_2:
			weights_ = w2;
			nodes_ = n2;
			break;
		case NPoint::_4:
			weights_ = w4;
			nodes_ = n4;
			break;
		case NPoint::_6:
			weights_ = w6;
			nodes_ = n6;
			break;
		case NPoint::_8:
			weights_ = w8;
			nodes_ = n8;
			break;
		case NPoint::_10:
			weights_ = w10;
			nodes_ = n10;
			break;
		case NPoint::_12:
			weights_ = w12;
			nodes_ = n12;
			break;
		case NPoint::_14:
			weights_ = w14;
			nodes_ = n14;
			break;
		case NPoint::_16:
			weights_ = w16;
			nodes_ = n16;
			break;
		case NPoint::_18:
			weights_ = w18;
			nodes_ = n18;
			break;
		case NPoint::_20:
			weights_ = w20;
			nodes_ = n20;
			break;
		}
	}
	
}





#endif ///_GQ_LEGENDRE_H_