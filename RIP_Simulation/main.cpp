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
    Router(string id) :
     mRouterID(id)
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
    }
    
private:
    const string mRouterID;
    vector<RoutingTableEntry> routingTable;
};


// Initialize the Routers.
vector<Router> init()
{
    vector<Router> routers;
    Router R1("R1");
    R1.insertIntoTable("N1", "-", 1);
    R1.insertIntoTable("N2", "-", 1);
    routers.push_back(R1);
    
    Router R2("R2");
    R1.insertIntoTable("N2", "-", 1);
    R1.insertIntoTable("N3", "-", 1);
    routers.push_back(R1);
    
    Router R3("R3");
    R1.insertIntoTable("N3", "-", 1);
    R1.insertIntoTable("N4", "-", 1);
    routers.push_back(R1);
    
    Router R4("R4");
    R1.insertIntoTable("N4", "-", 1);
    R1.insertIntoTable("N5", "-", 1);
    routers.push_back(R1);
    
    Router R5("R5");
    R1.insertIntoTable("N5", "-", 1);
    R1.insertIntoTable("N6", "-", 1);
    routers.push_back(R1);
    
    Router R6("R6");
    R1.insertIntoTable("N6", "-", 1);
    R1.insertIntoTable("N7", "-", 1);
    routers.push_back(R1);
    
    Router R7("R7");
    R1.insertIntoTable("N7", "-", 1);
    R1.insertIntoTable("N8", "-", 1);
    routers.push_back(R1);
    
    return routers;
    
}



//////////////////////////////////////////////////////////////////////////////////////////
// Main
int main(int argc, const char * argv[]) {
    
    // RIP Protocol Simulation
    vector<Router> routers = init();
    
    routers[0].printTable();
    
    return 0;
}
