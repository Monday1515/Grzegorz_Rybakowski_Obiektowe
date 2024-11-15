#include <iostream>
#include <string>

using namespace std;

class Samochod {
private:
    string marka;
    string model;
    int rokProdukcji;

public:

    Samochod(const string& marka, const string& model, int rokProdukcji)
        : marka(marka), model(model), rokProdukcji(rokProdukcji) {}


    Samochod() : marka("Nieznana"), model("Nieznany"), rokProdukcji(0) {}


    ~Samochod() {
        cout << "Destruktor wywolany dla: " << marka << " " << model << endl; // informacja o likwidacji obiektu?
    }


    void wyswietlInformacje() const {
        cout << "Samochod: " << marka << " " << model << ", Rok produkcji: " << rokProdukcji << endl;
    }
};

int main() {

    Samochod auto1("Toyota", "Corolla", 2020);
    Samochod auto2("Opel", "Astra", 2010);
    Samochod auto3;
    
    auto1.wyswietlInformacje();
    auto2.wyswietlInformacje();
    auto3.wyswietlInformacje();

    return 0;
}
