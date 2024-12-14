#include <iostream>

using namespace std;

// Open/Closed Principle (OCP) – Obiekty i klasy powinny być otwarte na rozszerzenia, ale zamknięte na modyfikacje.

// Interfejs rabatu
class Discount {
public:
    virtual double calculateDiscount(double price) const = 0; 
    virtual ~Discount() = default;
};

// Regularny rabat (10%)
class RegularDiscount : public Discount {
public:
    double calculateDiscount(double price) const override {
        return price * 0.90;
    }
};

// Sezonowy rabat (20%)
class SeasonalDiscount : public Discount {
public:
    double calculateDiscount(double price) const override {
        return price * 0.80; 
    }
};

void showDiscountedPrice(const Discount& discount, double price) {
    cout << "Original price: " << price << endl;
    cout << "Price after discount: " << discount.calculateDiscount(price) << endl;
}


int main() {
    double price = 10.0;

    RegularDiscount regularDiscount;
    SeasonalDiscount seasonalDiscount;

    cout << "Applying regular discount:" << endl;
    showDiscountedPrice(regularDiscount, price);

    cout << "Applying seasonal discount:" << endl;
    showDiscountedPrice(seasonalDiscount, price);

    return 0;
}