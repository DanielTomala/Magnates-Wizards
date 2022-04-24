#include <iostream>
#include <vector>
#include "hero.hpp"


using namespace std;

Hero::Hero(){}

Hero::Hero(vector <Weapon> weapons, string name, int hp)
{
    this->weapons = weapons;
    this->name = name;
    this->hp = hp;
}

void Hero::SetName(string name)
{
    this->name = name;
}

void Hero::SetHp(int hp)
{
    this->hp = hp;
}

vector <Weapon> Hero::GetWeapons() const
{
    return this->weapons;
}

string Hero::GetName() const
{
    return this->name;
}

int Hero::GetHp() const
{
    return this->hp;
}

void Hero::GetDamage(int damage)
{
    if (damage > this->hp)
    {
        damage = this->hp;
    }
    this->hp -= damage;
}

void Hero::AddWeapon(Weapon weapon)
{
    this->weapons.push_back(weapon);
}

bool Hero::IsAlive() const
{
    if 
}