#include <iostream>
#include <string>
using namespace std;

class Session {
private:
    string title;
    string speaker;
    string startTime;
    string endTime;
    static int sessionCount;  // Private static variable to track session count

    // Private function to format session details
    string formatDetails() const {
        return "Session: " + title + "\nSpeaker: " + speaker + "\nTime: " + startTime + " - " + endTime;
    }

public:
    // Constructor (public interface)
    Session(string title = "", string speaker = "", string startTime = "", string endTime = "")
        : title(title), speaker(speaker), startTime(startTime), endTime(endTime) {
        sessionCount++;  // Increment session count when a session is created
    }

    // Public static function to display session count (relevant info exposed)
    static void displaySessionCount() {
        cout << "Total Sessions Created: " << sessionCount << endl;
    }

    // Public function to access formatted session details (abstraction of internal formatting logic)
    void displayDetails() const {
        cout << formatDetails() << endl;
    }

    // Public accessor and mutator for title (relevant interface)
    string getTitle() const {
        return title;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
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
    static int attendeeCount;  // Private static variable to track attendee count

public:
    // Constructor (public interface)
    Attendee(string name = "") : name(name) {
        attendeeCount++;  // Increment attendee count when an attendee is registered
    }

    // Public static function to display attendee count (relevant info exposed)
    static void displayAttendeeCount() {
        cout << "Total Attendees Registered: " << attendeeCount << endl;
    }

    // Public function to allow attending a session (simplified interaction)
    void attendSession(const Session& session) const {
        cout << name << " is attending session: " << session.getTitle() << endl;
    }

    // Public accessor and mutator for name (relevant interface)
    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
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

    // Dynamically allocate Attendees
    Attendee* attendee1 = new Attendee("Kalvium");
    Attendee* attendee2 = new Attendee("Parth");

    // Demonstrate abstraction by calling public methods (internal details hidden)
    session1->displayDetails();
    session2->displayDetails();

    attendee1->attendSession(*session1);
    attendee2->attendSession(*session2);

    // Display static counts using public static functions
    Session::displaySessionCount();
    Attendee::displayAttendeeCount();

    // Free dynamically allocated memory
    delete session1;
    delete session2;
    delete attendee1;
    delete attendee2;

    return 0;
}
