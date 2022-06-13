#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
using namespace std;
namespace ball{
    class Leauge {
    private:

    public:
        vector<Team*> teams;
        int num_names_in_len_4;
        Leauge();
        Leauge(vector<Team*> new_team);
        void Leauge_in_random();
        void rand_init(vector<Team*> new_team);
    };
}

