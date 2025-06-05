#include "banner.h"
#include "enemy.h"
#include "player.h"
#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  initscr();
  start_color();
  curs_set(false);
  srand(time(NULL));
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  init_pair(6, COLOR_BLUE, COLOR_BLACK);

  struct Player person = {10, " ", 10, 1, 0, 20, 1000, "fist", 1000};
  mvprintw(10, 10, "What's your name, young warrior? : ");
  char name[20];
  scanw("%s", name);
  strcpy(person.name, name);
  refresh();
  banner();
  clear();
  while (person.hp >= 1) {
    stats(person);
    menu(&person);
    refresh();
    int choice;
    choice = getch();
    // first stage enemies
    if (choice == '1') {
      struct Enemy troll = {3, "mini troll", 5, 3, 1, "fists", 3};
      struct Enemy goblin = {4, "goblin", 8, 3, 1, "fists", 5};
      struct Enemy wolf = {6, "wolf", 10, 3, 2, "claws", 5};
      struct Enemy snake = {7, "Big Python", 15, 5, 2, "fangs", 6};
      struct Enemy bigfoot = {8, "Big Foot", 25, 5, 3, "big feet", 8};
      int Decide = rand() % 5 + 1;

      if (Decide == 1) {
        clear();
        fight(&person, &troll);
        refresh();
      }

      if (Decide == 2) {
        clear();
        fight(&person, &goblin);
        refresh();
      }

      if (Decide == 3) {
        clear();
        fight(&person, &wolf);
        refresh();
      }

      if (Decide == 4) {
        clear();
        fight(&person, &snake);
        refresh();
      }

      if (Decide == 5) {
        clear();
        fight(&person, &bigfoot);
        refresh();
      }
    }

    // 2nd stage enemies
    if (choice == '2') {
      struct Enemy troll = {15, "small troll", 5, 5, 5, "fists", 5};
      struct Enemy goblin = {15, "thirsty goblin", 8, 8, 5, "fists", 8};
      struct Enemy coyote = {15, "hungry coyote", 10, 8, 5, "teeth", 9};
      struct Enemy memphits = {25, "blood thirsty memphits", 15, 8, 8, "fangs",
                               9};
      struct Enemy scorpion = {25, "giant scorpion", 20, 8, 10, "stinger", 10};
      int Decide = rand() % 5 + 1;

      if (Decide == 1) {
        clear();
        fight(&person, &troll);
        refresh();
      }

      if (Decide == 2) {
        clear();
        fight(&person, &goblin);
        refresh();
      }

      if (Decide == 3) {
        clear();
        fight(&person, &coyote);
        refresh();
      }

      if (Decide == 4) {
        clear();
        fight(&person, &memphits);
        refresh();
      }

      if (Decide == 5) {
        clear();
        fight(&person, &scorpion);
        refresh();
      }
    }

    // 3rd stage enemies
    if (choice == '3') {
      struct Enemy troll = {40, "medium troll", 5, 5, 5, "fists", 5};
      struct Enemy goblin = {45, "hairy goblin", 8, 8, 5, "fists", 8};
      struct Enemy coyote = {45, "starved coyote", 10, 8, 5, "teeth", 9};
      struct Enemy memphits = {50, "blood thirsty vampire", 15, 8, 8, "fangs",
                               9};
      struct Enemy scorpion = {55, "giant anaconda", 20, 8, 10, "fangs", 10};
      int Decide = rand() % 5 + 1;

      if (Decide == 1) {
        clear();
        fight(&person, &troll);
        refresh();
      }

      if (Decide == 2) {
        clear();
        fight(&person, &goblin);
        refresh();
      }

      if (Decide == 3) {
        clear();
        fight(&person, &coyote);
        refresh();
      }

      if (Decide == 4) {
        clear();
        fight(&person, &memphits);
        refresh();
      }

      if (Decide == 5) {
        clear();
        fight(&person, &scorpion);
        refresh();
      }
    }

    // 4th stage enemies
    if (choice == '4') {
      struct Enemy troll = {60, "large troll", 5, 5, 5, "fists", 5};
      struct Enemy goblin = {60, "ice goblin", 8, 8, 5, "fists", 8};
      struct Enemy coyote = {70, "ice bear ", 10, 8, 5, "claws", 9};
      struct Enemy memphits = {75, "ice dragon", 15, 8, 8, "ice attack", 9};
      struct Enemy scorpion = {90, "ice cthulhu",    20, 8,
                               10, "great strength", 10};
      int Decide = rand() % 5 + 1;

      if (Decide == 1) {
        clear();
        fight(&person, &troll);
        refresh();
      }

      if (Decide == 2) {
        clear();
        fight(&person, &goblin);
        refresh();
      }

      if (Decide == 3) {
        clear();
        fight(&person, &coyote);
        refresh();
      }

      if (Decide == 4) {
        clear();
        fight(&person, &memphits);
        refresh();
      }

      if (Decide == 5) {
        clear();
        fight(&person, &scorpion);
        refresh();
      }
    }

    // shop stuff here
    if (choice == '5') {
      shopmenu(&person);
      int new_attack = person.attack;;
      person.attack = new_attack;
      refresh();
      getch();
    }

    // boss fight
    if (choice == '6' && person.level >= 100) {
      struct Enemy boss = {90, "ice cthulhu", 20, 8, 10, "great strength", 10};
      refresh();
      getch();

      if (boss.hp <= 0) {
        clear();
        printw(
            "YOU WON!!! now keep leveling up\nor leave and do this again!\n");
        refresh();
        getch();
      } else {
        clear();
        printw("you lost my guy, try again sometime.\n");
        refresh();
        getch();
      }
      printw("you have defeated the boss, you are the champion of the world\n");
      refresh();
    }

    if (choice == '7') {
      endwin();
      return 0;
    }

    else {
      clear();
    }
    stats(person);
    levelcheck(&person);
    clear();
  }
  clear();
  endwin(); // End ncurses mode

  return 0;
}
