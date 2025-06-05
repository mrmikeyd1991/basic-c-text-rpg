#ifndef PLAYER_H
#define PLAYER_H

struct Enemy;

struct Player {
  int hp;
  char name[20];
  int attack;
  int level;
  int exp;
  int exptolevelup;
  int maxhp;
  char weapon[30];
  int coins;
};

void stats(struct Player player);

void fight(struct Player *player, struct Enemy *enemy);

void levelcheck(struct Player *player);


#endif
