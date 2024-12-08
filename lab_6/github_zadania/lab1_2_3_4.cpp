#include <iostream>  // rozwiązanie poprawne
#include <memory>  
#include <vector>  

using namespace std;


class Pojazd {
public:
    virtual void przyspiesz() {
        cout << "Pojazd przyspiesza..." << endl;
    }

    virtual void zatrzymaj() {
        cout << "Pojazd zatrzymuje sie..." << endl;
    }

    virtual ~Pojazd() {
        cout << "Destruktor Pojazd" << endl;
    }
};


class Samochod : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Samochod przyspiesza na drodze" << endl;
    }

    void zatrzymaj() override {
        cout << "Samochod zatrzymuje sie na czerwonym swietle." << endl;
    }

    ~Samochod() override {
        cout << "Destruktor Samochod" << endl;
    }
};

class Rower : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Rowerzysta pedaluje szybciej" << endl;
    }

    void zatrzymaj() override {
        cout << "Rowerzysta zatrzymuje sie na chodniku." << endl;
    }

    ~Rower() override {
        cout << "Destruktor Rower" << endl;
    }
};

class Motocykl : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Motocykl przyspiesza" << endl;
    }

    void zatrzymaj() override {
        cout << "Motocykl zatrzymuje sie przy parkingu." << endl;
    }

    ~Motocykl() override {
        cout << "Destruktor Motocykl" << endl;
    }
};

class Skuter : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Skuter przyspiesza spokojnie" << endl;
    }

    void zatrzymaj() override {
        cout << "Skuter zatrzymuje sie" << endl;
    }

    ~Skuter() override {
        cout << "Destruktor Skuter" << endl;
    }
};

int main() {

    vector<unique_ptr<Pojazd>> pojazdy;


    pojazdy.push_back(make_unique<Samochod>());
    pojazdy.push_back(make_unique<Rower>());
    pojazdy.push_back(make_unique<Motocykl>());
    pojazdy.push_back(make_unique<Skuter>());  

    for (const auto& pojazd : pojazdy) {
        pojazd->przyspiesz();
        pojazd->zatrzymaj();
        cout << "-------------------" << endl;
    }

    return 0;
}
