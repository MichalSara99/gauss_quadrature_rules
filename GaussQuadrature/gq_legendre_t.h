#pragma once
#if !defined(_GQ_LEGENDRE_T_H_)
#define _GQ_LEGENDRE_T_H_

#include"gq_utilities.h"
#include"gq_legendre.h"


void integrateExp5Legendre() {

	using gq_legendre::GQLegendre;
	using gq_legendre::Integrand;
	using gq_utilities::Range;
	using gq_legendre::NPoint;

	auto integratingFun = [](double x) {return std::exp(5 * x); };
	auto integrationDomain = Range<double>{ 0.0,5.0 };
	Integrand<double, double> integrand{ integratingFun,integrationDomain };

	// 2-point Gauss-Legendre
	auto integral2 = GQLegendre<NPoint::_2, double>{ integrand };
	// 4-point Gauss-Legendre
	auto integral4 = GQLegendre<NPoint::_4, double>{ integrand };
	// 6-point Gauss-Legendre
	auto integral6 = GQLegendre<NPoint::_6, double>{ integrand };
	// 8-point Gauss-Legendre
	auto integral8 = GQLegendre<NPoint::_8, double>{ integrand };
	// 10-point Gauss-Legendre
	GQLegendre<NPoint::_10, double> integral10{ integrand };
	// 12-point Gauss-Legendre
	GQLegendre<NPoint::_12, double> integral12{ integrand };
	// 14-point Gauss-Legendre
	GQLegendre<NPoint::_14, double> integral14{ integrand };
	// 16-point Gauss-Legendre
	GQLegendre<NPoint::_16, double> integral16{ integrand };
	// 18-point Gauss-Legendre
	GQLegendre<NPoint::_18, double> integral18{ integrand };
	// 20-point Gauss-Legendre
	auto integral20 = GQLegendre<NPoint::_20, double>{ integrand };

	std::cout << "Exact value of int_{0}^{5}{exp(5*x)dx} = " << (1.0 / 5.0)*(std::exp(25.0) - 1.0) << "\n";
	std::cout << "2-point Gauss-Legendre integral value: " << integral2() << "\n";
	std::cout << "4-point Gauss-Legendre integral value: " << integral4() << "\n";
	std::cout << "6-point Gauss-Legendre integral value: " << integral6() << "\n";
	std::cout << "8-point Gauss-Legendre integral value: " << integral8() << "\n";
	std::cout << "10-point Gauss-Legendre integral value: " << integral10() << "\n";
	std::cout << "12-point Gauss-Legendre integral value: " << integral12() << "\n";
	std::cout << "14-point Gauss-Legendre integral value: " << integral14() << "\n";
	std::cout << "16-point Gauss-Legendre integral value: " << integral16() << "\n";
	std::cout << "18-point Gauss-Legendre integral value: " << integral18() << "\n";
	std::cout << "20-point Gauss-Legendre integral value: " << integral20() << "\n";
	std::cout << "\n\n";


}




#endif //_GQ_LEGENDRE_T_H_