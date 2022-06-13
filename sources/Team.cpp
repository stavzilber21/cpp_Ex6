#include "Team.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ball;
Team::Team(){
    this->name="";
    this->talent = 0.0;
    this->num_wins=0;
    this->num_losses=0;
    this->points_good=0;
    this->points_loss=0;
    this->num_wins_in_a_row=0;
    this->num_losses_in_a_row=0;
    this->num_wins_in_a_row_last=0;
    this->num_losses_in_a_row_last=0;

}
Team::Team(string name, double talent){
    if(name == "\n" || name == " " || name == "\t"){
        throw invalid_argument("The name is invalid");
    }
    if(talent > 1 || talent < 0){
        throw invalid_argument("Invalid talent");
    }
    this->name=name;
    this->talent=talent;
    this->points_good=0;
    this->points_loss=0;
}


