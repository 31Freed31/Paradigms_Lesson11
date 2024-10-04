#include <iostream>
#include <vector>

class Talent {
public:
    virtual void showTalent() const = 0;
    virtual ~Talent() {}
};

class Dog {
    std::string name;
    std::vector<Talent*> talents;

public:
    Dog(std::string dogName) : name(dogName) {}

    void addTalent(Talent* talent) {
        talents.push_back(talent);
    }

    void show_talents() const {
        std::cout << "This is " << name << " and it has some talents:\n";
        for (const auto& talent : talents) {
            talent->showTalent();
        }
    }

    ~Dog() {
        for (Talent* talent : talents) {
            delete talent;
        }
    }
};

class Swimming : public Talent {
public:
    void showTalent() const override {
        std::cout << "It can \"Swim\"\n";
    }
};

class Dancing : public Talent {
public:
    void showTalent() const override {
        std::cout << "It can \"Dance\"\n";
    }
};

class Counting : public Talent {
public:
    void showTalent() const override {
        std::cout << "It can \"Count\"\n";
    }
};

int main() {
    Dog dog1("Sharik");

    dog1.addTalent(new Swimming());
    dog1.addTalent(new Dancing());
    dog1.addTalent(new Counting());

    dog1.show_talents();

    return 0;
}
