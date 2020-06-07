#pragma once
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic {

public:
    ParamedicCommander(int numTeam, int startPoint = 200, int numD = 0, int numH =  200): Paramedic(numTeam) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};


