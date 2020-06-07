#include <iostream>
#include "Board.hpp"
#include "Soldier.hpp"

using namespace WarGame;

Soldier*& Board::operator[](std::pair<int,int> location){

    return board[location.first][location.second];
}
    
Soldier* Board::operator[](std::pair<int,int> location) const{

    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    Soldier* s = (*this)[source];
    if(s == nullptr)
        throw invalid_argument("No soldier at the source point");
    if(s->numTeam != player_number)
        throw invalid_argument("The move is illegal");
    if(source.first >= board.size() || source.first < 0 || source.second >= board[0].size() || source.second < 0)
        throw invalid_argument("Out of the board");
    
    std::pair<int,int> step;
    switch (direction)
    {
    case Up:
        step.first = source.first + 1;
        step.second = source.second;
        break;
    case Down:
        step.first = source.first - 1;
        step.second = source.second;
        break;
    case Left:
        step.first = source.first;
        step.second = source.second - 1;
        break;
    case Right:
        step.first = source.first;
        step.second = source.second + 1;
        break;
    }
    
    if(step.first >= board.size() || step.first < 0 || step.second >= board[0].size() || step.second < 0)
        throw invalid_argument("Out of the board");
    if((*this)[step] != nullptr)
        throw invalid_argument("The move is illegal");

    (*this)[step] = s;
    (*this)[source] = nullptr;

    s->attack(board,step);
}

bool Board::has_soldiers(uint player_number) const{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *s = (*this)[{i,j}];
            if(s != nullptr && s->numTeam == player_number)
            return true;
        }
        
    }
    
    return false;
}
    
