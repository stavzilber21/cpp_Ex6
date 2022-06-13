#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"
using namespace std;
namespace ball{
    class Schedule {

    public:
        vector<Team*> teams;
        int num_of_teko;
        Schedule(vector<Team*> other);
        vector<Game*> schedule ();

    };
}

