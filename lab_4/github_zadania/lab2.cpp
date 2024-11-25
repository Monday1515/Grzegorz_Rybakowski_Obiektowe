#include <iostream>
#include <string>

using namespace std;


class Pracownik {
protected:
    string stanowisko;
    float wynagrodzenie;

public:
    Pracownik(const string& stanowisko, float wynagrodzenie)
        : stanowisko(stanowisko), wynagrodzenie(wynagrodzenie) {}

    virtual void pokazDane() const = 0; 
};

class Nauczyciel : public Pracownik {
public:
    Nauczyciel(const string& stanowisko, float wynagrodzenie)
        : Pracownik(stanowisko, wynagrodzenie) {}

    void pokazDane() const override {
        cout << "Stanowisko: " << stanowisko << "\n";
        cout << "Wynagrodzenie: " << wynagrodzenie << " PLN\n";
    }
};

class Administracja : public Pracownik {
public:
    Administracja(const string& stanowisko, float wynagrodzenie)
        : Pracownik(stanowisko, wynagrodzenie) {}

    void pokazDane() const override {
        cout << "Stanowisko: " << stanowisko << "\n";
        cout << "Wynagrodzenie: " << wynagrodzenie << " PLN\n";
    }
};

int main() {
    Nauczyciel nauczyciel("Nauczyciel matematyki", 5000.0);  // proszę tworzyc dane także w pamięci dynamicznej
    Nauczyciel nauczyciel1("Nauczyciel polskiego", 3000.0);
    Administracja administracja("Pracownik administracji", 4500.0);

    cout << "Dane nauczyciela:\n";
    nauczyciel.pokazDane();
    nauczyciel1.pokazDane();

    cout << "\nDane administracji:\n";
    administracja.pokazDane();

    return 0;
}
