#include <iostream>
#include <string>
using namespace std;

class Session {
private:
    string title;
    string speaker;
    string startTime;
    string endTime;

public:
    Session(string title = "", string speaker = "", string startTime = "", string endTime = "")
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {}

    void displayDetails() const {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }

    string getTitle() const {
        return this->title;
    }
};

class Attendee {
private:
    string name;

public:
    Attendee(string name = "") : name(name) {}

    void attendSession(const Session& session) const {
        cout << this->name << " is attending session: " << session.getTitle() << endl;
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }
};

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
    Event(string name) : eventName(name), sessionCount(0), attendeeCount(0), speakerCount(0) {}

    void addSession(Session* session) {
        if (this->sessionCount < 2) {
            this->sessions[this->sessionCount++] = session;  // Using this pointer
        }
    }

    void registerAttendee(Attendee* attendee) {
        if (this->attendeeCount < 2) {
            this->attendees[this->attendeeCount++] = attendee;  // Using this pointer
        }
    }

    void addSpeaker(Speaker* speaker) {
        if (this->speakerCount < 2) {
            this->speakers[this->speakerCount++] = speaker;  // Using this pointer
        }
    }

    void showEventDetails() const {
        cout << "Event: " << this->eventName << endl;
        cout << "Sessions:" << endl;
        for (int i = 0; i < this->sessionCount; ++i) {
            this->sessions[i]->displayDetails(); // Accessing member via this
            cout << endl;
        }

        cout << "Attendees:" << endl;
        for (int i = 0; i < this->attendeeCount; ++i) {
            this->attendees[i]->displayDetails(); // Accessing member via this
            cout << endl;
        }

        cout << "Speakers:" << endl;
        for (int i = 0; i < this->speakerCount; ++i) {
            this->speakers[i]->displayDetails(); // Accessing member via this
            cout << endl;
        }
    }
};

int main() {
    Event event("Tech Conference 2024");

    // Array of Session objects
    Session sessionsArray[2] = {
        Session("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM"),
        Session("Workshop: AI and Machine Learning", "Jane Smith", "11:30 AM", "1:00 PM")
    };

    for (int i = 0; i < 2; ++i) {
        event.addSession(&sessionsArray[i]);
    }

    Attendee attendeeArray[2] = {
        Attendee("Alice"),
        Attendee("Bob")
    };

    for (int i = 0; i < 2; ++i) {
        event.registerAttendee(&attendeeArray[i]);
    }

    Speaker speakerArray[2] = {
        Speaker("John Doe"),
        Speaker("Jane Smith")
    };

    for (int i = 0; i < 2; ++i) {
        event.addSpeaker(&speakerArray[i]);
    }

    attendeeArray[0].attendSession(sessionsArray[0]);
    attendeeArray[1].attendSession(sessionsArray[1]);

    event.showEventDetails();

    return 0;
}
