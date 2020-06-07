 
#include <iostream>
#include "Sniper.hpp"

void Sniper::attack(vector<vector<Soldier*>> &board, pair<int,int> location){
 pair<double, Soldier *> strongest = make_pair(0, nullptr);

        int fir, sec;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                Soldier *s = board[i][j];

                if (s != nullptr && s->numTeam != numTeam)
                {
                    double points = s->startPoint;
                    if (points > strongest.first)
                    {
                        strongest.first = points;
                        strongest.second = s;
                        fir = i;
                        sec = j;
                    }
                }
            }
        }
        if (strongest.second != nullptr)
        {
            int new_points = strongest.second->startPoint - numDamage;
            if (new_points <= 0)
            {
                board[fir][sec] = nullptr;                
            }
            else
                strongest.second->startPoint=new_points;
        }
    }