#pragma once
#if !defined(_GQ_HERMITE_T_H_)
#define _GQ_HERMITE_T_H_

#include<iostream>
#include"gq_utilities.h"
#include"gq_hermite.h"


void integrateExp() {

	using gq_hermite::GQHermite;
	using gq_interface::Integrand;
	using gq_utilities::Range;
	using gq_utilities::PI;
	using gq_hermite::NPoint;

	auto integratingFun = [](double x) {return (x*x*std::exp(-1.0*x*x)); };
	Integrand<double, double> integrand{ integratingFun };

	// 2-point Gauss-Hermite
	auto integral2 = GQHermite<NPoint::_2, double>{ integrand };
	// 4-point Gauss-Hermite
	auto integral4 = GQHermite<NPoint::_4, double>{ integrand };
	// 6-point Gauss-Hermite
	auto integral6 = GQHermite<NPoint::_6, double>{ integrand };
	// 8-point Gauss-Hermite
	auto integral8 = GQHermite<NPoint::_8, double>{ integrand };
	// 10-point Gauss-Hermite
	GQHermite<NPoint::_10, double> integral10{ integrand };
	// 12-point Gauss-Hermite
	GQHermite<NPoint::_12, double> integral12{ integrand };
	// 14-point Gauss-Hermite
	GQHermite<NPoint::_14, double> integral14{ integrand };
	// 16-point Gauss-Hermite
	GQHermite<NPoint::_16, double> integral16{ integrand };
	// 18-point Gauss-Hermite
	GQHermite<NPoint::_18, double> integral18{ integrand };
	// 20-point Gauss-Hermite
	auto integral20 = GQHermite<NPoint::_20, double>{ integrand };

	std::cout << "Exact value of int_{-infty}^{infty}{x*x*exp(-1.0*x*x)dx} = " << 0.5*std::sqrt(PI) << "\n";
	std::cout << "2-point Gauss-Hermite integral value: " << integral2() << "\n";
	std::cout << "4-point Gauss-Hermite integral value: " << integral4() << "\n";
	std::cout << "6-point Gauss-Hermite integral value: " << integral6() << "\n";
	std::cout << "8-point Gauss-Hermite integral value: " << integral8() << "\n";
	std::cout << "10-point Gauss-Hermite integral value: " << integral10() << "\n";
	std::cout << "12-point Gauss-Hermite integral value: " << integral12() << "\n";
	std::cout << "14-point Gauss-Hermite integral value: " << integral14() << "\n";
	std::cout << "16-point Gauss-Hermite integral value: " << integral16() << "\n";
	std::cout << "18-point Gauss-Hermite integral value: " << integral18() << "\n";
	std::cout << "20-point Gauss-Hermite integral value: " << integral20() << "\n";
	std::cout << "\n\n";


}




#endif //_GQ_LEGENDRE_T_H_