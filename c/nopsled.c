#include <stdio.h>
#include <string.h>

void func(char* arg) {
  char str[4];
  printf("%d %p\n", (int)strlen(arg), str);

  strcpy(str, arg);

  printf("End of func!\n");
}

int main(int argc, char *argv[]) {
  if(argc > 1)
    func(argv[1]);

  printf("End of main!\n");
  return 0;
}
