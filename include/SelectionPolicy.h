#pragma once
#include <vector>
class Coalition;
class Graph;
class Agent;
using std::vector;

class SelectionPolicy 
{
    public:
        virtual int Select(vector<int> neighbors, Graph &mGraph, Coalition &coal, int mPartyId)=0;
        virtual SelectionPolicy* Clone() const = 0;
        virtual ~SelectionPolicy() = default;

};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        int Select(vector<int> neighbors, Graph &mGraph, Coalition &coal, int mPartyId) override;
        SelectionPolicy* Clone() const override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
    public:
        int Select(vector<int> neighbors, Graph &mGraph, Coalition &coal, int mPartyId) override;
        SelectionPolicy* Clone() const override;
};

