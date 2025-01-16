#include <iostream>
#include <string>

class Pizza {
private:
    std::string name;
    std::string dough;
    std::string sauce;
    std::string topping;

    Pizza(const std::string& name, const std::string& dough, const std::string& sauce, const std::string& topping)
        : name(name), dough(dough), sauce(sauce), topping(topping) {}

public:
    class Builder { // ten wzorzec Budowniczego powinien byc ukonkretniony dlam różnych rodzajów pizzy
    private:
        std::string name;
        std::string dough;
        std::string sauce;
        std::string topping;

    public:
        Builder& setName(const std::string& n) {
            name = n;
            return *this;
        }

        Builder& setDough(const std::string& d) {
            dough = d;
            return *this;
        }

        Builder& setSauce(const std::string& s) {
            sauce = s;
            return *this;
        }

        Builder& setTopping(const std::string& t) {
            topping = t;
            return *this;
        }

        Pizza build() {
            return Pizza(name, dough, sauce, topping);
        }
    };

    void display() const {
        std::cout << name << " Pizza with " 
                  << dough << " dough, " 
                  << sauce << " sauce, and " 
                  << topping << " topping." << std::endl;
    }
};

int main() {

    Pizza margarita = Pizza::Builder()
                        .setName("Margarita")
                        .setDough("Thin crust")
                        .setSauce("Tomato")
                        .setTopping("Cheese")
                        .build(); // ???

    margarita.display();

    Pizza pepperoni = Pizza::Builder()
                        .setName("Pepperoni")
                        .setDough("Thick crust")
                        .setSauce("Barbecue")
                        .setTopping("Pepperoni")
                        .build();  // ???

    pepperoni.display();

    return 0;
}
