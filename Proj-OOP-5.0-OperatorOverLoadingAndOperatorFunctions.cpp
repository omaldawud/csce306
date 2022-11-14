// Proj-OOP-5.0-OperatorOverLoadingAndOperatorFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

//members of a struct are by default public
struct YouTubeChannel {
    string name;
    int subscribersCount;
    //constrcutor
    YouTubeChannel(string nName, int subcount) {
        name = nName;
        subscribersCount = subcount;
    }

    //overload operator ==
    bool operator==(const YouTubeChannel& yt) const {
        return this->name == yt.name;
    }
};

//operator function operator<<   -  pass by reference
//overloaded insertion operator as a global function
ostream& operator<<(ostream& COUT, YouTubeChannel& yt) {
    COUT << "Name: " << yt.name << endl;
    COUT << "\tSubscribers:" << yt.subscribersCount << endl;
    return COUT;
}

struct MyCollection {
    list<YouTubeChannel> myChannels;

    //+=operator overloading as a member functoin
    void operator+=(YouTubeChannel& channel) {
        this->myChannels.push_back(channel);
    }

    void operator-=(YouTubeChannel& channel) {
        this->myChannels.remove(channel);
    }
    void printChannels() {
        for (YouTubeChannel yt : myChannels)
            cout << yt;
    }
};

//for example 3: overload << as a global function for 
// my clooection objects to print the list
ostream& operator<<(ostream& COUT, MyCollection& myc) {
    for (YouTubeChannel yt : myc.myChannels)
        COUT << yt << endl;
    return COUT;
}

int main()
{
    //car1 + car2 (sum 2 cars)  use operator overloading
    YouTubeChannel yt1 = YouTubeChannel("1. Singing", 75000);
    cout << yt1;        //compiler does not know how the insertion operator <<
                        // it does not know how to print user defined datatype
    //operator functions same like normal function just need operator keyword

    YouTubeChannel yt2 = YouTubeChannel("2. Cooking", 80000);
    cout << yt1 << yt2;           

    //do the same by using the operator itself
    // call operator functoin like any function
    operator<<(cout, yt1);

    //need to overload += to work with MyCollection and YouTubeChannel types
    // which will add a channel to collection myCollection.
    //
    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    cout << "\n----------\tPrinting MyCollection\t----------" << endl;
    myCollection.printChannels();

    //example3: overload << to be able to say cout << myCollection
    cout << "\n---------\tExampole 3: overload << for collection list\t--------" << endl;
    cout << myCollection;

    //overload -= 
    cout << "\n\t----------\toverload -=\t" << endl;
    myCollection -= yt2;    //to make this work need to overload == operator
    myCollection.printChannels();

    cin.get();
    exit(0);
}