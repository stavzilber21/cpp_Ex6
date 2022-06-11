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
        int result;
        Game(Team* in,Team* out );
        void points();
        string winner();
        void start_game();
    };
}