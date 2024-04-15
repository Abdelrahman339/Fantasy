#include <iostream>
using namespace std;

class competition {

protected:

    void static UpdateFootballerPoints(/*FootballerName  ,*/ int CurrentGoals, int CurrentAssists, bool redCard, bool yellowCard, bool cleanSheet) {};
    void static UpdateFootballerPrice() {};//based on points
    bool checkPosition(string& footballerName, vector<footballPlayer>& footballers) {};
};
