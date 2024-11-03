#include <iostream>   // oba rozwiazania poprawne
#include <memory>
#include <string>
#include <vector>
#include <cstdlib> // rand i srand
#include <ctime> // time
using namespace std;

class parrot
{
private:
    vector <string> phrases;

public:

    parrot() {
        srand(time(0));
    }

    void addPhrase(const string& newPhrase) {
        phrases.push_back(newPhrase);
    }

    void say() const {
        if (phrases.empty()) {
            cout << "Papuga nie ma fraz!" << endl;
        }
        else
        {
           int randomIndex = rand() % phrases.size();
           cout << "Papuga mowi: " << phrases[randomIndex] << endl; 
        }
    }

};

int main() 
{
    parrot p1;

    p1.addPhrase("Papuga jestem, a nie kura");
    p1.addPhrase("Chce krakersa");
    p1.addPhrase("Arr Arr Matey");
    p1.addPhrase("ha ha ha");
    p1.addPhrase("Kura! Kura!");
    p1.addPhrase("Armata!");
    p1.say();

    return 0;
}
