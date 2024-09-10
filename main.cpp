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
    Session(string sessionTitle, string sessionSpeaker, string start, string end)
        : title(sessionTitle), speaker(sessionSpeaker), startTime(start), endTime(end) {}

    void displayDetails() const {
        cout << "Session: " << title << "\nSpeaker: " << speaker 
             << "\nTime: " << startTime << " - " << endTime << endl;
    }

    string getTitle() const {
        return title;
    }
};

class Attendee {
private:
    string name;

public:
    Attendee(string attendeeName) : name(attendeeName) {}

    void attendSession(const Session& session) const {
        cout << name << " is attending session: " << session.getTitle() << endl;
    }

    void displayDetails() const {
        cout << "Attendee Name: " << name << endl;
    }
};

class Speaker {
private:
    string name;

public:
    Speaker(string speakerName) : name(speakerName) {}

    void displayDetails() const {
        cout << "Speaker Name: " << name << endl;
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
        if (sessionCount < 2) {
            sessions[sessionCount++] = session;
        }
    }

    void registerAttendee(Attendee* attendee) {
        if (attendeeCount < 2) {
            attendees[attendeeCount++] = attendee;
        }
    }

    void addSpeaker(Speaker* speaker) {
        if (speakerCount < 2) {
            speakers[speakerCount++] = speaker;
        }
    }

    void showEventDetails() const {
        cout << "Event: " << eventName << endl;
        cout << "Sessions:" << endl;
        for (int i = 0; i < sessionCount; ++i) {
            sessions[i]->displayDetails();
            cout << endl;
        }

        cout << "Attendees:" << endl;
        for (int i = 0; i < attendeeCount; ++i) {
            attendees[i]->displayDetails();
            cout << endl;
        }

        cout << "Speakers:" << endl;
        for (int i = 0; i < speakerCount; ++i) {
            speakers[i]->displayDetails();
            cout << endl;
        }
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
