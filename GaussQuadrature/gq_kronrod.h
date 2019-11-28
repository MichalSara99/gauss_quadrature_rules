#pragma once
#if !defined(_GQ_KRONROD_H_)
#define _GQ_KRONROD_H_


#include"gq_interface.h"
#include"gq_kronrod_data.h"
#include<vector>

namespace gq_kronrod {

	using gq_interface::Integrand;
	using gq_utilities::NPoint;

	template<NPoint points,
		typename T,
		typename ...Ts>
		class GQKronrodBuilder {
		private:
			void mapping();
		protected:
			std::vector<T> weights_;
			std::vector<T> nodes_;
			Integrand<T, Ts...> integrand_;

		public:
			GQKronrodBuilder(Integrand<T, Ts...> const &integrand)
				:integrand_{ integrand } {
				mapping();
			}

			virtual T operator()() = 0;
	};



	template<NPoint points,
		typename T,
		typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
		class GQKronrod : public GQKronrodBuilder<points, T, T> {
		public:
			explicit GQKronrod(Integrand<T, T> const &integrand)
				:GQKronrodBuilder<points, T, T>(integrand) {}

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
		void GQKronrodBuilder<points, T, Ts...>::mapping() {
		switch (points) {
		case NPoint::_3:
			weights_ = w3;
			nodes_ = n3;
			break;
		case NPoint::_5:
			weights_ = w5;
			nodes_ = n5;
			break;
		case NPoint::_7:
			weights_ = w7;
			nodes_ = n7;
			break;
		case NPoint::_9:
			weights_ = w9;
			nodes_ = n9;
			break;
		case NPoint::_11:
			weights_ = w11;
			nodes_ = n11;
			break;
		case NPoint::_13:
			weights_ = w13;
			nodes_ = n13;
			break;
		case NPoint::_15:
			weights_ = w15;
			nodes_ = n15;
			break;
		case NPoint::_17:
			weights_ = w17;
			nodes_ = n17;
			break;
		case NPoint::_19:
			weights_ = w19;
			nodes_ = n19;
			break;
		case NPoint::_21:
			weights_ = w21;
			nodes_ = n21;
			break;
		}
	}

}





#endif ///_GQ_KRONROD_H_