#include <iostream>
#include <string>

using namespace std;

class Pojazd {
public:
    virtual void przyspiesz() const {
        cout << "Pojazd przyspiesza." << endl;
    }

    void zatrzymaj() const {
        cout << "Pojazd zatrzymuje sie." << endl;
    }

    virtual ~Pojazd() = default; 
};


class Samochod : public Pojazd {
public:
    void przyspiesz() const override {
        cout << "Samochod przyspiesza na drodze." << endl;
    }
};


class Rower : public Pojazd {
public:
    void przyspiesz() const override {
        cout << "Rowerzysta przyspiesza pedalujac mocniej." << endl;
    }
};


void testujPojazd(const Pojazd& pojazd) {
    pojazd.przyspiesz();
    pojazd.zatrzymaj();
}

int main() {
    Samochod mojSamochod;
    Rower mojRower;

    cout << "Testowanie samochodu:" << endl;
    testujPojazd(mojSamochod);

    cout << "\nTestowanie roweru:" << endl;
    testujPojazd(mojRower);

    return 0;
}
