#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib> // rand i srand
#include <ctime> // time
using namespace std;

class parrot
{
private:
    string phrase;

public:

    parrot(const string& phrase) : phrase(phrase) {}

    void say(int times = 1) const {
        for (int i = 0; i < times; i++) {
            cout << "Papuga mowi: " << phrase << endl;
        }
    }

    void setPhrase(const string& newPhrase) {
        phrase = newPhrase;
    }
};

int main() 
{
    parrot p1("Jestem papuga!");
    parrot p2("Jestem kura!");

    p1.say(5);
    p2.say();
    p1.setPhrase("Jestes papuga, a nie kura!");
    p1.say();
}