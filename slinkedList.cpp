#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void addelement(node **head);
void display(node *head);

void addelement(node **head) {
    int num;
    cout <<"Enter the number: ";
    cin >> num;

    node *temp = new node;
    temp->data = num;
    temp->next = nullptr;

    if (*head == nullptr) {
        *head = temp;
    } else {
        node *current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

void display(node *head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Linked List:" << endl;
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main() {
    node *head = nullptr;
    int ch;
    while (true) {
        cout << "Enter one of the following choices:" << endl;
        cout << "1. Add New Element" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                addelement(&head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                return 0;
            default:
                cout << "Choose a correct option." << endl;
                break;
        }
    }
    return 0;
}
