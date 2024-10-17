#include <iostream>
#include <string>
using namespace std;

class Session {
private:
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

class Attendee {
private:
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
        cout << this->name << " is attending session: " << session.displayDetails() << endl;
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }
};

// Initialize static variable
int Attendee::attendeeCount = 0;

int main() {
    // Using the Default Constructor
    Session session1;
    Attendee attendee1;

    // Using the Parameterized Constructor
    Session session2("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Attendee attendee2("Parth");

    // Display details and counts
    session1.displayDetails();
    session2.displayDetails();
    attendee1.displayDetails();
    attendee2.displayDetails();

    Session::displaySessionCount();
    Attendee::displayAttendeeCount();

    return 0;
}
