#pragma once
 
#include <vector>
#include "Agent.h"

using std::string;
using std::vector;
class Simulation;

class Coalition
{
public: 
    Coalition(int mandates, int partyId, int coalitionId);
    int getCoalitionMandates() const;
    int getCoalitionId() const;
    void addParty(int mandates, int id);
    

private:
    int mCoalitionMandates;
    vector<int> mPartiesIds;
    int mCoalitionId; 
};
