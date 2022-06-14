#include <vector>
#include <iostream>
#include "sources/Game.cpp"
#include "sources/Leauge.cpp"
#include "sources/Schedule.cpp"
using namespace ball;
#include "sources/Team.cpp"
using namespace std;

int main(){
    vector<Team*> te;
    Leauge l;
    double talent;
    int new_name = 1;
    for (unsigned int i = 0; i < 20; ++i) {
        talent = rand() % 1;
        te.push_back(new Team(to_string(new_name), talent));
        new_name += 1;
    }
    for (unsigned int i = 0; i < 20; ++i) {
         cout<<te.at(i)->name+ ", ";
    }
    cout<<endl;

    l.teams=te;
    cout<<"The size is:"<<endl;
    cout<<l.teams.size()<<endl;
    try{
        Team* t = new Team("\n",0.4);
    }
    catch (exception e) {
        cout<<e.what();
        cout<<" the name invalid"<<endl;
    }
    Team* t1 = new Team("home",0.4);
    Team* t2 = new Team("out",0.3);
    Game* g = new Game(t1,t2);
    return 0;
}