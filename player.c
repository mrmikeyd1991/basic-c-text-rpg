#include "player.h"
#include "enemy.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void stats(struct Player player) {
  mvprintw(4,10,"Name:  %s\n", player.name);
  if (player.hp >= 80) {
    
    mvprintw(3,10,"player hp: ");
    attron(COLOR_PAIR(1));
    mvprintw(3,25,"%d\n", player.hp); 
    attroff(COLOR_PAIR(1));
    
  }

  else if (player.hp < 80) {
    mvprintw(3,10,"player hp: ");
    attron(COLOR_PAIR(2));
    mvprintw(3,25,"%d\n", player.hp); 
    attroff(COLOR_PAIR(2));
    
  }

  else if (player.hp < 50 ) {
    mvprintw(3,10,"player hp: ");
    attron(COLOR_PAIR(4));
    mvprintw(3,25,"%d\n", player.hp); 
    attroff(COLOR_PAIR(4));
    
  }

  else if (player.hp < 35) {
    mvprintw(3,10,"player hp: ");
    attron(COLOR_PAIR(5));
    mvprintw(3,25,"%d\n", player.hp); 
    attroff(COLOR_PAIR(5));
    
  }
  mvprintw(5,10,"level:  %d\n", player.level);
  mvprintw(6,10,"exp:   %d\n", player.exp);
  if (player.exptolevelup < 0)
  {
    player.exptolevelup = 0;
  }
  mvprintw(7,10,"exp to get:  %d\n", player.exptolevelup - player.exp);
  mvprintw(8,10,"weapon:   %s\n", player.weapon);
  mvprintw(9,10,"attack:  %d\n", player.attack);
  mvprintw(10,10,"Coins:   %d\n\n\n", player.coins);
}

//fight function
void fight(struct Player *player, struct Enemy *enemy) {
  attron(COLOR_PAIR(2));
  if (strcmp(player->weapon, "fist") == 0) {
    player->attack += 1;
  }

  if (strcmp(player->weapon, "brass knuckles") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "metal bat") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "chain") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "wooden dagger") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "iron dagger") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "short sword") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "long sword") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "uzi") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "ak47") == 0) {
    player->attack = 10;
  }

    if (strcmp(player->weapon, "RPG") == 0) {
    player->attack = 10;
  }





  while (player->hp >= 1 && enemy->hp >= 1) {
    if (enemy->hp <= 0) enemy->hp = 0;
    attron(COLOR_PAIR(2));
    mvprintw(5,10,"-------------------------------------------------\n");
    mvprintw(6,10,"%s       HP:   %d\n", player->name, player->hp);
    mvprintw(7,10,"Weapon:  %s\n", player->weapon);
    mvprintw(8,10,"Attack:   %d\n", player->attack);
    mvprintw(9,10,"Level:  %d\n", player->level);
    mvprintw(10,10,"Coins:  %d\n", player->coins);
    mvprintw(11,10,"-------------------------------------------------\n");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvprintw(5,60,"-------------------------------------------------\n");
    mvprintw(6, 60,"%s       HP:   %d\n", enemy->name, enemy->hp);
    mvprintw(7, 60,"Weapon:  %s\n", enemy->weapon);        
    mvprintw(8, 60,"Attack:   %d\n", enemy->attack);
    mvprintw(9, 60,"Level:  %d\n", enemy->level);
    mvprintw(10, 60,"Coins:  %d\n", enemy->coins);
    mvprintw(11, 60,"-------------------------------------------------\n");
    attroff(COLOR_PAIR(3));
    mvprintw(20,25,"Press a key to attack or block\n");


    mvprintw(22,25,"a) attack");
    mvprintw(23,25,"b) block\n\n-->  ");
    refresh();

    char choice;
    int eChoice = rand() % 2 + 1;
    choice = getchar();
    clear();

    if (eChoice == 1 && choice == 'a') {
      mvprintw(20,20,"You both attacked\n\n");
      int Pattack = (player->attack > 0) ? rand() % player->attack : 0;
      int Eattack = (enemy->attack > 0) ? rand() % enemy->attack : 0;
      player->hp -= Eattack;
      enemy->hp -= Pattack;
      mvprintw(21,20,"%s was hit with %d damage\n", player->name, Eattack);
      mvprintw(22,20,"%s was hit with %d damage\n\n", enemy->name, Pattack);
      refresh(); getch(); clear();
    }

    else if (eChoice == 2 && choice == 'b') {
      printw("You both blocked, no one attacked\n");
      refresh(); getch(); clear();
    }

    else if (choice == 'b' && eChoice == 1) {
      clear();
      if (enemy->attack > 0) {
        int attack = rand() % enemy->attack + 1;
        int attackresults = (int)(attack / 2.0);
        player->hp -= attackresults;
        printw("You blocked and took %d damage\n", attackresults);
      } else {
        printw("Enemy's attack is zero, you took no damage.\n");
      }

      refresh(); getch(); clear();
    }

    else if (choice == 'a' && eChoice == 2) {
      mvprintw(10,20,"%s attacked but %s blocked, they take half damage!\n\n", player->name, enemy->name);
      if (player->attack > 0) {
        int attack = rand() % player->attack + 1;
        int fresults = (int)(attack / 2.0);
        enemy->hp -= fresults;
        mvprintw(20,20,"%s took %d damage\n", enemy->name, fresults);
      } else {
        mvprintw(20,20,"%s attack is zero, no damage done.", player->name);
      }
      refresh(); getch(); clear();
      if (enemy->hp <= 0) enemy->hp = 0;
    }

    if (player->hp <= 0 && enemy->hp >= 1) {
      clear();
      mvprintw(20,20,"%s has %d HP. You died my dude. Press something to leave.\n", player->name, player->hp);
      refresh(); getch(); return;
    }

    if (enemy->hp <= 0) {
      clear();
      attron(COLOR_PAIR(2));
      mvprintw(5,10,"-------------------------------------------------\n");
      mvprintw(6,10,"%s       HP:   %d\n", player->name, player->hp);
      mvprintw(7,10,"-------------------------------------------------\n");
      attroff(COLOR_PAIR(2));
      attron(COLOR_PAIR(3));
      mvprintw(5,60,"-------------------------------------------------\n");
      mvprintw(6, 60,"%s       HP:   %d\n", enemy->name, enemy->hp);
      mvprintw(7, 60,"-------------------------------------------------\n");
      attroff(COLOR_PAIR(3));
      attron(COLOR_PAIR(1));
      mvprintw(15,20,"You win the battle!!!!!!");
      int a = rand() % enemy->exp + 1;
      int b = rand() % enemy->coins + 1;
      if (a == '0')
      {
        a = 1;
      }

      if (b == '0')
      {
        b = 1;
      } 

      
      player->exp += a;
      player->coins += b;
      mvprintw(17,20, "you got %d coins and %d exp :D", b, a );
      attroff(COLOR_PAIR(1));
      refresh(); getch(); return;
    }

    clear();
  }
  attroff(COLOR_PAIR(2));
}

//level up stsem here

void levelcheck(struct Player *player)
{
  if (player->exp >= player->exptolevelup)
  {
    
    printw("you leveled up!!!\n\n");
    printw("--old stats--\n");
    printw("level:  %d\n", player->level);
    printw("attack:  %d\n", player->attack);
    printw("max hp:  %d\n", player->maxhp);
    printw("coins  %d\n\n", player->coins);
    player->level = player->level + 1;

    if (player->level <= 10)
    {
      player->exptolevelup += 10;
      player->maxhp += 5;
      player->attack += 5;
    }

    if (player->level >= 11 && player->level <= 20)
    {
      player->exptolevelup += 50;
      player->maxhp += 4;
      player->attack += 4;
    }

    if (player->level >= 21 && player->level <= 30)
    {
      player->exptolevelup += 70;
      player->maxhp += 3;
      player->attack += 3;
    }

    if (player->level >= 31 && player->level <= 50)
    {
      player->exptolevelup += 100;
      player->maxhp += 2;
      player->attack += 2;
    }

    if (player->level >= 51 && player->level <=70)
    {
      player->exptolevelup += 150;
      player->maxhp += 1;
      player->attack += 1;
    }

    if (player->level >=71 && player->level <=90)
    {
      player->exptolevelup += 225;
      player->maxhp += 1;
      player->attack += 1;
    }


    if (player->level >=91 && player->level <=120)
    {
      player->exptolevelup += 300;
      player->maxhp += 1;
      player->attack += 1;
    }


    if (player->level > 120)
    {
      player->level +=1;
      player->attack += 1;
      player->maxhp += 1;
      player->exptolevelup += 100;
    }

    int bonus = rand() % 25 + 1;
    player->coins += bonus;
    printw("--New stats--\n");
    printw("level:  %d\n", player->level);
    printw("attack:  %d\n", player->attack);
    printw("max hp:  %d\n\nheres a coin bonus of %d also!!\n", player->maxhp, bonus);
    printw("coins:   %d", player->coins);
    refresh();
    getch();
    printw("\n\npress something........");
    clear();



  }

}
