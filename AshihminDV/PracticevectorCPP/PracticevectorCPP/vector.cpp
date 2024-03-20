#include "vector.h"



TVector::TVector()
{
	std::cout << "TVector::TVector()" << std::endl;
	this->n = 0;
	this->x = nullptr;
}

TVector::TVector(int n)
{
	//std::cout << "TVector::TVector(int n)" << std::endl;
	this->n = n;
	this->x = new double[this->n];
}

TVector::TVector(const TVector & v)
{
	std::cout << "TVector::TVector(const TVector & v)" << std::endl;
	this->n = v.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++) {
		this->x[i] = v.x[i];
	}
}

TVector::~TVector() 
{
	std::cout << "TVector::~TVector()" << std::endl;
	delete[] this->x;
}

TVector TVector::operator+ (const TVector& v)
{
	if (this->n != v.n) 
	{
		throw std::exception("Diff len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res.x[i] = this->x[i] + v.x[i];
	}
	return res;
}

TVector TVector::operator- (const TVector& v)
{
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res.x[i] = this->x[i] - v.x[i];
	}
	return res;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
	//std::cout << "std::istream& operator>>(std::istream& in, TVector& v)" << std::endl;
	std::cout << "Input n: ";
	in >> v.n;
	std::cout << "Input x: ";
	if (v.x != nullptr) {
		delete[] v.x;
	}
	v.x = new double[v.n];
	for (int i = 0; i < v.n; i++)
	{
		in >> v.x[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const TVector& v)
{
	//std::cout << "std::ostream& operator<<(std::ostream& out, const TVector& v)" << std::endl;
	std::cout << "Vector :";

	for (int i = 0; i < v.n; i++)
	{
		out << v.x[i]<< " ";
	}
	std::cout << std::endl;
	return out;
}

const TVector& TVector::operator= (const TVector& v)
{
	std::cout << "TVector& TVector::operator= (const TVector& v)" << std::endl;
	n = v.n;
	for (int i = 0; i < this->n; i++) 
	{
		x[i] = v.x[i];
	}
	return *this;
}

double TVector::operator* (const TVector&v)
{
	if (this->n != v.n)
	{
		throw std::exception("Diff len");
	}
	double res = 0;
	for (int i = 0; i < v.n; i++)
	{
		res += this->x[i] * v.x[i];
	}
	return res;
}
