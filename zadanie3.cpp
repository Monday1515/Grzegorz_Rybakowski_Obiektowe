#include <iostream>
#include <cmath>
#include <vector>

struct Complex {
    double real;
    double imag;

    // Metoda do wyznaczania modułu liczby zespolonej
    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Operator dodawania dla liczb zespolonych
    Complex operator+(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    }

    // Operator mnożenia dla liczb zespolonych
    Complex operator*(const Complex& other) const {
        return {real * other.real - imag * other.imag, real * other.imag + imag * other.real};
    }
};

int main() {
    std::vector<Complex> numbers;
    Complex sum = {0.0, 0.0};
    Complex product = {1.0, 0.0}; // Element neutralny mnożenia
    Complex maxModulusComplex = {0.0, 0.0};

    double real, imag;

    // Wczytywanie liczb zespolonych
    while (std::cin >> real >> imag) {
        Complex number = {real, imag};
        numbers.push_back(number);

        // Suma
        sum = sum + number;

        // Iloczyn
        product = product * number;

        // Znalezienie liczby o największym module
        if (number.modulus() > maxModulusComplex.modulus()) {
            maxModulusComplex = number;
        }
    }

    // Wyświetlenie wyników
    std::cout << "Suma: " << sum.real << " + " << sum.imag << "i" << std::endl;
    std::cout << "Iloczyn: " << product.real << " + " << product.imag << "i" << std::endl;
    std::cout << "Liczba o największym module: " << maxModulusComplex.real
              << " + " << maxModulusComplex.imag << "i" << std::endl;
    std::cout << "Moduł: " << maxModulusComplex.modulus() << std::endl;

    return 0;
}
