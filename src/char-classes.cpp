#include "char-classes.h"

Move::Move() {
    attack = 0;
    restored_health = 0;
    effect = Effect::None;
}

Move::Move(int attack, int restored_health, float miss_chance, Effect effect, std::string name, std::string description) {
    this->attack = attack;
    this->restored_health = restored_health;
    this->miss_chance = miss_chance;
    this->effect = effect;

    this->name = name;
    this->description = description;
}

Enemy::Enemy() { }
virtual Enemy::~Enemy() { }

Enemy::Attack(Adventurer* adv) {
    int index;
    // TODO: Select random adventurer
    
    adv[index].health -= this.attack;
}

Adventurer::Adventurer() { }
virtual Adventurer::~Adventurer() { }

void Adventurer::move(Enemy* enemy, int index) {
    // if (random number <= miss chance)
    //     return;
    
    Move selected_move = moves[index]
    
    enemy->health -= selected_move.attack;
}
