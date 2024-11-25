#include <iostream>
#include <string>

using namespace std;

class Silnikowy {
public:
    void przyspiesz() const {
        cout << "Pojazd silnikowy przyspiesza, zwiekszajac obroty silnika spalinowego." << endl;
    }
};


class Elektryczny {
public:
    void ladowanie() const {
        cout << "Pojazd elektryczny jest ladowany z gniazdka." << endl;
    }

    void przyspiesz() const {
        cout << "Pojazd elektryczny przyspiesza, zwiekszajac moc silnika elektrycznego." << endl;
    }
};


class Hybryda : public Silnikowy, public Elektryczny {
public:
    void przyspiesz() const {
        Silnikowy::przyspiesz();
        Elektryczny::przyspiesz();
        cout << "Hybryda korzysta z obu napedow, aby przyspieszyc bardziej efektywnie." << endl;
    }
};

int main() {
    Hybryda mojHybryda;

    cout << "Ladowanie hybrydy:" << endl;
    mojHybryda.ladowanie();

    cout << "\nPrzyspieszanie hybrydy:" << endl;
    mojHybryda.przyspiesz();

    return 0;
}
