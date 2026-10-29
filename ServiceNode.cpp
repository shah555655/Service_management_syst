#include "ServiceNode.h"

ServiceNode::ServiceNode(int id, string name, string type, string phone) {
    serviceID = id;
    customerName = name;
    serviceType = type;
    contact = phone;
    next = nullptr;
}