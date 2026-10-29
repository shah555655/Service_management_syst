#ifndef SERVICELIST_H
#define SERVICELIST_H

#include "ServiceNode.h"

class ServiceList {
private:
    ServiceNode* head;

public:
    ServiceList();
    ~ServiceList();

    ServiceList(const ServiceList&) = delete;
    ServiceList& operator=(const ServiceList&) = delete;

    void Insert(int id, string name, string type, string phone);
    void Remove();
    void InsertAt(int index, int id, string name,
                  string type, string phone);
    void RemoveAt(int index);

    void Swap(int id1, int id2);
    void Sort();
    void Reverse();
    void Print() const;

    bool IsEmpty() const;
    bool IsNotEmpty() const;

    ServiceNode* SearchByID(int id) const;
    int Count() const;
};

#endif