#include <iostream>
#include "Fraction.h"

Fraction::Fraction() { }

Fraction::Fraction(int a, int b) {
	set(a, b);
}

Fraction::~Fraction() { }

void Fraction::set(int a, int b) {
	int g = gcd(a, b);
	m_a = a / g;
	m_b = b / g;

	if (m_b < 0) {
		m_a = -m_a;
		m_b = -m_b;
	}
}

int Fraction::gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int Fraction::lcm(int a, int b) {
	return a * b / gcd(a, b);
}

float Fraction::get() const {
	return (float) m_a / m_b;
}

void Fraction::get(int &a, int &b) const {
	a = m_a;
	b = m_b;
}

int Fraction::getFirst() const {
	return m_a;
}

int Fraction::getSecond() const {
	return m_b;
}

Fraction& Fraction::operator-() {
	m_a = -m_a;
	return *this;
}

Fraction& Fraction::operator+=(Fraction& rhs) {
	int a, b, l;
	rhs.get(a, b);
	l = lcm(b, m_b);
	a *= l / b;
	set((m_a * l / m_b) + a, l);
	return *this;
}

Fraction& Fraction::operator-=(Fraction& rhs) {
	*this += -rhs;
	return *this;
}

Fraction& Fraction::operator*=(Fraction& rhs) {
	int a, b;
	rhs.get(a, b);
	set(m_a * a, m_b * b);
	return *this;
}

Fraction& Fraction::operator/=(Fraction& rhs) {
	int a, b;
	rhs.get(a, b);
	rhs.set(b, a);
	*this *= rhs;
	return *this;
}

Fraction Fraction::operator+(Fraction& f) {
	int a, b;
	f.get(a, b);

	Fraction frac(m_a, m_b);
	frac += f;

	return frac;
}

Fraction Fraction::operator-(Fraction& f) {
	int a, b;
	f.get(a, b);

	Fraction frac(m_a, m_b);
	frac -= f;

	return frac;
}

Fraction Fraction::operator*(Fraction& f) {
	int a, b;
	f.get(a, b);

	Fraction frac(m_a, m_b);
	frac *= f;

	return frac;
}

Fraction Fraction::operator/(Fraction& f) {
	int a, b;
	f.get(a, b);

	Fraction frac(m_a, m_b);
	frac /= f;

	return frac;
}

Fraction& Fraction::operator=(int a) {
	m_a = a;
	m_b = 1;
	return *this;
}

Fraction& Fraction::operator=(int& a) {
	m_a = a;
	m_b = 1;
	return *this;
}

bool Fraction::operator==(Fraction rhs) {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	return rhs_a == m_a && rhs_b == m_b;
}

bool Fraction::operator<(Fraction rhs) {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	l = lcm(m_b, rhs_b);

	return (m_a * (l / m_b)) < (rhs_a * (l / rhs_b));
}

bool Fraction::operator>(Fraction rhs) {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	l = lcm(m_b, rhs_b);

	return (m_a * (l / m_b)) > (rhs_a * (l / rhs_b));
}

bool Fraction::operator<(const Fraction rhs) const {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	l = lcm(m_b, rhs_b);

	return (m_a * (l / m_b)) < (rhs_a * (l / rhs_b));
}

bool Fraction::operator<=(Fraction rhs) {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	l = lcm(m_b, rhs_b);

	return (m_a * (l / m_b)) <= (rhs_a * (l / rhs_b));
}

bool Fraction::operator>=(Fraction rhs) {
	int rhs_a, rhs_b, l;
	rhs.get(rhs_a, rhs_b);

	l = lcm(m_b, rhs_b);

	return (m_a * (l / m_b)) >= (rhs_a * (l / rhs_b));
}