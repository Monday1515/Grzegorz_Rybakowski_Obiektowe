#include <iostream>
#include <memory>
#include <string>

struct VerboseObject
{
    //punkt 1
    std::string name;

    //punkt 2
    VerboseObject(const std::string& name) : name(name) {
        std::cout << "Konstruktor został wywołany dla obiektu: " << name << std::endl;
    }

    //punkt 3
    ~VerboseObject() {
        std::cout << "Destruktor został wywołany dla obiektu: " << name << std::endl;
    }

    //punkt 4
    void info() {
        std::cout << "Metoda info została wywołana dla obiektu: " << name << std::endl;
    }
};


int main() {
    std::cout << "Hello World!" << std::endl;

    static VerboseObject staticObject("Obiekt statyczny");

    VerboseObject autoObj("Obiekt automatyczny");
    VerboseObject autoObj2("obiekt automatyczny 2");

    auto uniquePtrObj = std::make_unique<VerboseObject>("Obiekt unique_ptr");

    VerboseObject* manualPtrObj = new VerboseObject("Obiekt manualny_ptr");

    autoObj.info();
    autoObj2.info();
    uniquePtrObj->info();
    manualPtrObj->info();

    delete manualPtrObj;

    std::cout << "Koniec funkcji main" << std::endl;
    return 0;
    /*
    Obserwacje:
    1. Obiekt statyczny jest tworzony tylko raz i jego destruktor jest wywoływany na końcu programu.
    2. Obiekty automatyczne są tworzone w miejscu, w którym zostały zadeklarowane i ich destruktor jest wywoływany na końcu bloku, w którym zostały zadeklarowane. 
        Obowiązuję tutaj zasada LIFO, czyli Last In First Out. Odwrotna kolejność niszczenia obiektów automatycznych.
    3. Wskaźnik inteligentny unique_ptr zarządza życiem obiektu automatycznie. Obiekt automatycznie jest niszczony, gdy wskaźnik przestaje istnieć.
    4. Obiekt manualny_ptr jest tworzony dynamicznie i jego destruktor musi być wywołany ręcznie, aby zwolnić przydzieloną pamięć.

    Czy kolejność jest taka sama, jak w przypadku „ręcznego” tworzenia obiektów?
    Nie, kolejność wywoływania destruktorów obiektów automatycznych różni się od obiektów tworzonych "ręcznie" za pomocą new i delete. Obiekty automatyczne są niszczone po zakończeniu bloku (najpierw jest niszczony ostatni obiekt stworzony, potem wcześniejsze).
    Natomiast obiekty tworzone dynamicznie za pomocą new i delete muszą być niszczone ręcznie, a destruktory są wywoływane dokładnie w momencie wywołania delete.
    */
}

