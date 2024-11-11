#include <iostream>

using namespace std;

class Tablica {
private:
    int* tablica;
    int rozmiar;

public:

    Tablica() {
        rozmiar = 10;
        tablica = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            tablica[i] = 0; 
        }
        cout << "Konstruktor domyslny: alokowanie tablicy o rozmiarze " << rozmiar << endl;
    }


    // Tablica(int rozmiar) {
    //     this->rozmiar = rozmiar;
    //     tablica = new int[rozmiar];
    //     cout << "Konstruktor z parametrem: alokowanie tablicy o rozmiarze " << rozmiar << endl;
    // }


    Tablica(int rozmiar) {
        this->rozmiar = rozmiar;
        tablica = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            tablica[i] = 0;  
        }
        cout << "Konstruktor z parametrem: alokowanie tablicy o rozmiarze " << rozmiar << endl;
    }


    ~Tablica() {
        delete[] tablica;
        cout << "Destruktor: zwolniono pamiec dla tablicy o rozmiarze " << rozmiar << endl;
    }

    void wyswietl() const {
        for (int i = 0; i < rozmiar; i++) {
            cout << tablica[i] << " ";
        }
        cout << endl;
    }

    void ustaw(int indeks, int wartosc) {
        if (indeks >= 0 && indeks < rozmiar) {
            tablica[indeks] = wartosc;
        } else {
            cout << "Nieprawidlowy indeks!" << endl;
        }
    }
};

int main() {
    cout << "Tworzenie obiektow Tablica..." << endl;

    Tablica tablica1;
    tablica1.ustaw(0, 5);
    tablica1.wyswietl();

    Tablica tablica2(25);
    tablica2.ustaw(0, 10);
    tablica2.ustaw(1, 15);
    tablica2.ustaw(24, 160379);
    tablica2.wyswietl();

    return 0;
}
