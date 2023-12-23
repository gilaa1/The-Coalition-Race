#pragma once
#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"


class Simulation;
class Coalition;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy); //constructor
    virtual ~Agent();
    Agent(const Agent &other);
    Agent(Agent &&other);
    Agent& operator=(const Agent &other);
    Agent& operator=(Agent &&other);

    int getPartyId() const;
    int getId() const;
    bool getIsIdle() const;
    SelectionPolicy *getSelectionPolicy() const;
    void step(Simulation &simulation);
    void setAgentId(int agentId);
    void setPartyId(int partyId);
    void setIsIdle(bool isIdle);
    Agent clone(int agentId, int partyId) const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    bool mIsIdle;
    int mCoalitionId;

};
