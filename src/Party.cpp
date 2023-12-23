#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "Coalition.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mTimer(-1), mCoalitionId(-1), mOffers{}
{
}

Party::~Party() // destructor
{
    if (mJoinPolicy)
    {
        delete (mJoinPolicy);
        mJoinPolicy = nullptr;
    }
}

// copy constructor
Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->Clone()), mState(other.mState), mTimer(other.mTimer), mCoalitionId(other.mCoalitionId), mOffers(other.mOffers)
{
}

// move constructor
Party::Party(Party &&other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mTimer(other.mTimer), mCoalitionId(other.mCoalitionId), mOffers(other.mOffers)
{
    other.mJoinPolicy = nullptr;
}

Party &Party::operator=(const Party &other) // copy assignment operator
{
    if (this != &other)
    {
        if (mJoinPolicy)
        {
            delete (mJoinPolicy);
            mJoinPolicy = nullptr;
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->Clone();
        mState = other.mState;
        mTimer = other.mTimer;
        mCoalitionId = other.mCoalitionId;
        mOffers = other.mOffers;
    }
    return *this;
}
Party &Party::operator=(Party &&other) // move assignment operator
{
    if (this != &other)
    {
        if (mJoinPolicy)
        {
            delete (mJoinPolicy);
            mJoinPolicy = nullptr;
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        mTimer = other.mTimer;
        mCoalitionId = other.mCoalitionId;
        mOffers = other.mOffers;
        other.mJoinPolicy = nullptr;
    }
    return *this;
}
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string &Party::getName() const
{
    return mName;
}

int Party::getId() const
{
    return mId;
}
vector<vector<int>> &Party::getOffers()
{
    return mOffers;
}

void Party::step(Simulation &s)
{
    switch (mState)
    {
    case Waiting:
        break;
    case CollectingOffers:
    {
        mTimer++;
        if (mTimer == 3)
        {
            mJoinPolicy->Join(s, (*this));
            mState = Joined;
        }
    }
    break;
    case Joined:
        break;
    }
}

void Party::setTimer()
{
    mTimer++;
}

void Party::setCoalitionId(int newId)
{
    mCoalitionId = newId;
}