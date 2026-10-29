#ifndef SERVICENODE_H
#define SERVICENODE_H

#include <string>
using namespace std;

class ServiceNode {
public:
    int serviceID;
    string customerName;
    string serviceType;
    string contact;
    ServiceNode* next;

    ServiceNode(int id, string name, string type, string phone);
};

#endif