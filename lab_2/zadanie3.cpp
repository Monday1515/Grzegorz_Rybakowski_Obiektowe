#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Function {
public:
    virtual ~Function() = default;
    virtual float calculate(float x) = 0;
};

class LinearFunction : public Function {
private:
    float a;
    float b;
public:
    LinearFunction(float coeff, float intercept): a(coeff), b(intercept) {}

    float calculate(float x) override {
        return a * x + b;
    }
};

int main (){
    LinearFunction linear(2.0f, 3.0f); // f(x) = 2 * x + 3
    float x = 5.0f;

    cout << "Wartosc funkcji w punkcie " << x << " to: " << linear.calculate(x) << endl;

    return 0;
}