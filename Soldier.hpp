#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>

using namespace std;
class Soldier
{

public:
    int numTeam;
    int startPoint;
    int numHealth;
    int numDamage;
    Soldier(int numT, int sP, int numH, int numD): numTeam(numT), startPoint(sP), numHealth(numH), numDamage(numD) {}
  virtual  ~Soldier() {}

  double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  }

  virtual void attack (vector<vector<Soldier*>> &b, pair<int,int> location) = 0;


};