#include <iostream>
#include <string>

using namespace std;

class Pojazd {
protected:
    string marka;
    string model;

public:
    Pojazd(const string& m, const string& mo)
        : marka(m), model(mo) {}

    void wyswietlInformacje() const {
        cout << "Marka: " << marka << ", Model: " << model << endl;
    }
};

class Samochod : protected Pojazd {
private:
    int liczbaDrzwi;

public:
    Samochod(const string& m, const string& mo, int drzwi)
        : Pojazd(m, mo), liczbaDrzwi(drzwi) {}

    void wyswietlSzczegoly() const {
        cout << "Samochod: Marka: " << marka
                  << ", Model: " << model
                  << ", Liczba drzwi: " << liczbaDrzwi << endl;
    }
};

int main() {
    Samochod mojSamochod("Toyota", "Corolla", 4);

    mojSamochod.wyswietlSzczegoly();

    // Próba dostępu do chronionych atrybutów klasy bazowej (nie działa):
    //mojSamochod.marka = "Ford"; // Błąd kompilacji
    //mojSamochod.wyswietlInformacje(); // Błąd kompilacji (z powodu chronionego dziedziczenia)

    return 0;
}
