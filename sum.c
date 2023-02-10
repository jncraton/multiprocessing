#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 1600000000
#define PROCESSES 16

int main() {
  pid_t children[PROCESSES];

  for (int i = 0; i < PROCESSES; i++) {
    children[i] = fork();
    if (children[i] == -1) {
      printf("Error forking process %d\n", children[i]);
    } else if (children[i]) {
      printf("PID %d complete\n", children[i]);
      exit(1);
    }
  }

  for (int i = 0; i < PROCESSES; i++) {
    // Wait for children to terminate
    waitpid(children[i], NULL, 0);
  }

  printf("All processes complete");
  
  exit(0);
}