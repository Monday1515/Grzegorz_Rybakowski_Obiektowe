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


class Samochod : private Pojazd {
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

    
    using Pojazd::wyswietlInformacje; 
};


int main() {
    Samochod mojSamochod("Ford", "Mustang", 2);


    mojSamochod.wyswietlSzczegoly();
    mojSamochod.wyswietlInformacje();

    // Próba bezpośredniego dostępu do atrybutów klasy bazowej (zawsze błąd):
    // mojSamochod.marka = "Toyota"; // Błąd kompilacji
    // mojSamochod.model = "Corolla"; // Błąd kompilacji

    return 0;
}
