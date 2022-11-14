// Proj-OOP-3-YouTubeCase-Study-InheritancePolymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
    string ChannelName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
    void printPublishedVideoList() {
        for (string i : PublishedVideoTitles)
            cout << "\t\tTitle: " << i << endl;
    }
protected:
    string OwnerName;
    int ContentQuality;
public:
    //Constructors
    YouTubeChannel(string cName, string oName) {
        this->ChannelName = cName;
        this->OwnerName = oName;
        this->SubscribersCount = 0;
        this->ContentQuality = 0;
    }
    //Setters
    void setName(string cName) { this->ChannelName = cName; }
    void setOwnerName(string oName) { this->OwnerName = oName; }
    void setSubsribersCount(int nCount) { this->SubscribersCount = nCount; }

    //Mutators
    void publishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
    void subscribe() {
        this->SubscribersCount++;
    }
    void UnSubscribe() {
        if (this->getSubscriberCount() > 0)
            this->SubscribersCount--;
    }

    //Getters
    string getName() { return this->ChannelName; }
    string getOwner() { return this->OwnerName; }
    int getSubscriberCount() { return this->SubscribersCount; }

    void getInfo() {
        cout << "\n---------  Channels Information   ---------" << endl;
        cout << "Channel Name: " << this->getName() << endl;
        cout << "\tOwner Name: " << this->getOwner() << endl;
        cout << "\tSubscriber Count: " << this->getSubscriberCount() << endl;
        cout << "\tList of Videos: " << endl;
        printPublishedVideoList();
    }
    void checkAnalytics() {
        if (this->ContentQuality > 5)
            cout << this->getOwner() << ": BAD Qulaity" << endl;
        else
            cout << this->getOwner() << ": GOOD Quality ... " << endl;
    }
};

//derived class: specialization
class CookingYouTubeChannel :public YouTubeChannel {
public:
    CookingYouTubeChannel(string cName, string oName)
        : YouTubeChannel(cName, oName)      //call parent class constructor 
    {}
    void practice() {
        cout << this->getOwner() << ": Practicing cooking, new recipes, spices mixer, ..." << endl;
        ContentQuality++;
    }
};

//another derived class
class SingersYouTubeChannel :public YouTubeChannel {
public:
    SingersYouTubeChannel(string cName, string oName)
        : YouTubeChannel(cName, oName)      //call parent class constructor 
    {}
    void practice() {
        cout << this->getOwner() << ": is taking singing classes, learn to dance, learn new songs ..." << endl;
    }
};

int main()
{
    CookingYouTubeChannel cookingChannel1("Cooking", "Omar");

    //Access base class using child class object as they are
    //inherited 
    cookingChannel1.publishVideo("Hamberger w Cheese");
    cookingChannel1.publishVideo("Biryani w Meet");
    cookingChannel1.publishVideo("Biryani w Chicken");
    cookingChannel1.subscribe(); cookingChannel1.subscribe(); cookingChannel1.subscribe();
    cookingChannel1.getInfo();
    cookingChannel1.practice();      //specialized method for cookingChannels

    YouTubeChannel cookingChannel2("Fish Cooking", "Fisher Man");
    cookingChannel2.publishVideo("Intor to Fish");
    cookingChannel2.publishVideo("Why Fish when you cna fish!");
    cookingChannel2.getInfo();
    //    cookingChannel2.practice(); //error practice is not available for TouTubeChannel objects


    SingersYouTubeChannel SingersYouTubeChannel("Omar Singing", "Singer 1");
    SingersYouTubeChannel.publishVideo("How to Sing in the Shower");
    SingersYouTubeChannel.subscribe();
    SingersYouTubeChannel.getInfo();

    cookingChannel1.practice();
    SingersYouTubeChannel.practice();

    //use a pointer to Base class to point to derived class object
    YouTubeChannel* yt1 = &cookingChannel1;
    YouTubeChannel* yt2 = &SingersYouTubeChannel;

    yt1->checkAnalytics();
    yt2->checkAnalytics();

    std::cout << "Okay Done Now!\n";
    exit(0);
}



//1.  we need to add a specific channel say cooking
//1.1 we create a nother class and call it CookingYouTubeChannel that
//      inherit from YouTubeChannel Class.