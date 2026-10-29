#include "ServiceFunctions.h"
#include <iostream>
using namespace std;

void SearchService(const ServiceList& list) {
    int id;

    cout << "Enter Service ID to search: ";
    cin >> id;

    ServiceNode* result = list.SearchByID(id);

    if (result == nullptr) {
        cout << "Service not found.\n";
    } else {
        cout << "\nService Found!\n";
        cout << "Service ID: " << result->serviceID << '\n';
        cout << "Customer Name: " << result->customerName << '\n';
        cout << "Service Type: " << result->serviceType << '\n';
        cout << "Contact: " << result->contact << '\n';
    }
}

void ShowTotalServices(const ServiceList& list) {
    cout << "Total service records: "
         << list.Count() << '\n';
}