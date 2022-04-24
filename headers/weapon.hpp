#include <iostream>
#include <vector>

using namespace std;

class Weapon {
private:
    string name;
    int damage;
public:
    void SetName(string name);
    void SetDamage(int damage);

    string GetName() const;
    int GetDamage() const;
};