/* Fraction class
enhancements by <username(s)> FIXME

Milestone Requirements:
By 8 am on 9/9/19 Milestone 1: Pull repo and make at least one change and commit

By 8 am on 9/11/19 Milestone 2: Make sincere attempt to complete everything, so you can come to class with questions.  To meet this milestone, you must have written and pushed most of the code needed for completion to the repo. However, it might not yet be working.

By 8 am on 9/13/19 Final Milestone: Lab is complete.
*/

#include <iostream>
using namespace std;

int gcd(int m, int n) {
	while (m%n != 0) {
		int oldm = m;
		int oldn = n;

		m = oldn;
		n = oldm % oldn;
	}
	return n;
}

class Fraction {
	public:
		Fraction(int top = 0, int bottom = 1) {
			num = top;
			den = bottom;
		}

		friend ostream &operator<<(ostream &stream, const Fraction &frac);
		friend bool operator ==(const Fraction &frac1, const Fraction &frac2);
		friend Fraction operator +(const Fraction &frac1, const Fraction &frac2);

	private:
		int num, den;
};

Fraction operator +(const Fraction &frac1, const Fraction &frac2) {
	int newnum = frac1.num * frac2.den + frac1.den * frac2.num;
	int newden = frac1.den * frac2.den;
	int common = gcd(newnum, newden);
	return Fraction(newnum / common, newden / common);
}

bool operator ==(const Fraction &frac1, const Fraction &frac2) {
	return  (frac1.num == frac2.num && frac1.den == frac2.den);
}

ostream &operator<<(ostream &stream, const Fraction &frac) {
	stream << frac.num << "/" << frac.den;
	return stream;
}

int main() {
	char enterme;

	cout << "Demo use of the constructors & operator overloading." << endl;
	Fraction f1; 
	cout << "f1 = " << f1 << endl;
	Fraction f2(1, 4);
	cout << "f2 = "<< f2 << endl;
	Fraction f3 = f1 + f2;
	cout << "f3 is f1 + f2 = " << f3 << endl;
	Fraction f4 = f2 + f2;
	cout << "f4 is f2 + f2 = " << f4 << endl;

	cin >> enterme; //holds console open in some situations
	return 0;
}

