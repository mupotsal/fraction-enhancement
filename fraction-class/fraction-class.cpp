/* Fraction class
enhancements by <Liberty Mupotsa(s)> FIXME

Milestone Requirements:
By 8 am on 9/9/19 Milestone 1: Pull repo and make at least one change and commit

By 8 am on 9/11/19 Milestone 2: Make sincere attempt to complete everything, so you can come to class with questions.  To meet this milestone, you must have written and pushed most of the code needed for completion to the repo. However, it might not yet be working.

By 8 am on 9/13/19 Final Milestone: Lab is complete.
*/

#include <iostream>
using namespace std;

/* The function below finds the greatest common devisor*/
int gcd(int m, int n) {
	while (m%n != 0) {
		int oldm = m;
		int oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}
/* The following is a  Fraction class*/
class Fraction {
	public:
		/* The following block of code is the constructor which is makes the fraction
		is one invokes the constructor but does not give the  numerator and the deniminator, a fraction o/1 is made.*/
		Fraction(int top = 0, int bottom = 1) {
			// modifying the constructor so that it reduces the fractions at the beginning
			int commondev = gcd(top, bottom);
			num = (top/commondev);  
			den = (bottom/commondev);

		}
		/* The following is operator overloading using the  friend method*/
		friend ostream &operator<<(ostream &stream, const Fraction &frac); //Overloaded the << symbol for cout
		friend bool operator ==(const Fraction &frac1, const Fraction &frac2); //overloaded the == operator so that it can be used in classes
		friend Fraction operator +(const Fraction &frac1, const Fraction &frac2); // Overloaded the addtion operator so that it can be used outside the class
		friend Fraction operator -(const Fraction &frac1, const Fraction &frac2);
		friend Fraction operator *(const Fraction &frac1, const Fraction &frac2);
		friend Fraction operator /(const Fraction &frac1, const Fraction &frac2);
		friend bool operator !=(const Fraction &frac1, const Fraction &frac2);
	private:
		int num, den;
};
/*Below is the implementation of the + operator, this is a friend function.
The primary purpose of this is to overload  + operator so that it can be used in the fraction class*/

Fraction operator +(const Fraction &frac1, const Fraction &frac2) {
	int newnum = frac1.num * frac2.den + frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	return Fraction(newnum, newden);

	// We nolonger need the code that I commented below because reducing is taken care of when the Constructor is called

	/*int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);*/
}
Fraction operator -(const Fraction& frac1, const Fraction& frac2) {
	int newnum = frac1.num * frac2.den - frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	return Fraction(newnum, newden);	

}

Fraction operator /(const Fraction& frac1, const Fraction& frac2) {
	int newnum = frac1.num * frac2.den ;
	int newden = frac1.den * frac2.num; // Note how the algorithm for dividing fractions was implemented
	return Fraction(newnum, newden);
}

Fraction operator *(const Fraction& frac1, const Fraction& frac2) {
	int newnum = frac1.num * frac2.num;
	int newden = frac1.den * frac2.den; // Note how the algorithm for multiplying fractions was implemented
	return Fraction(newnum, newden);
}
/* Implementation of the == oprator function which is a friend function of the Fraction class*/
bool operator ==(const Fraction &frac1, const Fraction &frac2) {
	return  (frac1.num == frac2.num && frac1.den == frac2.den);
}
// Overloading the << operator
ostream &operator<<(ostream &stream, const Fraction &frac) {
	stream << frac.num << "/" << frac.den;
	return stream;
}

int main() {
	char enterme;
	Fraction f0(100, 800);
	Fraction f00(100, 800);
	cout << "f0 is " << f0+f00 << endl;
	Fraction f1; 
	cout << "f1 = " << f1 << endl;
	Fraction f2(1, 4);
	Fraction f5(2, 4);
	cout << "f5 =" << f5 << endl;
	cout << "f2 = "<< f2 << endl;
	Fraction f3 = f1 + f2;
	cout << "f3 is f1 + f2 = " << f3 << endl;
	Fraction f4 = f2 + f2;
	cout << "f4 is f2 + f2 = " << f4 << endl;

	Fraction f6(2, 4);
	Fraction f7(1, 4);
	cout << "f6-f7 is " << f6 - f7 << endl;

	Fraction f8(2, 4);
	Fraction f9(1, 4);
	cout << "f8 / f9 is " << f8 / f9 << endl;

	Fraction f10(5, 10);
	Fraction f11(3, 4);
	cout << " f10 * f11 is " << f10 * f11 << endl;

	cin >> enterme; //holds console open in some situations
	return 0;
}

