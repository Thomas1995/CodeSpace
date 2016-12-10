#include <stdio.h>

// asta e functia de care ai tu nevoie
void changeBase(int nr, int base, char* str) {
  int step, pos;
  for(step = 1; step < nr; step *= base);
  for(pos = 0; step; step /= base) {
    int ct = nr / step;
    nr -= ct * step;
    char c = ct < 10 ? ct + '0' : ct - 10 + 'A';
    str[pos++] = c;
  }
  str[pos] = '\0';
}

// ai aici cateva exemple
int main(void) {
  char buffer[10];

  changeBase(5, 2, buffer);
  printf("%s\n", buffer);

  changeBase(2, 2, buffer);
  printf("%s\n", buffer);

  changeBase(46, 2, buffer);
  printf("%s\n", buffer);

  changeBase(32, 32, buffer);
  printf("%s\n", buffer);

  changeBase(80, 32, buffer);
  printf("%s\n", buffer);

  return 0;
}
