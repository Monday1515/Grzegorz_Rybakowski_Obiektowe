#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Klasa bazowa Osoba
class Osoba {
protected:
    string imie;
    string nazwisko;
    string dataUrodzenia;

public:
    Osoba(const string& imie, const string& nazwisko, const string& dataUrodzenia)
        : imie(imie), nazwisko(nazwisko), dataUrodzenia(dataUrodzenia) {}

    string getFullName() const {
        return imie + " " + nazwisko;
    }

    string getDataUrodzenia() const {
        return dataUrodzenia;
    }

    virtual ~Osoba() {}
};

// Klasa Uczen, dziedziczy po Osoba
class Uczen : public Osoba {
    int nrIndeksu;

public:
    Uczen(const string& imie, const string& nazwisko, const string& dataUrodzenia, int nrIndeksu)
        : Osoba(imie, nazwisko, dataUrodzenia), nrIndeksu(nrIndeksu) {}

    int getNrIndeksu() const {
        return nrIndeksu;
    }
};

// Klasa Nauczyciel, dziedziczy po Osoba
class Nauczyciel : public Osoba {
    string specjalizacja;

public:
    Nauczyciel(const string& imie, const string& nazwisko, const string& dataUrodzenia, const string& specjalizacja)
        : Osoba(imie, nazwisko, dataUrodzenia), specjalizacja(specjalizacja) {}

    string getSpecjalizacja() const {
        return specjalizacja;
    }
};

// Klasa Material
class Material {
    string nazwaMaterialu;
    string typPliku;

public:
    Material(const string& nazwaMaterialu, const string& typPliku)
        : nazwaMaterialu(nazwaMaterialu), typPliku(typPliku) {}

    string getNazwaMaterialu() const {
        return nazwaMaterialu;
    }

    string getTypPliku() const {
        return typPliku;
    }
};

// Klasa SalaLekcyjna
class SalaLekcyjna {
    int numerSali;
    int pojemnosc;

public:
    SalaLekcyjna(int numerSali, int pojemnosc)
        : numerSali(numerSali), pojemnosc(pojemnosc) {}

    int getNumerSali() const {
        return numerSali;
    }

    int getPojemnosc() const {
        return pojemnosc;
    }
};

// Klasa Kurs
class Kurs {
    string nazwaKursu;
    string kodKursu;
    Nauczyciel* nauczyciel; // Wskaznik na nauczyciela
    SalaLekcyjna* salaLekcyjna; // Wskaznik na salę
    vector<Uczen*> uczniowie; // Lista uczniów
    vector<Material*> materialy; // Lista materiałów

public:
    Kurs(const string& nazwaKursu, const string& kodKursu)
        : nazwaKursu(nazwaKursu), kodKursu(kodKursu), nauczyciel(nullptr), salaLekcyjna(nullptr) {}

    void assignTeacher(Nauczyciel* n) {
        nauczyciel = n;
    }

    void assignClassroom(SalaLekcyjna* sala) {
        salaLekcyjna = sala;
    }

    void addStudent(Uczen* u) {
        uczniowie.push_back(u);
    }

    void addMaterial(Material* m) {
        materialy.push_back(m);
    }

    void displayDetails() const {
        cout << "Kurs: " << nazwaKursu << " (" << kodKursu << ")" << endl;

        if (nauczyciel) {
            cout << "Nauczyciel: " << nauczyciel->getFullName() << " (Data urodzenia: " << nauczyciel->getDataUrodzenia() << ")" << endl;
        } else {
            cout << "Nauczyciel: brak" << endl;
        }

        if (salaLekcyjna) {
            cout << "Sala lekcyjna: " << salaLekcyjna->getNumerSali() << " (Pojemnosc: " << salaLekcyjna->getPojemnosc() << ")" << endl;
        } else {
            cout << "Sala lekcyjna: brak" << endl;
        }

        cout << "Lista uczniow:" << endl;
        for (const auto& uczen : uczniowie) {
            cout << " - " << uczen->getFullName() << " (Data urodzenia: " << uczen->getDataUrodzenia() << ")" << endl;
        }

        cout << "Materialy kursu:" << endl;
        for (const auto& material : materialy) {
            cout << " - " << material->getNazwaMaterialu() << " (Typ pliku: " << material->getTypPliku() << ")" << endl;
        }
    }
};

int main() {

    Nauczyciel nauczyciel("Jan", "Kowalski", "1975-05-20", "Matematyka");
    SalaLekcyjna sala(101, 30);

    Uczen uczen1("Anna", "Nowak", "2005-03-14", 12345);
    Uczen uczen2("Piotr", "Zielinski", "2004-07-22", 67890);

    Material material1("Podstawy matematyki", "PDF");
    Material material2("Algebra", "Video");


    Kurs kurs("Matematyka dla poczatkujacych", "MATH101");
    kurs.assignTeacher(&nauczyciel);
    kurs.assignClassroom(&sala);
    kurs.addStudent(&uczen1);
    kurs.addStudent(&uczen2);
    kurs.addMaterial(&material1);
    kurs.addMaterial(&material2);


    kurs.displayDetails();

    return 0;
}
