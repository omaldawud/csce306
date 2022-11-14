// Proj-OOP-2-ListOfObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    Employee(string name = "", string company = "", int age = 0) {
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
            cout << name << ": sorry no $" << endl;
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

class Teacher :public Employee {
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

class Adminstrator:public Employee {
    string dept = "CS";
public:
    Adminstrator(string name, string company, int age, string nDept)
        : Employee(name, company, age)
    {
        this->dept = nDept;
    }
    string getDept() { return dept; }
    void setDept(string nDept) { this->dept = nDept; }
};


int main()
{
    cout << "\n  ---    Demo List of Employees  ---" << endl;
    Developer d1("D1", "Google1", 65, "C++");
    Developer d2("D2", "Google2", 65, "Java");
    Developer d3("D3", "Google3", 65, "Python");

    Teacher t1("T1", "NCTRL1", 33, "History");
    Teacher t2 = Teacher("T2", "NCTRL2", 33, "Biology");
    Teacher t3 = Teacher("T3", "NCTRL3", 33, "Math");

    std::list<Employee*>  empList1;
    Employee* e = &d1;

    empList1.push_back(e);
    e = &d2;
    empList1.push_back(e);
    empList1.push_back(&d3);

    e = &t1;
    empList1.push_back(e);
    empList1.push_back(&t2);
    empList1.push_back(&t3);


    for (Employee* i : empList1)
        i->Work();

    //or 
    //Create an iterator of std::list
    cout << "\n ---    Using an iterator of std::list   ---" << endl;
    list<Employee*>::iterator it;
    for (it = empList1.begin(); it != empList1.end(); it++)
        (*it)->Work();

    // push Admins -  admin did not override the Work() method
    Adminstrator admin1("Admin1", "ATT", 45, "CS");

    cout << "\n Testing with Admins - " << endl;
    e = &admin1;
    empList1.push_back(e);
    for (Employee* i : empList1)
        i->Work();



    /*  without Polymorphism we need 2 lists and 2 loops */
}

