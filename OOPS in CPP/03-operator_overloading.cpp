#include<list>
#include<string>
#include<iostream>
using namespace std;

struct YouTubeChannel {
public:
    string Name;
    int SubscribersCount;
    YouTubeChannel(string name, int subscibersCount) {
        Name = name;
        SubscribersCount = subscibersCount;
    }

    bool operator==(const YouTubeChannel& yt) const{
        return this -> Name == yt.Name;
    }
};

ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
    COUT << "Name : " << ytChannel.Name << endl;
    COUT << "Subscribers : " << ytChannel.SubscribersCount << endl;
    return COUT;
}

class MyCollection {
public:
    list<YouTubeChannel> myChannels;
    void operator+=(YouTubeChannel& channel) {
        this -> myChannels.push_back(channel);
    }
    void operator-=(YouTubeChannel& channel) {
        this -> myChannels.remove(channel);
    }
};

ostream& operator<<(ostream& out, MyCollection& Collection) {
    int i = 0;
    for (auto& it : Collection.myChannels) {
        out << "Channel " << i++ << " :\n" << it << endl;
    }
    return out;
}

int main() {
    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("Striver", 750000);
    cout << yt1; cout << yt2;
    MyCollection Collection = MyCollection();
    Collection += yt1;
    Collection += yt2;
    cout << Collection;
    Collection -= yt2;
    cout << Collection;
}