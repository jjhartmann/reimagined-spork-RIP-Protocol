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

class Router
{
public:
    Router()
    {
        ;
    }
    
    // Insert into table
    void InsertIntoTable(string dest, string nextRouter, int num)
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
        cout << "ROUTING TABLE:\t\t" << mRouterID << endl;
        cout << "Indx \tDestination \tNext Router \tDistance" << endl;
        cout << "---------------------------------------------------------" << endl;
        int index = 0;
        for (RoutingTableEntry v : routingTable)
        {
            cout << index << "  \t" << v.destinationNetwork << "      \t" << v.nextHopRouter << "       \t" << v.numberOfHops << endl;
        }
    }
    
private:
    vector<RoutingTableEntry> routingTable;
};



//////////////////////////////////////////////////////////////////////////////////////////
// Main 
int main(int argc, const char * argv[]) {
    
    // RIP Protocol Simulation
    
    
    
    
    return 0;
}
