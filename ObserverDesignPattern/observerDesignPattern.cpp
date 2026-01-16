#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ISubscriber
{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {} // virtual destructor for interface
};

// Abstract Observable interface : a youtube channel interface

class Ichannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unsubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~Ichannel() {};
};

// Concrete Subject: a Youtube Channel that observers can subscribe to
class Channel : public Ichannel
{
private:
    vector<ISubscriber *> subscribers; // list of subscribers
    string name;
    string latestVideo;

public:
    Channel(const string &name)
    {
        this->name = name;
    }

    // Add a subscriber (avoid duplicates)
    void subscribe(ISubscriber *subscriber) override
    {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }

    // Remove a subscriber
    void unsubscribe(ISubscriber *subscriber) override
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscribers);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }

    // notify all subscribers of the latest video
    void notifySubscribers() override
    {
        for (ISubscriber *sub : subscribers)
        {
            sub->update();
        }
    }

    // upload a new video and notify all subscribers
    void uploadVideo(const string &title)
    {
        latestVideo = title;
        cout << "\n[" << name << "uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    // read video data
    string getVideoData()
    {
        return "\nCheckout our new video : " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber
{
private:
    string name;
    Channel *channel;

public:
    Subscriber(const string &name, Channel *channel)
    {
        this->name = name;
        this->channel = channel;
    }
    // called by channel; prints notification message
    void update() override
    {
        cout << "hey" << name << "," << this->channel->getVideoData();
    }
};

int main()
{
    // create a channel and subscribers
    Channel *channel = new Channel("CoderArmy");

    Subscriber *subs1 = new Subscriber("Varun", channel);
    Subscriber *subs2 = new Subscriber("Tarun", channel);

    channel->subscribe(subs1);
    channel->subscribe(subs2);

    channel->uploadVideo("Observer Pattern Tutorial");

    channel->unsubscribe(subs1);

    channel->uploadVideo("Decorator pattern tutoial");
}