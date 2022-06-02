#include "../../../headers/game_logic/heroes/hero_attributes.hpp"

const HeroAttributes heroAttributes{
    {std::make_tuple(EArcher, Damage), {100, 2, 30, 1, 2}},
    {std::make_tuple(EArcher, Balanced), {100, 2, 25, 1, 3}},
    {std::make_tuple(EArcher, Range), {100, 2, 20, 1, 4}},

    {std::make_tuple(EKnight, Damage), {200, 1, 50, 1, 1}},
    {std::make_tuple(EKnight, Balanced), {200, 2, 45, 1, 1}},
    {std::make_tuple(EKnight, Range), {200, 3, 40, 1, 1}},

    {std::make_tuple(EMage, Damage), {150, 2, 35, 1, 1}},
    {std::make_tuple(EMage, Balanced), {150, 2, 30, 1, 2}},
    {std::make_tuple(EMage, Range), {150, 2, 25, 1, 3}},

    {std::make_tuple(EMedic, Damage), {80, 2, 15, 1, 1, 30}},
    {std::make_tuple(EMedic, Balanced), {80, 2, 10, 1, 2, 40}},
    {std::make_tuple(EMedic, Range), {80, 2, 5, 1, 3, 50}},

    {std::make_tuple(ENinja, Damage), {100, 3, 30, 1, 2}},
    {std::make_tuple(ENinja, Balanced), {100, 3, 25, 1, 3}},
    {std::make_tuple(ENinja, Range), {100, 3, 20, 1, 4}},

    {std::make_tuple(EIceDruid, Damage), {150, 2, 30, 1, 1}},
    {std::make_tuple(EIceDruid, Balanced), {150, 2, 25, 1, 2}},
    {std::make_tuple(EIceDruid, Range), {150, 2, 20, 1, 3}},

    {std::make_tuple(ETrebuchet, Damage), {100, 0, 50, 1, 4}},
    {std::make_tuple(ETrebuchet, Balanced), {100, 0, 45, 1, 5}},
    {std::make_tuple(ETrebuchet, Range), {100, 0, 40, 1, 6}},

    {std::make_tuple(ECatapult, Damage), {100, 0, 70, 1, 4}},
    {std::make_tuple(ECatapult, Balanced), {100, 0, 60, 1, 5}},
    {std::make_tuple(ECatapult, Range), {100, 0, 50, 1, 6}},
};