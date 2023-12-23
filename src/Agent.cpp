#include "Agent.h"
#include "Simulation.h"
#include "Coalition.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mIsIdle(false), mCoalitionId(agentId)
{
}

Agent::~Agent() // destructor
{
    if (mSelectionPolicy)
    {
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
    }
}

// copy constructor
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->Clone()), mIsIdle(other.mIsIdle), mCoalitionId(other.mCoalitionId)
{
}

// move constructor
Agent::Agent(Agent &&other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mIsIdle(other.mIsIdle), mCoalitionId(other.mCoalitionId)
{
    other.mSelectionPolicy = nullptr;
}

Agent &Agent::operator=(const Agent &other) // copy assignment operator
{
    if (this != &other)
    {
        if (mSelectionPolicy)
        {
            delete mSelectionPolicy;
            mSelectionPolicy = nullptr;
        }
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->Clone();
        mIsIdle = other.mIsIdle;
        mCoalitionId = other.mCoalitionId;
    }
    return *this;
}

Agent &Agent::operator=(Agent &&other) // move assignment operator
{
    if (this != &other)
    {
        if (mSelectionPolicy)
        {
            delete mSelectionPolicy;
            mSelectionPolicy = nullptr;
        }
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        mIsIdle = other.mIsIdle;
        mCoalitionId = other.mCoalitionId;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

bool Agent::getIsIdle() const
{
    return mIsIdle;
}

SelectionPolicy *Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::step(Simulation &simulation)
{
    if (!mIsIdle)
    {
        const vector<int> neighbors = simulation.getGraph().getNeighborsOf(mPartyId);
        int PartyRock = mSelectionPolicy->Select(neighbors, simulation.getGraph(), simulation.getCoalition(mCoalitionId), mPartyId);
        if (PartyRock != -1)
            simulation.getGraph().addOffer(PartyRock, simulation.getCoalition(mCoalitionId));
        else
            mIsIdle = true;
    }
}

void Agent::setAgentId(int agentId)
{
    mAgentId = agentId;
}

void Agent::setPartyId(int partyId)
{
    mPartyId = partyId;
}

void Agent::setIsIdle(bool isIdle)
{
    mIsIdle = isIdle;
}
