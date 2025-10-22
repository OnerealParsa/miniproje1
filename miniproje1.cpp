#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int studentID;
    int units;
    float gpa;
    string securityCode;
    Student* next;
};

void addStudent(Student*& head, const string& name, int studentID, int units, float gpa, const string& securityCode) {
    Student* cur = head;
    while (cur != nullptr) {
        if (cur->studentID == studentID) {
            cout << "shomare tekrari\n";
            return;
        }
        cur = cur->next;
    }
   
    

    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->studentID = studentID;
    newStudent->units = units;
    newStudent->gpa = gpa;
    newStudent->securityCode = securityCode;
    newStudent->next = nullptr;
    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Parvande ba movaffaghiat afzoode shod." << endl;
}

bool deleteStudent(Student*& head, int studentID) {
    if (head == nullptr) {
        return false;
    }

    if (head->studentID == studentID) {
        Student* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Student* current = head;
    while (current->next != nullptr && current->next->studentID != studentID) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Student* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}

Student* searchStudent(Student* head, int studentID) {
    Student* current = head;
    while (current != nullptr) {
        if (current->studentID == studentID) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool updateStudent(Student* head, int studentID, int newUnits, float newGPA) {
    Student* student = searchStudent(head, studentID);
    if (student == nullptr) {
        return false;
    }
    
    student->units = newUnits;
    student->gpa = newGPA;
    return true;
}

void displayAllRecords(Student* head) {
    if (head == nullptr) {
        cout << "Liste parvandeha khali ast" << endl;
        return;
    }

    Student* current = head;
    while (current != nullptr) {
        cout << "Name: " << current->name << endl;
        cout << "Shomare daneshjooee: " << current->studentID << endl;
        cout << "Tedad vahedha: " << current->units << endl;
        cout << "Moadel: " << current->gpa << endl;
        cout << "Code amni: " << current->securityCode << endl;
        cout << "------------------------" << endl;
        current = current->next;
    }
}

void displayMenu() {
    cout << "\n=== Systeme Modiriate Parvandehaye Daneshjooee ===" << endl;
    cout << "1. Afzoodane parvandeh jadid" << endl;
    cout << "2. Hazfe parvandeh" << endl;
    cout << "3. Jostojooye daneshjoo" << endl;
    cout << "4. Be rooz resanie nomarat" << endl;
    cout << "5. Namayeshe tamame parvandeha" << endl;
    cout << "0. Khorooj" << endl;
    cout << "Entekhab konid: ";
}

int main() {
    Student* head = nullptr;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                string name, securityCode;
                int studentID, units;
                float gpa;
                
                cout << "Name daneshjoo: ";
                getline(cin, name);
                cout << "Shomare daneshjooee: ";
                cin >> studentID;
                cout << "Tedad vahedha: ";
                cin >> units;
                cout << "Moadel: ";
                cin >> gpa;
                cin.ignore();
                cout << "Code amni: ";
                getline(cin, securityCode);
                
                addStudent(head, name, studentID, units, gpa, securityCode);
                break;
            }
            
            case 2: {
                int studentID;
                cout << "Shomare daneshjooee baraye hazf: ";
                cin >> studentID;
                
                if (deleteStudent(head, studentID)) {
                    cout << "Parvande ba movaffaghiat hazf shod." << endl;
                } else {
                    cout << "Parvande ba in shomare daneshjooee yaft nashod." << endl;
                }
                break;
            }
            
            case 3: {
                int studentID;
                cout << "Shomare daneshjooee baraye jostojo: ";
                cin >> studentID;
                
                Student* found = searchStudent(head, studentID);
                if (found != nullptr) {
                    cout << "\n=== Ettelaate Daneshjoo ===" << endl;
                    cout << "Name: " << found->name << endl;
                    cout << "Shomare daneshjooee: " << found->studentID << endl;
                    cout << "Tedad vahedha: " << found->units << endl;
                    cout << "Moadel: " << found->gpa << endl;
                    cout << "Code amni: " << found->securityCode << endl;
                } else {
                    cout << "Daneshjoo ba in shomare daneshjooee yaft nashod." << endl;
                }
                break;
            }
            
            case 4: {
                int studentID, newUnits;
                float newGPA;
                
                cout << "Shomare daneshjooee baraye be rooz resani: ";
                cin >> studentID;
                cout << "Tedad vahedhaye jadid: ";
                cin >> newUnits;
                cout << "Moadel jadid: ";
                cin >> newGPA;
                
                if (updateStudent(head, studentID, newUnits, newGPA)) {
                    cout << "Ettelaat ba movaffaghiat be rooz resani shod" << endl;
                } else {
                    cout << "Daneshjoo ba in shomare daneshjooee yaft nashod" << endl;
                }
                break;
            }
            
            case 5: {
                cout << "\n=== Tamame Parvandehaye Daneshjooee ===" << endl;
                displayAllRecords(head);
                break;
            }
            
            case 0: {
                cout << "Khorooj az barname..." << endl;
                break;
            }
            
            default: {
                cout << "Gozeye namotabar! Lotfan dobare talash konid" << endl;
                break;
            }
        }
    } while (choice != 0);
    Student* current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}