#pragma once
#if !defined(_GQ_LOBATTO_T_H_)
#define _GQ_LOBATTO_T_H_

#include"gq_utilities.h"
#include"gq_lobatto.h"
#include<iostream>

void integrateExp5Lobatto() {

	using gq_lobatto::GQLobatto;
	using gq_lobatto::Integrand;
	using gq_utilities::Range;
	using gq_lobatto::NPoint;

	auto integratingFun = [](double x) {return std::exp(5 * x); };
	auto integrationDomain = Range<double>{ 0.0,5.0 };
	Integrand<double, double> integrand{ integratingFun,integrationDomain };

	// 2-point Gauss-Lobatto
	auto integral2 = GQLobatto<NPoint::_2, double>{ integrand };
	// 4-point Gauss-Lobatto
	auto integral4 = GQLobatto<NPoint::_4, double>{ integrand };
	// 6-point Gauss-Lobatto
	auto integral6 = GQLobatto<NPoint::_6, double>{ integrand };
	// 8-point Gauss-Lobatto
	auto integral8 = GQLobatto<NPoint::_8, double>{ integrand };
	// 10-point Gauss-Lobatto
	GQLobatto<NPoint::_10, double> integral10{ integrand };
	// 12-point Gauss-Lobatto
	GQLobatto<NPoint::_12, double> integral12{ integrand };
	// 14-point Gauss-Lobatto
	GQLobatto<NPoint::_14, double> integral14{ integrand };
	// 16-point Gauss-Lobatto
	GQLobatto<NPoint::_16, double> integral16{ integrand };
	// 18-point Gauss-Lobatto
	GQLobatto<NPoint::_18, double> integral18{ integrand };
	// 20-point Gauss-Lobatto
	auto integral20 = GQLobatto<NPoint::_20, double>{ integrand };

	std::cout << "Exact value of int_{0}^{5}{exp(5*x)dx} = " << (1.0 / 5.0)*(std::exp(25.0) - 1.0) << "\n";
	std::cout << "2-point Gauss-Lobatto integral value: " << integral2() << "\n";
	std::cout << "4-point Gauss-Lobatto integral value: " << integral4() << "\n";
	std::cout << "6-point Gauss-Lobatto integral value: " << integral6() << "\n";
	std::cout << "8-point Gauss-Lobatto integral value: " << integral8() << "\n";
	std::cout << "10-point Gauss-Lobatto integral value: " << integral10() << "\n";
	std::cout << "12-point Gauss-Lobatto integral value: " << integral12() << "\n";
	std::cout << "14-point Gauss-Lobatto integral value: " << integral14() << "\n";
	std::cout << "16-point Gauss-Lobatto integral value: " << integral16() << "\n";
	std::cout << "18-point Gauss-Lobatto integral value: " << integral18() << "\n";
	std::cout << "20-point Gauss-Lobatto integral value: " << integral20() << "\n";
	std::cout << "\n\n";


}


void simpleIntegralsLobatto() {

	using gq_lobatto::GQLobatto;
	using gq_legendre::Integrand;
	using gq_utilities::Range;
	using gq_legendre::NPoint;

	auto inverseFun = [](double x) {return (1.0 / x); };
	auto poly = [](double x) {return (1.0 + x * x); };

	auto firstDomain = Range<double>{ 1.0,2.0 };
	auto secondDomain = Range<double>{ 0.0,10.0 };

	Integrand<double, double> firstIntegrand{ inverseFun,firstDomain };
	Integrand<double, double> secondIntegrand{ poly,secondDomain };

	auto integral_1 = GQLobatto<NPoint::_10, double>{ firstIntegrand };
	auto integral_2 = GQLobatto<NPoint::_10, double>{ secondIntegrand };

	std::cout << "10-point Gauss-Lobatto integral value: " << integral_1() << "\n";
	std::cout << "10-point Gauss-Lobatto integral value: " << integral_2() << "\n";
	std::cout << "===========================================\n";
}


void fresnelIntegralsLobatto() {

	using gq_lobatto::GQLobatto;
	using gq_utilities::PI;
	using gq_utilities::Range;
	using gq_utilities::NPoint;
	using gq_interface::Integrand;

	// Prepare integrands for fresnel integrals:
	auto sinFun = [](double t) {return std::sin(0.5*PI*t*t); };
	auto cosFun = [](double t) {return std::cos(0.5*PI*t*t); };

	// Sine Fresnel integral:
	// S(x) = int_{0}^{x}{sin(0.5*pi*t*t)dt}
	auto S = [&](double x) {
		auto range = Range<double>{ 0.0,x };
		auto integral = GQLobatto<NPoint::_20, double>{ Integrand<double, double>{ sinFun,range } };
		return integral();
	};

	// Cosine Fresnel integral:
	// C(x) = int_{0}^{x}{cos(0.5*pi*t*t)dt}
	auto C = [&](double x) {
		auto range = Range<double>{ 0.0,x };
		auto integral = GQLobatto<NPoint::_20, double>{ Integrand<double, double>{ cosFun,range } };
		return integral();
	};

	std::cout << "Sine Fresnel integral:\n";
	std::cout << "True value S(6.0) = " << 0.44696 << "\n";
	std::cout << "Approximated value S(6.0) = " << S(6.0) << "\n";
	std::cout << "True value S(6.40) = " << 0.49646 << "\n";
	std::cout << "Approximated value S(6.40) = " << S(6.40) << "\n";
	std::cout << "========================================================\n";
}




#endif //_GQ_LEGENDRE_T_H_