// COMSC-210 | Lab 18 | Ali Saeed
// IDE used: nvim / vscode
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    float rating;
    string comments;
    Node *next;
};

void output(Node*);
void addF(Node*&);
void addT(Node*&);
void delAll(Node*&);

int main() {
    Node *head = nullptr;
    int choice;
    string yes_or_no = "Y";
    // create a linked list of size SIZE with random numbers 0-99
    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "\tChoice: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        while (yes_or_no != "n" && yes_or_no != "N") {
            addF(head);
            cout << "Enter another review? Y/N: ";
            getline(cin, yes_or_no);
        }
    }
    else {
        while (yes_or_no != "n" && yes_or_no != "N") {
            addT(head);
            cout << "Enter another review? Y/N: ";
            getline(cin, yes_or_no);
        }
    }
    output(head);

    delAll(head);
    return 0;
}

void output(Node * hd) {
    float average;
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    cout << "Outputting all reviews: " << endl;
    while (current) {
        cout << "\tReview #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        average += current->rating;
        current = current->next;
    }
    cout << "\tAverage: " << average / count << endl;
    cout << endl;
}

void addF(Node*& head) {
    Node *temp = new Node;
    float rating;
    string comment;
   // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = temp;
            cout << "Enter review rating 0-5: ";
            cin >> rating;
            cin.ignore();
            cout << "Enter review coments: ";
            getline(cin, comment);
            temp->next = nullptr;
            temp->rating = rating;
            temp->comments = comment;
        }
        else { // its a second or subsequent node; place at the head
            temp->next = head;
            cout << "Enter review rating 0-5: ";
            cin >> rating;
            cin.ignore();
            cout << "Enter review coments: ";
            getline(cin, comment);
            temp->rating = rating;
            temp->comments = comment;
            head = temp;
        }
}

void addT(Node*& head) {
    float rating;
    string comment;
    Node * temp = new Node;
    temp->next = nullptr;
    cout << "Enter review rating 0-5: ";
    cin >> rating;
    cin.ignore();
    cout << "Enter review coments: ";
    getline(cin, comment);
    temp->rating = rating;
    temp->comments = comment;

    if (head == nullptr) {
        head = temp;
    }
    else {
        Node* temp2 = head;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
  
}

void delAll(Node*& head) {
    Node * current = head;
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}