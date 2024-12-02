#include <iostream>   // przejrzała wszystkie rozwiązania, są poprawne
#include <string>

using namespace std;

class Pojazd {
public:
    virtual void przyspiesz() const {
        cout << "Pojazd przyspiesza w sposób podstawowy." << endl;
    }
};

class Silnikowy : virtual public Pojazd {
public:
    void przyspiesz() const override {
        cout << "Silnikowy pojazd przyspiesza, zwiekszajac obroty silnika spalinowego." << endl;
    }
};

class Elektryczny : virtual public Pojazd {
public:
    void przyspiesz() const override {
        cout << "Elektryczny pojazd przyspiesza, zwiekszajac moc silnika elektrycznego." << endl;
    }
};

class Hybryda : public Silnikowy, public Elektryczny {
public:
    void przyspiesz() const override {
        cout << "Hybryda laczy przyspieszenie silnika spalinowego i elektrycznego." << endl;
    }
};

int main() {
    Hybryda mojHybryda;

    cout << "Przyspieszanie hybrydy:" << endl;
    mojHybryda.przyspiesz();

    Pojazd* pojazd = &mojHybryda;
    cout << "\nPrzyspieszanie przez wskaznik na Pojazd:" << endl;
    pojazd->przyspiesz();

    return 0;
}
