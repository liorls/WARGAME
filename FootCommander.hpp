#pragma once
#include "FootSoldier.hpp"

class FootCommander : public FootSoldier {

public:
    FootCommander(int numTeam, int startPoint = 150, int numD = 20, int numH =  150): FootSoldier(numTeam) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};