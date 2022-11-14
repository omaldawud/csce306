// virtual function allows you to execute the most derived version of 
// a function when you invoked the function using a base class pointer
// 
// pure virtual (=0) make the class abstract and derived classes must
// implement the pure virtual function
//
#include <iostream>
using namespace std;

class Instrument {
public:
    virtual void makeSound() = 0;   //Pure Virtual Function - no implementation
};

class Accordion : public Instrument {
    void makeSound() {
        cout << "\nAn Accordion is playing..." << endl;
    }
};

class Piano :public Instrument {
    void makeSound() {
        cout << "\nA Piano is playing..." << endl;
    }
};
int main()
{
    // we cannot create an object from Instrument as its an Abstract Class
   // Instrument i1;


    //invoke using a pointer
    Instrument* inst1 = new Accordion();   //assign 
    inst1->makeSound();

    Instrument* inst2 = new Piano();
    inst2->makeSound();

    Instrument* instruments[2] = { inst1, inst2 };
    //loop Ploymorphically
    cout << "\n\t----------\tloop Ploymorphically\t----------" << endl;
    for (int i = 0; i < 2; i++)
        instruments[i]->makeSound();

    
    std::cout << "\n\nHello CSCE306!\n\n";
}
