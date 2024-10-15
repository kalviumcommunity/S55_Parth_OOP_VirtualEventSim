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

    void displayDetails() const {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }

    string getTitle() const {
        return this->title;
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

class Speaker {
private:
    string name;

public:
    Speaker(string name = "") : name(name) {}

    void displayDetails() const {
        cout << "Speaker Name: " << this->name << endl;
    }
};

class Event {
private:
    string eventName;
    Session* sessions[2];  // Fixed-size array for sessions
    Attendee* attendees[2]; // Fixed-size array for attendees
    Speaker* speakers[2];   // Fixed-size array for speakers
    int sessionCount;
    int attendeeCount;
    int speakerCount;

public:
    // Constructor
    Event(string name) : eventName(name), sessionCount(0), attendeeCount(0), speakerCount(0) {}

    void addSession(Session* session) {
        if (this->sessionCount < 2) {
            this->sessions[this->sessionCount++] = session;
        }
    }

    void registerAttendee(Attendee* attendee) {
        if (this->attendeeCount < 2) {
            this->attendees[this->attendeeCount++] = attendee;
        }
    }

    void addSpeaker(Speaker* speaker) {
        if (this->speakerCount < 2) {
            this->speakers[this->speakerCount++] = speaker;
        }
    }

    void showEventDetails() const {
        cout << "Event: " << this->eventName << endl;
        cout << "Sessions:" << endl;
        for (int i = 0; i < this->sessionCount; ++i) {
            this->sessions[i]->displayDetails();
            cout << endl;
        }

        cout << "Attendees:" << endl;
        for (int i = 0; i < this->attendeeCount; ++i) {
            this->attendees[i]->displayDetails();
            cout << endl;
        }

        cout << "Speakers:" << endl;
        for (int i = 0; i < this->speakerCount; ++i) {
            this->speakers[i]->displayDetails();
            cout << endl;
        }

        // Display static counts using static functions
        Session::displaySessionCount();
        Attendee::displayAttendeeCount();
    }

    // Destructor to release dynamically allocated memory
    ~Event() {
        for (int i = 0; i < sessionCount; ++i) {
            delete sessions[i]; // Free memory allocated for sessions
        }
        for (int i = 0; i < attendeeCount; ++i) {
            delete attendees[i]; // Free memory allocated for attendees
        }
        for (int i = 0; i < speakerCount; ++i) {
            delete speakers[i]; // Free memory allocated for speakers
        }
    }
};

int main() {
    // Dynamically allocate memory for Event
    Event* event = new Event("Tech Conference 2024");

    // Dynamically allocate Sessions
    Session* session1 = new Session("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Session* session2 = new Session("Workshop: AI and Machine Learning", "Jane Smith", "11:30 AM", "1:00 PM");

    event->addSession(session1);
    event->addSession(session2);

    // Dynamically allocate Attendees
    Attendee* attendee1 = new Attendee("Kalvium");
    Attendee* attendee2 = new Attendee("Parth");

    event->registerAttendee(attendee1);
    event->registerAttendee(attendee2);

    // Dynamically allocate Speakers
    Speaker* speaker1 = new Speaker("Program mentor");
    Speaker* speaker2 = new Speaker("Technical mentor");

    event->addSpeaker(speaker1);
    event->addSpeaker(speaker2);

    attendee1->attendSession(*session1);
    attendee2->attendSession(*session2);

    // Display all event details
    event->showEventDetails();

    // Free dynamically allocated memory
    delete event; // This also deletes all sessions, attendees, and speakers due to the destructor

    return 0;
}
