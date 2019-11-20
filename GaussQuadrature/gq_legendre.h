#pragma once
#if !defined(_GQ_LEGENDRE_H_)
#define _GQ_LEGENDRE_H_


#include"gq_interface.h"
#include<vector>

namespace gq_legendre {

	using gq_interface::Integrand;

	namespace {

		static const std::vector<double> w6 = { 0.3607615730481386,
			0.3607615730481386, 0.4679139345726910, 0.4679139345726910,
			0.1713244923791704, 0.1713244923791704 };

		static const std::vector<double> n6 = { 0.6612093864662645,
			-0.6612093864662645, -0.2386191860831969, 0.2386191860831969,
			-0.9324695142031521, 0.9324695142031521 };

		static const std::vector<double> w10 = { 0.2955242247147529,
			0.2955242247147529, 0.2692667193099963, 0.2692667193099963,
			0.2190863625159820, 0.2190863625159820, 0.1494513491505806,
			0.1494513491505806, 0.0666713443086881, 0.0666713443086881 };

		static const std::vector<double> n10 = { -0.1488743389816312,
			0.1488743389816312, -0.4333953941292472, 0.4333953941292472,
			-0.6794095682990244, 0.6794095682990244, -0.8650633666889845,
			0.8650633666889845, -0.9739065285171717, 0.9739065285171717 };

		static const std::vector<double> n20 = { -0.0765265211334973,
			0.0765265211334973, -0.2277858511416451, 0.2277858511416451,
			-0.3737060887154195,0.3737060887154195, -0.5108670019508271,
			0.5108670019508271, -0.6360536807265150, 0.6360536807265150,
			-0.7463319064601508, 0.7463319064601508, -0.8391169718222188,
			0.8391169718222188, -0.9122344282513259, 0.9122344282513259,
			-0.9639719272779138, 0.9639719272779138, -0.9931285991850949,
			0.9931285991850949 };
		static const std::vector<double> w20 = { 0.1527533871307258,
			0.1527533871307258, 0.1491729864726037, 0.1491729864726037,
			0.1420961093183820, 0.1420961093183820, 0.1316886384491766,
			0.1316886384491766, 0.1181945319615184, 0.1181945319615184,
			0.1019301198172404,0.1019301198172404, 0.0832767415767048,
			0.0832767415767048, 0.0626720483341091, 0.0626720483341091,
			0.0406014298003869, 0.0406014298003869, 0.0176140071391521,
			0.0176140071391521 };
	}


	enum class NPoint { _6, _10, _20 };

	template<NPoint points,
			typename T,
			typename ...Ts>
	class GQLegendreBuilder {
	protected:
		std::vector<T> weights_;
		std::vector<T> nodes_;
		Integrand<T, Ts...> integrand_;

	public:
		GQLegendreBuilder(Integrand<T,Ts...> const &integrand)
			:integrand_{integrand}{

			switch (points) {
			case NPoint::_10:
				weights_ = w10;
				nodes_ = n10;
				break;
			case NPoint::_20:
				weights_ = w20;
				nodes_ = n20;
				break;
			case NPoint::_6:
				weights_ = w6;
				nodes_ = n6;
				break;
			}
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







}





#endif ///_GQ_LEGENDRE_H_