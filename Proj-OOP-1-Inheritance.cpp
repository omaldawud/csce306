// Class is a auser defined data type (not built-in)
// Class type is called user-defined-datatype
// Class can represnet real life objects 
// Pillars of OOP: 
//      1. Encapsulation, getters and getters
//      2. Abstraction, abstract classes (virtual) hidding complixity
//      3. Inheritance, 
//      4. Polymorphism, many forms:
//          parent class reference is used to refere to object of a child class 

#include <iostream>
#include <list>

using namespace std;

//abstract class serves as a contract
class abstractEmployee {
    //contract role
    virtual void askForPromotion() = 0; 
};

//for a class to sign the contract use : 
class Employee : abstractEmployee {
    protected:
        string name;
        string company;
        int age;
    public:
        Employee(string name="", string company="", int age=0) {
            this->name = name;
            this->company = company;
            this->age = age;
        }
        void introduceYourSelf() {
            cout << "Name - " << name << endl;
            cout << "Company - " << company << endl;
            cout << "Age - " << age << endl;
        }
        void setAge(int age) {
            if (age > 18)
                this->age = age;
            else
                cout << "Error: Age must be over 18";
        }
        void setName(string nname) {
            this->name = nname;
        }
        void setCompany(string ncompany) {
            this->company = ncompany;
        }
        string getName() { return this->name; }
        string getCompany() { return this->company; }
        int getAge() { return this->age; }

        //Adhare to contract and provide code for the abstract method
        void askForPromotion() {
            if (age > 40) 
                cout << name << ": got promoted" << endl;
            else
                cout  << name << ": sorry no $" << endl;
            }

        //Work() is virtual functoin which forces the compiler to look for
        //a derived version of work() in children classes.
        // If derived classes has no work() function then the
        // base class's version of work will run instead.
        //
        virtual void Work() {
            cout << name << " is checking email, task backlog, performing tasks, ..." << endl;
        }
};

//Inheritance
class Developer : public Employee {
    string favProgrammingLangauge;
public:
    Developer(string name, string company, int age, string favProgLang) 
        : Employee(name, company, age)
    {
        favProgrammingLangauge = favProgLang;
    }
    
    //
    void fixBug() {
        cout << getName() << "\nFixed Bug Using: " << favProgrammingLangauge << endl;

    }
    void Work() {
        cout << name << " is writing " << favProgrammingLangauge << " code" << endl;
    }
};

class Teacher:public Employee {
    string subject;
public:
    Teacher(string name, string company, int age, string subject) 
        :Employee(name, company, age)  //call parent's constructor
    {
        this->subject = subject;
    }
    void prepareLesson() {
        cout << getName() << " is preparing: " << subject << " lesson" << endl;
    }
    void Work() {
        cout << name << " is teaching " << subject << endl;
    }
};

int main()
{
    std::cout << "employee1!\n";
    Employee employee1;
    employee1.setName("Omar 1 Aldawud");
    employee1.setCompany("North Central");
    employee1.setAge(25);

    employee1.introduceYourSelf();
    //call implemented abstract method
    employee1.askForPromotion();

    //or use constructor 
    cout << "\ncall implemented abstract method";
    Employee employee2("Omarc 2 Aldawud", "North Central", 56);
    employee2.introduceYourSelf();
    //call implemented abstract method
    employee2.askForPromotion();

    //Inheritance
    cout << "\nInheritance";
    Developer d("Omar Developer", "Google", 65, "C++");
    d.fixBug();
    d.introduceYourSelf();
    d.askForPromotion();
    cout << endl;

    Teacher t = Teacher("Omar Teacher", "NCTRL", 33,"History");
    t.prepareLesson();
    t.askForPromotion();

    //Polymorphism - 
    // invoke work against teacher and developer's objects
    d.Work();
    t.Work();

    //now implement work() on classes developer and teacher
    //same method implemented differently on each object

    // the most common use of polymorphism is when
    // a parent class reference is used to refer to
    // a child class
    Employee* e1 = &d;   // pointer to base class can hold reference to its child class - inheritance
    Employee* e2 = &t;

    //it will only work when we add the keyword virtual (abstract)
    // infornt of the work() method at the base class
    //
    // Demo virtual keyword
    e1->Work();
    e2->Work();   // use -> when using a pointer instead of DOT .
    
    // you can create a list of employees and run work on the entire list
    // using polymorphism 
    //see project 2 ListOFObjects
}
