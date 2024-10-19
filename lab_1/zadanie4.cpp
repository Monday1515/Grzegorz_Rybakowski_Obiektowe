#include <iostream>
#include <cmath>
#include <iomanip>

struct BinomialSolver {
    double a, b, c, epsilon;

    // Konstruktor inicjujący współczynniki równania i dokładność
    BinomialSolver(double _a, double _b, double _c, double _epsilon)
        : a(_a), b(_b), c(_c), epsilon(_epsilon) {}

    // Funkcja obliczająca i zwracająca większy z pierwiastków
    void solve() {
        double delta = b * b - 4 * a * c;

        // Sprawdzenie, czy istnieją pierwiastki rzeczywiste
        if (delta < 0) {
            std::cout << "Brak pierwiastków rzeczywistych" << std::endl;
            return;
        }

        // Obliczenie pierwiastków
        double sqrtDelta = std::sqrt(delta);
        double x1 = (-b - sqrtDelta) / (2 * a);
        double x2 = (-b + sqrtDelta) / (2 * a);

        // Wybranie większego pierwiastka
        double largerRoot = (x1 > x2) ? x1 : x2;

        // Zaokrąglenie do zadanej precyzji
        largerRoot = std::round(largerRoot / epsilon) * epsilon;

        // Wyświetlenie wyniku
        std::cout << std::fixed << std::setprecision(-std::log10(epsilon)) << largerRoot << std::endl;
    }
};

int main() {
    // Przykład użycia
    double a, b, c, epsilon;
    std::cin >> a >> b >> c >> epsilon;

    BinomialSolver solver(a, b, c, epsilon);
    solver.solve();

    return 0;
}
