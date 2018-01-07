#pragma once

#include <vector>

enum Effect { Poison, Fire, Stun };

class Move {
    public:
        Move();
        Move(int attack, int health, float miss_chance, Effect effect, std::string name, std::string description);
        virtual ~Move();

        int attack;
        int restored_health;
        float miss_chance;
        Effect effect;

        std::string name;
        std::string description;
};

virtual class Enemy;
virtual class Adventurer;

virtual class Enemy {
    public:
        std::string name;
        int attack;
        int health;
        std::vector<Effect> effects;

        void attack(Adventurer* adv);
}

virtual class Adventurer {
    public:
        Adventurer();
        virtual ~Adventurer();

        std::string name;
        int health;
        std::vector<Effect> effects;
        Move[] moves;
        
        void move(Enemy enemy, int index);
};
