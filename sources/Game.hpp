#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
using namespace std;
namespace ball {
    class Game {
    public:
        Team *team_in;
        Team *team_out;
        Game(Team* in,Team* out );
        void winner();
        int start_game(double min, double max);
    };
}