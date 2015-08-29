#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
	int m_a, m_b;

public:
	Fraction();
	Fraction(int a, int b);
	~Fraction();

	void set(int a, int b);
	float get() const;
	void get(int &a, int &b) const;
	
	int getFirst() const;
	int getSecond() const;

	Fraction& operator-();
	
	Fraction& operator+=(Fraction& rhs);
	Fraction& operator-=(Fraction& rhs);
	Fraction& operator*=(Fraction& rhs);
	Fraction& operator/=(Fraction& rhs);

	Fraction operator+(Fraction& f);
	Fraction operator-(Fraction& f);
	Fraction operator*(Fraction& f);
	Fraction operator/(Fraction& f);

	Fraction& operator=(int a);
	Fraction& operator=(int& a);
	
	bool operator==(Fraction rhs);
	bool operator<(Fraction rhs);
	bool operator>(Fraction rhs);

	bool operator<(const Fraction rhs) const;

	bool operator<=(Fraction rhs);
	bool operator>=(Fraction rhs);

	static int gcd(int a, int b);
	static int lcm(int a, int b);
};

#endif
