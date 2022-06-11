#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
#include "Leauge.hpp"
#include "random"
int MAX =20;
using namespace std;
namespace ball {

    Leauge::Leauge() {}

    Leauge::Leauge(vector<Team*> new_team) {
        if (new_team.size() > MAX) {
            throw invalid_argument("20 is the max number");
        }
        for (unsigned int i = 0; i < MAX; i++) {
            this->teams.push_back(new_team.at(i));
        }
    }

    void Leauge::Leauge_in_random() {
        vector<string> names;
        for (unsigned int i = 0; i < MAX; ++i) {
            char ch = 'a';
            string str;
            str.push_back(ch);
            names.push_back(str);
            ch++;
            str.clear();
        } //'a','b', ...
        double t;
        for (unsigned int i = 0; i < MAX; ++i) {
            t = rand() % 1;
            this->teams.push_back(new Team(names.at(i), t));
        }
    }

    void Leauge::rand_init(vector<Team*> new_team) {
        if (new_team.size() >= MAX) {
            throw invalid_argument("It should be partially filled");
        }
        double t;
        int new_name = 0;
        for (unsigned int i = 0; i < new_team.size(); ++i) {
            this->teams.push_back(new_team.at(i));
        }
        while (this->teams.size() < MAX) {
            t = rand() % 1;
            this->teams.push_back(new Team(to_string(new_name), t));
            new_name += 1;
        }

    }

}