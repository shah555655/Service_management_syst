#include "ServiceList.h"
#include <iostream>
#include <utility>
using namespace std;

ServiceList::ServiceList() {
    head = nullptr;
}

ServiceList::~ServiceList() {
    while (head != nullptr) {
        ServiceNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool ServiceList::IsEmpty() const {
    return head == nullptr;
}

bool ServiceList::IsNotEmpty() const {
    return head != nullptr;
}

// Insert a new service at the beginning
void ServiceList::Insert(int id, string name,
                         string type, string phone) {
    if (SearchByID(id) != nullptr) {
        cout << "Service ID already exists.\n";
        return;
    }

    ServiceNode* newNode =
        new ServiceNode(id, name, type, phone);

    newNode->next = head;
    head = newNode;

    cout << "Service added successfully.\n";
}

// Remove the first service
void ServiceList::Remove() {
    if (IsEmpty()) {
        cout << "Service list is empty.\n";
        return;
    }

    ServiceNode* temp = head;
    head = head->next;
    delete temp;

    cout << "First service removed.\n";
}

// Insert at a zero-based index
void ServiceList::InsertAt(int index, int id, string name,
                           string type, string phone) {
    if (index < 0 || index > Count()) {
        cout << "Invalid index.\n";
        return;
    }

    if (SearchByID(id) != nullptr) {
        cout << "Service ID already exists.\n";
        return;
    }

    ServiceNode* newNode =
        new ServiceNode(id, name, type, phone);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        ServiceNode* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    cout << "Service inserted at index "
         << index << ".\n";
}

// Remove a service at a zero-based index
void ServiceList::RemoveAt(int index) {
    if (index < 0 || index >= Count()) {
        cout << "Invalid index.\n";
        return;
    }

    ServiceNode* temp;

    if (index == 0) {
        temp = head;
        head = head->next;
    } else {
        ServiceNode* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;
    }

    delete temp;
    cout << "Service removed from index "
         << index << ".\n";
}

// Find a service using its ID
ServiceNode* ServiceList::SearchByID(int id) const {
    ServiceNode* current = head;

    while (current != nullptr) {
        if (current->serviceID == id) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

// Swap service details using IDs
void ServiceList::Swap(int id1, int id2) {
    ServiceNode* first = SearchByID(id1);
    ServiceNode* second = SearchByID(id2);

    if (first == nullptr || second == nullptr) {
        cout << "One or both service IDs were not found.\n";
        return;
    }

    if (first == second) {
        cout << "Both IDs are the same; no swap needed.\n";
        return;
    }

    swap(first->serviceID, second->serviceID);
    swap(first->customerName, second->customerName);
    swap(first->serviceType, second->serviceType);
    swap(first->contact, second->contact);

    cout << "Service details swapped successfully.\n";
}

// Sort services by ID in ascending order
void ServiceList::Sort() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Not enough services to sort.\n";
        return;
    }

    for (ServiceNode* i = head; i->next != nullptr;
         i = i->next) {
        for (ServiceNode* j = i->next; j != nullptr;
             j = j->next) {

            if (i->serviceID > j->serviceID) {
                swap(i->serviceID, j->serviceID);
                swap(i->customerName, j->customerName);
                swap(i->serviceType, j->serviceType);
                swap(i->contact, j->contact);
            }
        }
    }

    cout << "Services sorted by ID.\n";
}

// Reverse the linked list
void ServiceList::Reverse() {
    ServiceNode* previous = nullptr;
    ServiceNode* current = head;

    while (current != nullptr) {
        ServiceNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
    cout << "Service list reversed.\n";
}

// Display all service records
void ServiceList::Print() const {
    if (IsEmpty()) {
        cout << "No services available.\n";
        return;
    }

    ServiceNode* current = head;

    cout << "\n--- Service Center Records ---\n";

    while (current != nullptr) {
        cout << "Service ID: " << current->serviceID << '\n';
        cout << "Customer Name: " << current->customerName << '\n';
        cout << "Service Type: " << current->serviceType << '\n';
        cout << "Contact: " << current->contact << '\n';
        cout << "-----------------------------\n";

        current = current->next;
    }
}

// Count total service records
int ServiceList::Count() const {
    int total = 0;
    ServiceNode* current = head;

    while (current != nullptr) {
        total++;
        current = current->next;
    }

    return total;
}