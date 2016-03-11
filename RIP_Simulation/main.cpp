//
//  main.cpp
//  RIP_Simulation
//
//  Created by Jeremy Hartmann on 2016-03-10.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
/// Router Class
struct RoutingTableEntry
{
    RoutingTableEntry()
    {}
    
    RoutingTableEntry(string d, string n, int x) :
        destinationNetwork(d),
        nextHopRouter(n),
        numberOfHops(x)
    {}
    
    string destinationNetwork;
    string nextHopRouter;
    int numberOfHops;
};

//////////////////////////////////////////////////////////////////////////////////////////
/// Router Class
class Router
{
public:
    Router(int id) :
        mRouterID(id),
        mNext(NULL),
        mPrev(NULL)
    {
        ;
    }
    
    // Insert into table
    void insertIntoTable(string dest, string nextRouter, int num)
    {
        RoutingTableEntry entry(dest, nextRouter, num);
        routingTable.push_back(entry);
    }
    
    // Get an entry at index i
    RoutingTableEntry getTableEntry(int i)
    {
        if (i >= routingTable.size()) RoutingTableEntry();
    
        return routingTable[i];
    }
    
    // Get Router id
    int getId()
    {
        return mRouterID;
    }
    
    // Get Routing table
    vector<RoutingTableEntry> getRouteTable()
    {
        return routingTable;
    }
    
    // Set Next
    void setNext(Router* n)
    {
        mNext = n;
    }
    
    Router* getNext()
    {
        return mNext;
    }
    
    // set Prev
    void setPrev(Router* p)
    {
        mPrev = p;
    }
    
    Router* getPrev()
    {
        return mPrev;
    }
    
    // Print Routing table
    void printTable()
    {
        cout << "ROUTING TABLE:\t\t\t" << mRouterID << endl;
        cout << "Indx \tDestination \tNext Router \tDistance" << endl;
        cout << "------------------------------------------------" << endl;
        int index = 0;
        for (RoutingTableEntry v : routingTable)
        {
            cout << index << "     \t" << v.destinationNetwork << "            \t" << v.nextHopRouter << "           \t" << v.numberOfHops << endl;
            index++;
        }
        cout << endl;
    }
    
private:
    const int mRouterID;
    vector<RoutingTableEntry> routingTable;
    Router *mNext;
    Router *mPrev;
};


// Initialize the Routers.
Router* init()
{
    Router *R1 = new Router(0);
    R1->insertIntoTable("N1", "-", 1);
    R1->insertIntoTable("N2", "-", 1);
    
    
    Router *R2 = new Router(1);
    R1->insertIntoTable("N2", "-", 1);
    R1->insertIntoTable("N3", "-", 1);
    
    Router *R3 = new Router(2);
    R1->insertIntoTable("N3", "-", 1);
    R1->insertIntoTable("N4", "-", 1);
    
    Router *R4 = new Router(3);
    R1->insertIntoTable("N4", "-", 1);
    R1->insertIntoTable("N5", "-", 1);
    
    Router *R5 = new Router(4);
    R1->insertIntoTable("N5", "-", 1);
    R1->insertIntoTable("N6", "-", 1);
    
    Router *R6 = new Router(5);
    R1->insertIntoTable("N6", "-", 1);
    R1->insertIntoTable("N7", "-", 1);
    
    Router *R7 = new Router(6);
    R1->insertIntoTable("N7", "-", 1);
    R1->insertIntoTable("N8", "-", 1);
    
    R1->setNext(R2);
    R2->setPrev(R1);
    R2->setNext(R3);
    R3->setPrev(R2);
    R3->setNext(R3);
    R4->setPrev(R3);
    R4->setNext(R5);
    R5->setPrev(R4);
    R5->setNext(R6);
    R6->setPrev(R5);
    R6->setNext(R7);
    R7->setPrev(R6);
    
    return R1;
    
}

// Perform Rip on all routers.
// 1. Start with Router one, and propogate table throughout Other routers.
// 2. Move to router two, repeat.
void PerformRIP(vector<Router> &routers)
{
    int numberOfRouters = routers.size();
    
    
    // The rounds.
    for (int round = 0; round < numberOfRouters; ++round)
    {
        // Print each routers table
        cout << "****ROUND NUMBER " << round + 1 << "*****" <<endl;
        
    
    
    
}



//////////////////////////////////////////////////////////////////////////////////////////
// Main
int main(int argc, const char * argv[]) {
    
    // RIP Protocol Simulation
    Router *R1 = init();
    
    return 0;
}
