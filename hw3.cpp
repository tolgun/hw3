//      Tugcan Olgun
// 

#include <iostream>

using namespace std;

struct ComplexNumbers{
    int re;
    int im;
    ComplexNumbers() {
        re, im = 1, 1;
    }
    ComplexNumbers(int ire, int iim) {
        re = ire;
        im = iim;
    }
};

void operator+=(ComplexNumbers &fi, ComplexNumbers &se)
{
    fi.re = fi.re + se.re;
    fi.im = fi.im + se.im;
}

istream& operator>>(istream &in, ComplexNumbers &val) {
    cin >> val.re >> val.im;
    return in;
}

ostream& operator<<(ostream &out, ComplexNumbers &val ) {
    out << val.re << " + " << val.im << "i";
    return out;
}


void operator-=(ComplexNumbers &fi, ComplexNumbers &se)
{
    fi.re = fi.re - se.re;
    fi.im = fi.im - se.im;
}

void operator*=(ComplexNumbers &fi, ComplexNumbers &se)
{
    int tempVal;
    tempVal = (fi.re * se.re) - (fi.im * se.im);
    fi.im = fi.re * se.im + fi.im * se.re;
    fi.re = tempVal;
}
int main() {
    ComplexNumbers num1, num2;
    cout << "Enter real and imaginary separately for the first number. ex: 3 5: " << endl;
    cin >> num1;
    cout << "Enter real and imaginary separately for the second number. ex: 4 6: " << endl;
    cin >> num2;

    ComplexNumbers temp = num1;
    num1 += num2;
    cout << "The result of +(sum): " << num1 << endl;
    num1 = temp;

    num1 -= num2;
    cout << "The result of -(sub): " << num1 << endl;
    num1 = temp;

    num1 *= num2;
    cout << "The result of *(mul): " << num1 << endl;

    return 0;
}