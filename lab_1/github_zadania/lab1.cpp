#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Car 
{
private:
    string make;
    string model;
    int year;
    int currentyear=2024;

public:
    Car(const string& make, const string& model, int year):make(make), model(model), year(year){}

    void displayInfo() {
        cout << "Marka: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Rok produkcji: " << year << endl;
        cout << "Wiek samochodu: " << currentyear - year << endl;
    }

    bool isSameCar(Car otherCar) {
        return (make == otherCar.make && model == otherCar.model && year == otherCar.year);
    }
};

int main() {
    Car car1("Ford", "Mustang", 1969);
    Car car2("Ford", "Mustang", 1969); 
    Car car3("Toyota", "Corolla", 2020); 

    car1.displayInfo();

    if (car1.isSameCar(car2)) {
        cout << "Samochody car1 i car2 sa takie same." << endl;
    } else {
        cout << "Samochody car1 i car2 sa rozne." << endl;
    }

    if (car1.isSameCar(car3)) {
        cout << "Samochody car1 i car3 sa takie same." << endl;
    } else {
        cout << "Samochody car1 i car3 sa rozne." << endl;
    }

    return 0;
}