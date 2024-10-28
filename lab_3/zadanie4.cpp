#include <iostream>
#include <cmath>
#include <limits>

#include <stdexcept>

using namespace std;

class no_real_solution : public std::runtime_error {
public:
    no_real_solution() : std::runtime_error("No real solutions exist for the quadratic equation.") {}
};


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
            throw no_real_solution(); 
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
    try {
        //x^2 + 5x + 3 
        BinomialSolver b1(1.0, 5.0, 3.0);
        cout << "Roots of the equation x^2 + 5x + 3 = 0 are: " << endl;
        cout << "x1 = " << b1.getX1() << ", x2 = " << b1.getX2() << endl;
        cout << "The value of the polynomial x^2 + 5x + 3 at x = 1 is: " << b1.calculate(1.0) << endl;
        cout << "The value of the polynomial x^2 + 5x + 3 at x = -1 is: " << b1.calculate(-1.0) << endl;

        //x^2 + 2x + 1
        BinomialSolver b2(1.0, 2.0, 1.0);
        cout << "Roots of the equation x^2 + 2x + 1 = 0 are: " << endl;
        cout << "x1 = " << b2.getX1() << ", x2 = " << b2.getX2() << endl;
        cout << "The value of the polynomial x^2 + 2x + 1 at x = 1 is: " << b2.calculate(1.0) << endl;
        cout << "The value of the polynomial x^2 + 2x + 1 at x = -1 is: " << b2.calculate(-1.0) << endl;

        //6x^2 + 3x + 9
        BinomialSolver b3(6.0, 3.0, 9.0);
        cout << "Roots of the equation 6x^2 + 3x + 9 = 0 are: " << endl;
        cout << "x1 = " << b3.getX1() << ", x2 = " << b3.getX2() << endl;
        
    } catch (const no_real_solution& e) {
        cout << "Error: " << e.what() << endl; 
    } catch (const std::exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}