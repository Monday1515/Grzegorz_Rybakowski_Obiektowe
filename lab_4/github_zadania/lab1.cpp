#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    int wiek;
    string email;
    string telefon;

public:
    Osoba() : imie(""), nazwisko(""), wiek(0), email(""), telefon("") {}

   
    Osoba(const string& imie, const string& nazwisko, int wiek, const string& email, const string& telefon) 
        : imie(imie), nazwisko(nazwisko), wiek(wiek) {
        setEmail(email);  
        setTelefon(telefon); 
    }

    string getImie() const {
        return imie;
    }

    void setImie(const string& imie) {
        this->imie = imie;
    }

    string getNazwisko() const {
        return nazwisko;
    }

    void setNazwisko(const string& nazwisko) {
        this->nazwisko = nazwisko;
    }

    int getWiek() const {
        return wiek;
    }

    void setWiek(int wiek) {
        this->wiek = wiek;
    }

    string getEmail() const {
        return email;
    }

    void setEmail(const string& email) {
        if (email.find('@') != string::npos) { 
            this->email = email;
        } else {
            cerr << "Nieprawidlowy adres email!" << endl;
        }
    }


    string getTelefon() const {
        return telefon;
    }

    void setTelefon(const string& telefon) {
        if (telefon.length() == 9 && telefon.find_first_not_of("0123456789") == string::npos) {
            this->telefon = telefon;
        } else {
            cerr << "Nieprawidlowy numer telefonu! Powinien zawierać 9 cyfr." << endl;
        }
    }
};

int main() {

    Osoba osoba1("Jan", "Kowalski", 30, "jan.kowalski@example.com", "123456789");


    cout << "Imie: " << osoba1.getImie() << endl;
    cout << "Nazwisko: " << osoba1.getNazwisko() << endl;
    cout << "Wiek: " << osoba1.getWiek() << endl;
    cout << "Email: " << osoba1.getEmail() << endl;
    cout << "Telefon: " << osoba1.getTelefon() << endl;

    // Próba ustawienia nieprawidłowego emaila i numeru telefonu
    osoba1.setEmail("jan.kowalski_example.com");
    osoba1.setTelefon("12345");

    // Ustawienie poprawnego numeru telefonu
    osoba1.setTelefon("987654321");


    cout << "\nPo zmianach:\n";
    cout << "Email: " << osoba1.getEmail() << endl;
    cout << "Telefon: " << osoba1.getTelefon() << endl;

    return 0;
}
