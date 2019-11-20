#pragma once
#if !defined(_GQ_LEGENDRE_T_H_)
#define _GQ_LEGENDRE_T_H_

#include"gq_utilities.h"
#include"gq_legendre.h"


void integrateExp5() {

	using gq_legendre::GQLegendre;
	using gq_legendre::Integrand;
	using gq_utilities::Range;
	using gq_legendre::NPoint;

	auto integratingFun = [](double x) {return std::exp(5 * x); };
	auto integrationDomain = Range<double>{ 0.0,5.0 };
	Integrand<double, double> integrand{ integratingFun,integrationDomain };

	// 6-point Gauss-Legendre
	auto integral6 = GQLegendre<NPoint::_6, double>{ integrand };
	// 10-point Gauss-Legendre
	GQLegendre<NPoint::_10, double> integral10{ integrand };
	// 20-point Gauss-Legendre
	auto integral20 = GQLegendre<NPoint::_20, double>{ integrand };

	std::cout << "Exact value of int_{0}^{5}{exp(5*x)dx} = " << (1.0 / 5.0)*(std::exp(25.0) - 1.0) << "\n";
	std::cout << "6-point Gauss-Legendre integral value: " << integral6() << "\n";
	std::cout << "10-point Gauss-Legendre integral value: " << integral10() << "\n";
	std::cout << "20-point Gauss-Legendre integral value: " << integral20() << "\n";
	


}




#endif //_GQ_LEGENDRE_T_H_