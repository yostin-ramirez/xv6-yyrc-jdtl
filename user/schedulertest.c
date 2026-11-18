#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  for (int i = 0; i < 3; i++) {
    if (fork() == 0) {
      for (int n = 0; n < 40; n++) {
        for (volatile int j = 0; j < 20000000; j++);
        printf("%d", i);
      }
      exit(0);
    }
  }
  for (int i = 0; i < 3; i++) wait(0);
  printf("\n");
  exit(0);
}
