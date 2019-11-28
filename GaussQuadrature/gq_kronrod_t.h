#pragma once
#if !defined(_GQ_KRONROD_T_H_)
#define _GQ_KRONROD_T_H_

#include<iostream>
#include"gq_utilities.h"
#include"gq_kronrod.h"


void integrateExp5Kronrod() {

	using gq_kronrod::GQKronrod;
	using gq_kronrod::Integrand;
	using gq_utilities::Range;
	using gq_kronrod::NPoint;

	auto integratingFun = [](double x) {return std::exp(5 * x); };
	auto integrationDomain = Range<double>{ 0.0,5.0 };
	Integrand<double, double> integrand{ integratingFun,integrationDomain };

	// 3-point Gauss-Kronrod
	auto integral3 = GQKronrod<NPoint::_3, double>{ integrand };
	// 5-point Gauss-Kronrod
	auto integral5 = GQKronrod<NPoint::_5, double>{ integrand };
	// 7-point Gauss-Kronrod
	auto integral7 = GQKronrod<NPoint::_7, double>{ integrand };
	// 9-point Gauss-Kronrod
	auto integral9 = GQKronrod<NPoint::_9, double>{ integrand };
	// 11-point Gauss-Kronrod
	GQKronrod<NPoint::_11, double> integral11{ integrand };
	// 13-point Gauss-Kronrod
	GQKronrod<NPoint::_13, double> integral13{ integrand };
	// 15-point Gauss-Kronrod
	GQKronrod<NPoint::_15, double> integral15{ integrand };
	// 17-point Gauss-Kronrod
	GQKronrod<NPoint::_17, double> integral17{ integrand };
	// 19-point Gauss-Kronrod
	GQKronrod<NPoint::_19, double> integral19{ integrand };
	// 21-point Gauss-Kronrod
	auto integral21 = GQKronrod<NPoint::_21, double>{ integrand };

	std::cout << "Exact value of int_{0}^{5}{exp(5*x)dx} = " << (1.0 / 5.0)*(std::exp(25.0) - 1.0) << "\n";
	std::cout << "3-point Gauss-Kronrod integral value: " << integral3() << "\n";
	std::cout << "5-point Gauss-Kronrod integral value: " << integral5() << "\n";
	std::cout << "7-point Gauss-Kronrod integral value: " << integral7() << "\n";
	std::cout << "9-point Gauss-Kronrod integral value: " << integral9() << "\n";
	std::cout << "11-point Gauss-Kronrod integral value: " << integral11() << "\n";
	std::cout << "13-point Gauss-Kronrod integral value: " << integral13() << "\n";
	std::cout << "15-point Gauss-Kronrod integral value: " << integral15() << "\n";
	std::cout << "17-point Gauss-Kronrod integral value: " << integral17() << "\n";
	std::cout << "19-point Gauss-Kronrod integral value: " << integral19() << "\n";
	std::cout << "21-point Gauss-Kronrod integral value: " << integral21() << "\n";
	std::cout << "\n\n";


}




#endif //_GQ_KRONROD_T_H_