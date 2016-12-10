#include <stdio.h>

static int x = -5;

int main(int argc, char *argv[]) {
  if(argc > 1) {
    printf(argv[1]);
    printf("\n%d 0x%16x", x, &x);
  }
  return 0;
}
