#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace ball {
    class Team {
    public:
        string name;
        double talent;
        int points_good;
        int points_loss;
        int num_wins;
        int num_losses;
        int num_wins_in_a_row;
        int num_losses_in_a_row;
        int num_wins_in_a_row_last;
        int num_losses_in_a_row_last;
        Team();
        Team(string n, double t);

    };
}