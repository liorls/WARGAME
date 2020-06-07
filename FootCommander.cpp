#include <iostream>
#include "FootCommander.hpp"

void FootCommander::attack(vector<vector<Soldier *>> &b, pair<int, int> location)
{
    FootSoldier::attack(b, location);

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            Soldier *s = b[i][j];
            if(s != nullptr && s->numTeam == numTeam){
                if(dynamic_cast<FootSoldier*>(s))
                    s->attack(b,{i,j});
            }
        }
    }
}
