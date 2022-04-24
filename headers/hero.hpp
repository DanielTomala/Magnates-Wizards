#include <iostream>
#include <vector>
#include "weapon.hpp"

using namespace std;

class Hero {
private:
    vector <Weapon> weapons;
    string name;
    int hp;
public:
    Hero ();
    Hero (vector <Weapon> weapons, string name, int hp);
    void SetName(string name);
    void SetHp(int hp);

    vector <Weapon> GetWeapons() const;
    string GetName() const;
    string GetHp() const;

    void ChangeHp(const int damage);
};