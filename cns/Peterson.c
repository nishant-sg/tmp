#include <pthread.h>
#include <unistd.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(const char* fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);

  if(fmt[0] && fmt[strlen(fmt) - 1] == ':') {
    fputc(' ', stderr);
    perror(NULL);
  } else {
    fputc('\n', stderr);
  }

  exit(0);
}

int turn;
int flag[2];

void* f0(void* arg) {
  while(1) {
    flag[0] = 1;
    turn = 1;
    while(flag[1] && turn == 1);
    puts("hello");
    flag[0] = 0;
    sleep(1);
  }
}

void* f1(void* arg) {
  while(1) {
    flag[1] = 1;
    turn = 0;
    while(flag[0] && turn == 0);
    puts("world");
    flag[1] = 0;
    sleep(1);
  }
}

int main(void) {
  pthread_t t0, t1;
    
  if(pthread_create(&t0, NULL, f0, NULL)) die("unable to create thread");
  if(pthread_create(&t1, NULL, f1, NULL)) die("unable to create thread");

  while(1);
}
