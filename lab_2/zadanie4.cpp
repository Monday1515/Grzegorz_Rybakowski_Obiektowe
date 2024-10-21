#include <iostream>
#include <memory>
#include <string>
#include <cmath>
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

float bisection(Function* func, float p, float k, float d) {
    //cout << func->calculate(p) << endl;
    //cout << func->calculate(k) << endl;
    if (func->calculate(p) * func->calculate(k) > 0) {
        return NAN;
    }

    float mid;

    while ((k - p) >= d) {
        //cout << "p: " << p << endl;
        //cout << "k: " << k << endl;
        mid = (p + k) / 2;
        //cout << "mid: " << mid << endl;
        if (func->calculate(mid) == 0.0) {
            break;
        } else if (func->calculate(mid) * func->calculate(p) < 0){
            k = mid;
        } else {
            p = mid;
        }
    }
    return mid;
}



int main (){
    LinearFunction f(2, -4); // f(x) = 2x - 4
    float p = 0;
    float k = 3;
    float d = 0.01;

    float root = bisection(&f, p, k, d);

    if (isnan(root)) {
        cout << "Brak miejsca zerowego w tym przedziale." << endl;
    } else {
        cout << "Miejsce zerowe: " << root << endl;
    }

    return 0;
}