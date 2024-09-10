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
    Session(string title, string speaker, string startTime, string endTime)
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {}

    void displayDetails() const {
        cout << "Session: " << this->title << "\nSpeaker: " << this->speaker 
             << "\nTime: " << this->startTime << " - " << this->endTime << endl;
    }

    string getTitle() const {
        return this->title;
    }

    Session& getSession() {
        return *this; 
    }
};

class Attendee {
private:
    string name;

public:
    Attendee(string name) : name(name) {}

    void attendSession(const Session& session) const {
        cout << this->name << " is attending session: " << session.getTitle() << endl;
    }

    void displayDetails() const {
        cout << "Attendee Name: " << this->name << endl;
    }

    const Attendee& getThisAttendee() const {
        return *this; 
    }
};

class Speaker {
private:
    string name;

public:
    Speaker(string name) : name(name) {}

    void displayDetails() const {
        cout << "Speaker Name: " << this->name << endl;
    }

    Speaker& getThisSpeaker() {
        return *this;
    }
};

class Event {
private:
    string eventName;
    Session* sessions[2];  
    Attendee* attendees[2]; 
    Speaker* speakers[2];  
    int sessionCount;
    int attendeeCount;
    int speakerCount;

public:
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
    }

    Event& getThisEvent() {
        return *this; // Returning current object by reference
    }
};

int main() {
    Event event("Tech Conference 2024");

    Session keynote("Keynote: Future of Technology", "John Doe", "10:00 AM", "11:00 AM");
    Session workshop("Workshop: AI and Machine Learning", "Jane Smith", "11:30 AM", "1:00 PM");
    event.addSession(&keynote);
    event.addSession(&workshop);

    Attendee attendee1("Alice");
    Attendee attendee2("Bob");
    event.registerAttendee(&attendee1);
    event.registerAttendee(&attendee2);

    Speaker speaker1("John Doe");
    Speaker speaker2("Jane Smith");
    event.addSpeaker(&speaker1);
    event.addSpeaker(&speaker2);

    attendee1.attendSession(keynote);
    attendee2.attendSession(workshop);

    event.showEventDetails();

    return 0;
}
