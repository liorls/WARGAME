#include <iostream>
#include "SniperCommander.hpp"

void SniperCommander::attack(vector<vector<Soldier *>> &b, pair<int, int> location)
{
    Sniper::attack(b, location);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {

            Soldier *s = b[i][j];
            if (s != nullptr && s->numTeam == numTeam)
            {
                if (dynamic_cast<Sniper *>(s))
                    s->attack(b, {i, j});
            }
        }
    }
}
