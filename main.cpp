#include <iostream>
#include <string>
using namespace std;

// Abstract base class for Event to follow DIP
class Event {
public:
    virtual void displayDetails() const = 0; // Pure virtual function for abstraction
};

class Session : public Event {
protected:
    string title;
    string speaker;
    string startTime;
    string endTime;

public:
    Session(string title, string speaker, string startTime, string endTime)
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {}

    void displayDetails() const override {
        cout << "Session: " << title << "\nSpeaker: " << speaker 
             << "\nTime: " << startTime << " - " << endTime << endl;
    }
};

// A new type of event following DIP
class WorkshopSession : public Event {
private:
    string topic;
    int duration; // duration in minutes

public:
    WorkshopSession(string topic, int duration) : topic(topic), duration(duration) {}

    void displayDetails() const override {
        cout << "Workshop on: " << topic << "\nDuration: " << duration << " minutes" << endl;
    }
};

class Attendee {
private:
    string name;

public:
    Attendee(string name) : name(name) {}

    // Attendee depends on the abstract Event class, not on a concrete implementation
    void attendEvent(const Event& event) const {
        cout << name << " is attending event: ";
        event.displayDetails();
    }
};

int main() {
    // Create different types of events
    Session session1("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    WorkshopSession workshop1("Advanced C++ Programming", 120);

    // Create attendee
    Attendee attendee1("Parth");

    // Attendee can attend different types of events
    attendee1.attendEvent(session1);
    attendee1.attendEvent(workshop1);

    return 0;
}
