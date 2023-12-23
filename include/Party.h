#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class JoinPolicy;
class Simulation;
class Coalition;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); //constructor
    virtual ~Party();
    Party(const Party &other);
    Party(Party &&other);
    Party& operator=(const Party &other);
    Party& operator=(Party &&other);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;
    vector<vector<int>> &getOffers();
    void setTimer();
    void setCoalitionId(int newId);
    
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    int mCoalitionId;
    vector<vector<int>> mOffers;
};
