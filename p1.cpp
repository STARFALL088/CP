#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to sign up a new user
void signUp(const string& username, const string& password) {
    ofstream usersFile("users.txt", ios::app);
    usersFile << username << "|" << password << endl;
    usersFile.close();
}

// Function to log in an existing user
bool logIn(const string& username, const string& password) {
    ifstream usersFile("users.txt");
    string line;
    while (getline(usersFile, line)) {
        stringstream ss(line);
        string storedUsername, storedPassword;
        getline(ss, storedUsername, '|');
        getline(ss, storedPassword, '|');
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

// Function to add a new entry
void addEntry(const string& username, const string& title, const string& description) {
    ofstream entriesFile("entries.txt", ios::app);
    entriesFile << username << "|" << title << "|" << description << endl;
    entriesFile.close();
}

// Function to view entries of a user
vector<string> viewEntries(const string& username) {
    ifstream entriesFile("entries.txt");
    string line;
    vector<string> userEntries;
    while (getline(entriesFile, line)) {
        stringstream ss(line);
        string storedUsername, title, description;
        getline(ss, storedUsername, '|');
        getline(ss, title, '|');
        getline(ss, description, '|');
        if (storedUsername == username) {
            userEntries.push_back("Title: " + title + "\nDescription: " + description);
        }
    }
    return userEntries;
}

int main() {
    cout << "Welcome to the Journal Application!" << endl;
    while (true) {
        cout << "Do you want to (1) Sign Up or (2) Log In? (Enter 1 or 2): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string username, password;
            cout << "Enter a username: ";
            cin >> username;
            cout << "Enter a password: ";
            cin >> password;
            signUp(username, password);
            cout << "Sign Up successful! You can now log in." << endl;
        } else if (choice == 2) {
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            if (logIn(username, password)) {
                cout << "Log In successful!" << endl;
                while (true) {
                    cout << "Do you want to (1) Add Entry or (2) View Entries? (Enter 1 or 2): ";
                    int action;
                    cin >> action;
                    if (action == 1) {
                        string title, description;
                        cout << "Enter the title of your entry: ";
                        cin.ignore();
                        getline(cin, title);
                        cout << "Enter the description of your entry: ";
                        getline(cin, description);
                        addEntry(username, title, description);
                        cout << "Entry added successfully!" << endl;
                    } else if (action == 2) {
                        vector<string> entries = viewEntries(username);
                        if (!entries.empty()) {
                            cout << "Your Entries:" << endl;
                            for (const string& entry : entries) {
                                cout << entry << endl;
                            }
                        } else {
                            cout << "No entries found." << endl;
                        }
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
            } else {
                cout << "Log In failed. Please check your username and password." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
