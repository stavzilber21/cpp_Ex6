#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
#include "Leauge.hpp"
using namespace std;
namespace ball{
    class Schedule {
    private:
        vector<Team*> teams;
    public:
        Schedule(vector<Team*> other);
        Schedule();
        ~Schedule();

    };
}

