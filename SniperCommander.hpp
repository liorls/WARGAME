#pragma once
#include "Sniper.hpp"

class SniperCommander : public Sniper {

public:
    SniperCommander(int numTeam, int startPoint = 120, int numD = 100, int numH =  120): Sniper(numTeam) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};

