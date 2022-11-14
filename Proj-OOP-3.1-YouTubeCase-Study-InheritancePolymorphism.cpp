// Proj-OOP-3-YouTubeCase-Study-InheritancePolymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
    string ChannelName;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
    void printPublishedVideoList() {
        for (string i : PublishedVideoTitles)
            cout << "\t\tTitle: " << i << endl;
    }
public:
    //Constructors
    YouTubeChannel(string cName, string oName) {
        this->ChannelName = cName;
        this->OwnerName = oName;
        this->SubscribersCount = 0;
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
        if(this->getSubscriberCount() > 0)
            this->SubscribersCount--;
    }

    //Getters
    string getName() { return this->ChannelName; }
    string getOwner() { return this->OwnerName; }
    int getSubscriberCount() { return this->SubscribersCount; }
    
    void getInfo() {
        cout << "Channel Name: " << this->getName() << endl;
        cout << "\tOwner Name: " << this->getOwner() << endl;
        cout << "\tSubscriber Count: " << this->getSubscriberCount() << endl;
        cout << "\tList of Videos: " << endl;
        printPublishedVideoList();
    }
};
int main()
{
    YouTubeChannel cookingChannel("Cooking", "Omar");
    cookingChannel.publishVideo("Hamborger w Cheese");
    cookingChannel.publishVideo("Byrani w Meet");
    cookingChannel.publishVideo("Byrani w Chicken");
    cookingChannel.getInfo();
    
    YouTubeChannel programingChannel("OOP", "Omar");
    programingChannel.publishVideo("Intor to C++");
    programingChannel.publishVideo("Intro to Java");
    programingChannel.getInfo();
    
    std::cout << "Okay Done Now!\n";
    exit(0);
}



//1.  we need to add a specific channel say cooking
//1.1 we create a nother class and call it CookingYouTubeChannel that
//      inherit from YouTubeChannel Class.