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
    // Constructor
    Session(string title = "", string speaker = "", string startTime = "", string endTime = "")
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {
        sessionCount++;  // Increment session count when a session is created
    }

    // Static function to get the total session count
    static void displaySessionCount() {
        cout << "Total Sessions Created: " << sessionCount << endl;
    }

    // Accessor (getter) for title
    string getTitle() const {
        return this->title;
    }

    // Mutator (setter) for title
    void setTitle(const string& newTitle) {
        this->title = newTitle;
    }

    // Accessor (getter) for speaker
    string getSpeaker() const {
        return this->speaker;
    }

    // Mutator (setter) for speaker
    void setSpeaker(const string& newSpeaker) {
        this->speaker = newSpeaker;
    }

    void displayDetails() const {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }

    ~Session() {
        sessionCount--;  // Decrement session count when a session is destroyed
    }
};

// Initialize static variable
int Session::sessionCount = 0;

class Attendee {
private:
    string name;
    static int attendeeCount;  // Static variable to track number of attendees

public:
    // Constructor
    Attendee(string name = "") : name(name) {
        attendeeCount++;  // Increment attendee count when an attendee is registered
    }

    // Static function to get the total attendee count
    static void displayAttendeeCount() {
        cout << "Total Attendees Registered: " << attendeeCount << endl;
    }

    // Accessor (getter) for name
    string getName() const {
        return this->name;
    }

    // Mutator (setter) for name
    void setName(const string& newName) {
        this->name = newName;
    }

    void attendSession(const Session& session) const {
        cout << this->name << " is attending session: " << session.getTitle() << endl;
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }

    ~Attendee() {
        attendeeCount--;  // Decrement attendee count when an attendee is deregistered
    }
};

// Initialize static variable
int Attendee::attendeeCount = 0;

int main() {
    // Dynamically allocate Sessions
    Session* session1 = new Session("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Session* session2 = new Session("Workshop: AI and Machine Learning", "Jane Smith", "11:30 AM", "1:00 PM");

    // Using the mutator methods to modify session titles
    session1->setTitle("Keynote: The Future of Tech");
    session2->setSpeaker("Dr. Jane Smith");

    // Dynamically allocate Attendees
    Attendee* attendee1 = new Attendee("Kalvium");
    Attendee* attendee2 = new Attendee("Parth");

    // Using the mutator methods to modify attendee names
    attendee1->setName("Kalvium Tech Enthusiast");
    attendee2->setName("Parth Shah");

    attendee1->attendSession(*session1);
    attendee2->attendSession(*session2);

    // Display details after modification
    session1->displayDetails();
    session2->displayDetails();
    attendee1->displayDetails();
    attendee2->displayDetails();

    // Display static counts using static functions
    Session::displaySessionCount();
    Attendee::displayAttendeeCount();

    // Free dynamically allocated memory
    delete session1;
    delete session2;
    delete attendee1;
    delete attendee2;

    return 0;
}
