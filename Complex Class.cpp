/*
concepts in this project:
=========================
-operator overloading
-many implementations for the same operator
-friend function
-"<<" operator

what this project can do:
=========================
addition, subtraction, multiplication, division of complex numbers (with their respective operators)
numbers can be of any orders (when mixing floats and complex numbers)
can print out complex numbers using cout operator "<<"
*/
#include <iostream>
using namespace std;

class Complex
{
	float real;
	float imag;
public:
	friend ostream& operator<< (ostream& o, Complex c);
	friend Complex operator+(float f, Complex c);
	friend Complex operator-(float f, Complex c);
	friend Complex operator/(float f, Complex C);
	//setters - getters - constructor
	Complex()
	{
		real = 0.0f;
		imag = 0.0f;
	}
	Complex(float r, float i)
	{
		real = r;
		imag = i;
	}
	void setReal(float f)
	{
		real = f;
	}
	void setImag(float f)
	{
		imag = f;
	}
	void setComplex(float r, float i)
	{
		real = r;
		imag = i;
	}
	float getReal()
	{
		return real;
	}
	float getImag()
	{
		return imag;
	}
	//summation
	//deals with summation between two complex numbers
	Complex operator+ (Complex c)
	{
		Complex x;
		x.real = real + c.real;
		x.imag = imag + c.imag;
		return x;
	}
	//deals with summation between complex number (left) and float (right)
	Complex operator+ (float f)
	{
		Complex x;
		x.real = real + f;
		x.imag = imag;
		return x;
	}
	//subtraction
	Complex operator- (Complex c)
	{
		Complex x;
		x.real = real - c.real;
		x.imag = imag - c.imag;
		return x;
	}
	//deals with summation between complex number (left) and float (right)
	Complex operator- (float f)
	{
		Complex x;
		x.real = real - f;
		x.imag = imag;
		return x;
	}
	//multiplication
	Complex operator*(Complex C)
	{
		float a = real, b = imag;
		float c = C.real, d = C.imag;
		Complex X;
		X.real = a * c - b * d;
		X.imag = b * c + a * d;
		return X;
	}
	Complex operator*(float f)
	{
		return Complex(real * f, imag * f);
	}
	//division
	Complex operator/(Complex C)
	{
		if (C.real == 0 && C.imag == 0)
		{
			cout << "Not possible to divide " << *(this) << " by " << C << endl;
			cout << "returning " << *(this) << endl;
			return *(this);
		}
		float ar = real, ai = imag;
		float xr = C.real, xi = C.imag;
		Complex y;
		y.real = (ar * xr + ai * xi) / (xr * xr + xi * xi);
		y.imag = (ai * xr - ar * xi) / (xr * xr + xi * xi);
		return y;
	}
	Complex operator/(float f)
	{
		if (f == 0)
		{
			cout << "Not possible to divide " << *(this) << " by " << 0 << endl;
			cout << "returning " << *(this) << endl;
			return *(this);
		}
		return Complex(real / f, imag / f);
	}
	/*void print()
	{
		cout << real << "+i(" << imag << ")" << endl;
	}*/

};

//summation
//deals with summation between float (left) and complex number (on the right)
//friend function: can use class members
Complex operator+(float f, Complex c)
{
	Complex x;
	x.setComplex(f + c.real, c.imag);
	return x;
}
//subtraction
Complex operator-(float f, Complex c)
{
	Complex x;
	x.setComplex(f - c.real, c.imag * -1);
	return x;
}
//multiplication
Complex operator*(float f, Complex C)
{
	return Complex(C.getReal() * f, C.getImag() * f);
}
//division
Complex operator/(float f, Complex C)
{
	if (C.real == 0 && C.imag == 0)
	{
		cout << "Not possible to divide " << f << " by " << C << endl;
		cout << "returning " << C << endl;
		return C;
	}
	float xr = C.real, xi = C.imag;
	Complex y;
	y.real = (f * xr) / (xr * xr + xi * xi);
	y.imag = ( -1 * f * xi) / (xr * xr + xi * xi);
	return y;
}

//deals with printing complex using cout
//overloading the operator "<<"
//not friend: can use public functions only
ostream& operator<< (ostream& o, Complex c)
{
	o << c.getReal() << "+i(" << c.getImag() << ")";
	return o;
}

int main()
{
	Complex div1(1, 2), div2(3, 4);
	cout << "division testing:" << endl;
	cout << div1 / div2 << endl;
	cout << div1 / 2 << endl;
	cout << 1 / div1 << endl << endl;
	cout << "testing dividing by zero cases" << endl;
	cout << div1 / Complex(0, 0) << endl;
	cout << div1 / 0 << endl;
	cout << 1 / Complex(0, 0) << endl;
	
}