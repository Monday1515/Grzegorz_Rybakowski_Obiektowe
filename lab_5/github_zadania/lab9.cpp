#include <iostream>
#include <string>

using namespace std;

class Pojazd {
public:
    void wyswietlTyp() const {
        cout << "To jest pojazd." << endl;
    }

    virtual void przyspiesz() const {
        cout << "Pojazd przyspiesza w sposob podstawowy." << endl;
    }
};

class Samochod : public Pojazd {
public:
    void wyswietlTyp() const {
        cout << "To jest samochod." << endl;
    }

    void przyspiesz() const override {
        cout << "Samochod przyspiesza, zwiekszajac obroty silnika." << endl;
    }
};

class ElektrycznySamochod : public Samochod {
public:
    void wyswietlTyp() const {
        cout << "To jest samochod elektryczny." << endl;
    }

    void przyspiesz() const override {
        cout << "Samochod elektryczny przyspiesza, zwiekszajac moc silnika elektrycznego." << endl;
    }
};

int main() {
    Pojazd mojPojazd;
    Samochod mojSamochod;
    ElektrycznySamochod mojElektrycznySamochod;

    cout << "Obiekt klasy Pojazd:" << endl;
    mojPojazd.wyswietlTyp();
    mojPojazd.przyspiesz();

    cout << "\nObiekt klasy Samochod:" << endl;
    mojSamochod.wyswietlTyp();
    mojSamochod.przyspiesz();

    cout << "\nObiekt klasy ElektrycznySamochod:" << endl;
    mojElektrycznySamochod.wyswietlTyp();
    mojElektrycznySamochod.przyspiesz();

    return 0;
}
