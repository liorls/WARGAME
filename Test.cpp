#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;

namespace WarGame
{

    TEST_CASE("Test 1")
    {
        Board board(10, 10);
        CHECK(board.has_soldiers(2) == false);
        CHECK(board.has_soldiers(3) == false);
        CHECK(board.has_soldiers(4) == false);
        CHECK(board.has_soldiers(8) == false);
        CHECK(board.has_soldiers(9) == false);
        CHECK(board.has_soldiers(1) == false);
        board[{0, 1}] = new FootSoldier(1);
        CHECK(board.has_soldiers(1) == true);
        board[{0, 3}] = new FootCommander(1);
        board[{0, 5}] = new Sniper(1);
        board[{0, 6}] = new SniperCommander(1);
        board[{0, 7}] = new Paramedic(1);
        board[{0, 8}] = new ParamedicCommander(1);
        CHECK(board.has_soldiers(2) == false);
        CHECK(board.has_soldiers(7) == false);
        board[{9, 1}] = new FootSoldier(2);
        board[{9, 3}] = new FootCommander(2);
        board[{9, 5}] = new FootSoldier(2);
        CHECK(board.has_soldiers(2) == true);
        board[{9, 6}] = new SniperCommander(2);
        board[{9, 7}] = new Paramedic(2);
        board[{9, 8}] = new ParamedicCommander(2);
        CHECK_THROWS_AS(board.move(1, {0, 2}, Board::MoveDIR::Left), std::invalid_argument);
        CHECK_THROWS_AS(board.move(2, {0, 2}, Board::MoveDIR::Left), std::invalid_argument);
        board.move(1, {0, 1}, Board::MoveDIR::Right);
        CHECK_THROWS_AS(board.move(1, {0, 2}, Board::MoveDIR::Right), std::invalid_argument);
        CHECK_THROWS_AS(board.move(2, {0, 5}, Board::MoveDIR::Right), std::invalid_argument);
        CHECK_THROWS_AS(board.move(2, {9, 7}, Board::MoveDIR::Right), std::invalid_argument);
        CHECK_THROWS_AS(board.move(1, {9, 5}, Board::MoveDIR::Right), std::invalid_argument);
        for (int i = 0; i < 100; i++)
        {
            CHECK(!board.has_soldiers(10));
        }
    }
} // namespace WarGame
