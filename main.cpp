#include <iostream>
#include <string>
using namespace std;

class Event {
public:
    virtual void displayDetails() const = 0; // Pure virtual function for abstraction
};

// Separate class to handle session management (SRP implementation)
class SessionManager {
private:
    static int sessionCount;

public:
    static void incrementSessionCount() {
        sessionCount++;
    }

    static void decrementSessionCount() {
        sessionCount--;
    }

    static void displaySessionCount() {
        cout << "Total Sessions Created: " << sessionCount << endl;
    }
};

// Initialize static variable
int SessionManager::sessionCount = 0;

class Session : public Event {
protected:
    string title;
    string speaker;
    string startTime;
    string endTime;

public:
    // Constructor
    Session(string title, string speaker, string startTime, string endTime) 
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {
        SessionManager::incrementSessionCount();
        cout << "Session created with title: " << title << endl;
    }

    // Destructor
    ~Session() {
        SessionManager::decrementSessionCount();
        cout << "Session ended for title: " << title << endl;
    }

    void displayDetails() const override {
        cout << "Session: " << title << "\nSpeaker: " << speaker 
             << "\nTime: " << startTime << " - " << endTime << endl;
    }
};

class Attendee {
protected:
    string name;

public:
    Attendee(string name) : name(name) {
        cout << "Attendee created: " << name << endl;
    }

    void attendEvent(const Event& event) const {
        cout << name << " is attending event: ";
        event.displayDetails();
    }
};

int main() {
    // Creating Sessions and Attendees
    Session session1("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Attendee attendee1("Parth");

    // Display session details
    session1.displayDetails();

    // Attendee attending the event
    attendee1.attendEvent(session1);

    // Display session count using SessionManager
    SessionManager::displaySessionCount();

    return 0;
}
