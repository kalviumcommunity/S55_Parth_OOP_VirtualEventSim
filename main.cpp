#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Event {
public:
    // Pure virtual function to make this an abstract class
    virtual void displayDetails() const = 0; // Must be overridden in derived classes
};

class Session : public Event {
protected:
    string title;
    string speaker;
    string startTime;
    string endTime;
    static int sessionCount;  // Static variable to track the number of sessions

public:
    // Default Constructor (Type 1)
    Session() : title(""), speaker(""), startTime(""), endTime("") {
        sessionCount++;
        cout << "Default Constructor called for Session" << endl;
    }

    // Parameterized Constructor (Type 2)
    Session(string title, string speaker, string startTime, string endTime) 
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {
        sessionCount++;
        cout << "Parameterized Constructor called for Session" << endl;
    }

    // Destructor
    ~Session() {
        sessionCount--;
        cout << "Destructor called for Session" << endl;
    }

    // Static function to get the total session count
    static void displaySessionCount() {
        cout << "Total Sessions Created: " << sessionCount << endl;
    }

    // Override the displayDetails function
    void displayDetails() const override {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }
};

// Initialize static variable
int Session::sessionCount = 0;

class Workshop : public Session {
private:
    string workshopTopic;

public:
    Workshop(string title, string speaker, string startTime, string endTime, string topic) 
        : Session(title, speaker, startTime, endTime), workshopTopic(topic) {
        cout << "Workshop Constructor called for topic: " << topic << endl;
    }

    // Override the displayDetails function
    void displayDetails() const override {
        Session::displayDetails();
        cout << "Workshop Topic: " << this->workshopTopic << endl;
    }
};

// New class: PanelDiscussion
class PanelDiscussion : public Event {
private:
    string topic;
    string panelists;
    string startTime;
    string endTime;

public:
    // Constructor for PanelDiscussion
    PanelDiscussion(string topic, string panelists, string startTime, string endTime) 
        : topic(topic), panelists(panelists), startTime(startTime), endTime(endTime) {
        cout << "PanelDiscussion Constructor called for topic: " << topic << endl;
    }

    // Override the displayDetails function
    void displayDetails() const override {
        cout << "Panel Discussion on: " << this->topic 
             << "\nPanelists: " << this->panelists 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }
};

class Attendee {
protected:
    string name;
    static int attendeeCount;  // Static variable to track the number of attendees

public:
    // Default Constructor (Type 1)
    Attendee() : name("Unknown") {
        attendeeCount++;
        cout << "Default Constructor called for Attendee" << endl;
    }

    // Parameterized Constructor (Type 2)
    Attendee(string name) : name(name) {
        attendeeCount++;
        cout << "Parameterized Constructor called for Attendee" << endl;
    }

    // Destructor
    ~Attendee() {
        attendeeCount--;
        cout << "Destructor called for Attendee" << endl;
    }

    // Static function to get the total attendee count
    static void displayAttendeeCount() {
        cout << "Total Attendees Registered: " << attendeeCount << endl;
    }

    // Function to attend an event using virtual function
    void attendEvent(const Event& event) const {
        cout << this->name << " is attending event: ";
        event.displayDetails();
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }
};

// Initialize static variable
int Attendee::attendeeCount = 0;

class ExclusiveAccess {
public:
    void getExclusiveAccess() const {
        cout << "Access to VIP Lounge and exclusive content." << endl;
    }
};

// Derived class using Multiple Inheritance
class VIPAttendee : public Attendee, public ExclusiveAccess {
public:
    VIPAttendee(string name) : Attendee(name) {
        cout << "VIP Attendee created: " << name << endl;
    }

    void displayVIPDetails() const {
        displayDetails();
        getExclusiveAccess();
    }
};

int main() {
    // Using Default Constructor
    Session session1;
    Attendee attendee1;

    // Using Parameterized Constructor
    Session session2("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Workshop workshop1("Workshop: AI Ethics", "Jane Smith", "11:30 AM", "1:00 PM", "Ethics in AI");
    PanelDiscussion panel1("Future of AI", "Alice, Bob, Charlie", "2:00 PM", "3:00 PM");

    Attendee attendee2("Parth");

    // Demonstrating polymorphism with virtual function
    attendee2.attendEvent(session2);       // Attending a general session
    attendee2.attendEvent(workshop1);      // Attending a specific workshop
    attendee2.attendEvent(panel1);         // Attending a panel discussion

    // Using VIPAttendee derived from Attendee and ExclusiveAccess (Multiple Inheritance)
    VIPAttendee vipAttendee("Alice");
    vipAttendee.displayVIPDetails();

    // Display session and attendee counts
    Session::displaySessionCount();
    Attendee::displayAttendeeCount();

    return 0;
}
