#include "banner.h"
#include "player.h"
#include <ncurses.h>
#include <string.h>

void banner() {
  clear();
  mvprintw(5, 10, "Welcome to BorinRPG, you will fight beasts and trolls");
  mvprintw(6, 10,  "You will also level up and get weapons and exp!!!!!!! maybe");
  mvprintw(7, 10,  "Press anything to go on........");
  refresh();
  getch();
}

void menu(struct Player *player) {
  attron(COLOR_PAIR(6));
  mvprintw(3,40,"1) go to woods   -easy-     3-8   hp\n");
  mvprintw(4,40,"2) go to dessert  -medium-  15-25 hp\n");
  mvprintw(5,40,"3) go to jungle   -hard-    40-55 hp\n");
  mvprintw(6,40,"4) go to icelands  -harder- 60-90 hp\n");
  mvprintw(7,40,"5) go to store");
  attroff(COLOR_PAIR(6));
  if (player->level < 100)
  {
    attron(COLOR_PAIR(5));
    mvprintw(8,40,"6) UNLOCK AT LVL 100!!!  -120 hp boss!!-\n");
    attroff(COLOR_PAIR(5));
    refresh();
  }
  else{
    attron(COLOR_PAIR(1));
    mvprintw(8,40,"6) go Fight MAN BEAR PIG!!   -120 hp!-\n");
    attroff(COLOR_PAIR(1));
    refresh();
  }
  mvprintw(9,40,"7) Quit    - no progress will be saved.....yet");
  attroff(COLOR_PAIR(4));
}


void shopmenu(struct Player *player)
{
  bool leave = false;

  while(leave == false)
  {
    clear();
    printw("Welcome to the shop, here you can buy potions and weapons\n");
    printw("1) buy potion\n");
    printw("2) buy weapon\n");
    printw("3) leave store\n\n");
    printw("\nCoins:    %d\n", player->coins);
    printw("Weapon:  %s\n\n-->  ", player->weapon);
    printw("%s hp: %d\n", player->name, player->hp);
    refresh();
    int pick;

    pick = getch();
    //potion picking
    if (pick == '1')
    {
      clear();
      printw("1) small potion   - 25 coins\n");
      printw("2) half potion  - 50 coins\n");
      printw("3) full heal      - 100 coins\n");
      printw("you have:  %d coins\n", player->coins);
      printw("--> ");
      refresh();
      int pickpotion;
      pickpotion = getch();
      //small potion
      if (pickpotion == '1')
      {
        if (player->coins < 25)
        {
          clear();
          printw("you dont have enough coins bro.......\n-->  press something");
          refresh();
          getch();
        }

        else
        {
          player->hp = player->hp + 25;
          player->coins = player->coins - 25;
          if (player->hp > player->maxhp)
          {
            player->hp = player->maxhp;
          }

          clear();

        }
        
      }
      //half heal potion
      if (pickpotion == '2')
      {
        if (player->coins < 50)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else
        {
          int halfhealth = player->maxhp / 2;
          player->hp += halfhealth;
          player->coins -= 50;

          if (player->hp > player->maxhp)
          {
            player->hp = player->maxhp;
          }

        }
        
      }

      //full heal potion

      if (pickpotion == '3')
      {
        if (player->coins < 100)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else
        {
          int max = player->maxhp;
          player->hp = max;
          player->coins -= 100;

        }
        
      }

    }

    if (pick == '2')
    {
      clear();
      printw("\n\n1)  brass knuckles   +1 attack    $20\n");
      printw("2)  metal bat        +2 attack    $30\n");
      printw("3)  chain            +3 attack    $50\n");
      printw("4)  wooden dagger    +5 attack    $80\n");
      printw("5)  iron dagger     +7 attack    $100\n");
      printw("6)  short sword      +15 attack   $120\n");
      printw("7)  long sword       +25 attack   $160\n");
      printw("8)  uzi              +35 attack   $200\n");
      printw("9)  ak47             +45 attack   $250\n");
      printw("0)  RPG              +50 attack   $1000\n\n-->  ");


      int Weapon;
      Weapon = getch();
      //brrrass knuckles
      if (Weapon == '1')
      {
        clear();
        if (player->coins < 20)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "brass knuckles");
          player->coins -= 20;
          player->attack += 1;
        }
      }
      //metal bat
      if (Weapon == '2')
      {
        clear();
        if (player->coins < 30)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "metal bat");
          player->coins -= 30;
          player->attack += 2;
        }
      }

      //chain
      if (Weapon == '3')
      {
        clear();
        if (player->coins < 50)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "chain");
          player->coins -= 50;
          player->attack = 3;
        }
      }

      //wooden dagger
      if (Weapon == '4')
      {
        clear();
        if (player->coins < 80)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "wooden dagger");
          player->coins -= 80;
          player->attack =  5;
        }
      }
      //irron dagger
      if (Weapon == '5')
      {
        clear();
        if (player->coins < 100)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "irron dagger");
          player->coins -= 100;
          player->attack += 7;
          int new_attack = player->attack;
          player->attack = new_attack;
        }
      }
      //short sword
      if (Weapon == '6')
      {
        clear();
        if (player->coins < 120)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "short sword");
          player->coins -= 120;
          player->attack += 15;
        }
      }
      //long sword
      if (Weapon == '7')
      {
        clear();
        if (player->coins < 160)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "long sword");
          player->coins -= 160;
          player->attack += 25;
        }
      }

      //uzi
      if (Weapon == '8')
      {
        clear();
        if (player->coins < 200)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "uzi");
          player->coins -= 200;
          player->attack += 35;
        }
      }
      //ak47
      if (Weapon == '9')
      {
        clear();
        if (player->coins < 250)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "ak47");
          player->coins -= 250;
          player->attack += 45;
        }
      }
      //rpg
      if (Weapon == '0')
      {
        clear();
        if (player->coins < 1000)
        {
          clear();
          printw("you dont have enough coins bro.......\npress something");
          refresh();
          getch();
        }

        else{
          strcpy(player->weapon, "rpg");
          player->coins -= 1000;
          player->attack += 50;
        }
      }




    }

    


    //leave
    if (pick == '3')
    {
      leave = true;
    }

  }


}


