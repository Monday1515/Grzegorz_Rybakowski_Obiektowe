#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class BinomialSolver {
private:
    double a, b, c; 
    double x1, x2; 

public:
    BinomialSolver(double a, double b, double c) : a(a), b(b), c(c), x1(0), x2(0) {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
        } else if (discriminant == 0) {
            x1 = x2 = -b / (2 * a);
        } else {
            x1 = x2 = std::numeric_limits<double>::quiet_NaN(); 
        }
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    double getX1() const { return x1; }
    double getX2() const { return x2; }

    double calculate(double x) const {
        return a * x * x + b * x + c;
    }
};

int main() {
    // Test 1: wielomian x^2 - 5x + 4 = 0
    BinomialSolver b1(1.0, -5.0, 4.0);
    cout << "Roots of the equation x*x - 5x + 4 = 0 are: " << endl;
    cout << "x1 = " << b1.getX1() << ", x2 = " << b1.getX2() << endl;
    cout << "The value of the polynomial x*x - 5x + 4 at x = 1 is: " << b1.calculate(1.0) << endl;
    cout << "The value of the polynomial x*x - 5x + 4 at x = 3 is: " << b1.calculate(3.0) << endl;

    // Test 2: wielomian x^2 + 2x + 1 = 0
    BinomialSolver b2(1.0, 2.0, 1.0);
    cout << "Roots of the equation x*x + 2x + 1 = 0 are: " << endl;
    cout << "x1 = " << b2.getX1() << ", x2 = " << b2.getX2() << endl;
    cout << "The value of the polynomial x*x + 2x + 1 at x = 1 is: " << b2.calculate(1.0) << endl;
    cout << "The value of the polynomial x*x + 2x + 1 at x = -1 is: " << b2.calculate(-1.0) << endl;

    return 0;
}
