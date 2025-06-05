#ifndef ENEMY_H
#define ENEMY_H
struct Player;

struct Enemy {
  int hp;
  char name[25];
  int attack;
  int exp;
  int level;
  char weapon[30];
  int coins;
  
};


void sayhi(struct Enemy enemy);

#endif
