#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
using namespace std;
namespace ball{
    class Leauge {
    private:
        vector<Team*> teams;
    public:
        Leauge();
        Leauge(vector<Team*> new_team);
        void Leauge_in_random();
        void Leauge_half(vector<Team*> other_team_list);
        void initial_leauge();

    };
}

