#include <iostream> // poprawnie
#include <string>
#include <fstream> 

using namespace std;

// Single Responsibility Principle (SRP) – Klasa powinna mieć tylko jedną odpowiedzialność, czyli jedną przyczynę do zmiany.


// Klasa użytkownika
class User {
private:
    string name;
    string email;
    int age;

public:
    User(const string& name, const string& email, const int& age) 
        : name(name), email(email), age(age) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
    int getAge() const { return age; }
};

// Klasa odpowiedzialna za zapis użytkownika
class UserSaver {
public:
    void saveToFile(const User& user, const string& filename) {
        ofstream outFile(filename, ios::app); 
        
        if (outFile.is_open()) {
            outFile << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Age: " << user.getAge() << endl;
            outFile.close();  
            cout << "User data saved to file." << endl;
        } else {
            cout << "Failed to open the file!" << endl;
        }
    }
};

int main() {
    User user("Jan Kowalski", "jan.kowalski@example.com", 45); 
    UserSaver userSaver;
    

    userSaver.saveToFile(user, "users.txt");

    return 0;
}
