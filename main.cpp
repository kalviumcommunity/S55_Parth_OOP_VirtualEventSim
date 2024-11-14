#include <iostream>
#include <string>
using namespace std;

class Session {
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

    void displayDetails() const {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }
};

// Initialize static variable
int Session::sessionCount = 0;

// Derived class using Single Inheritance
class Workshop : public Session {
private:
    string workshopTopic;

public:
    Workshop(string title, string speaker, string startTime, string endTime, string topic) 
        : Session(title, speaker, startTime, endTime), workshopTopic(topic) {
        cout << "Workshop Constructor called for topic: " << topic << endl;
    }

    void displayWorkshopDetails() const {
        displayDetails();
        cout << "Workshop Topic: " << this->workshopTopic << endl;
    }
};

class Attendee {
protected:
    string name;
    static int attendeeCount;  // Static variable to track number of attendees

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

    void attendSession(const Session& session) const {
        cout << this->name << " is attending session: ";
        session.displayDetails();
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }
};

// Initialize static variable
int Attendee::attendeeCount = 0;

// Base class for Multiple Inheritance
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
    Attendee attendee2("Parth");

    // Using Workshop derived from Session (Single Inheritance)
    Workshop workshop1("Workshop: AI Ethics", "Jane Smith", "11:30 AM", "1:00 PM", "Ethics in AI");
    workshop1.displayWorkshopDetails();

    // Using VIPAttendee derived from Attendee and ExclusiveAccess (Multiple Inheritance)
    VIPAttendee vipAttendee("Alice");
    vipAttendee.displayVIPDetails();

    // Display session and attendee counts
    Session::displaySessionCount();
    Attendee::displayAttendeeCount();

    return 0;
}
