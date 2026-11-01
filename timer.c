/*
 * tc: Temperature converter
 * timer in the terminal (macOS)
 *
 * Author: Fulvia Mourikis
 * Date: 2026-11-31
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *usage =
      "usage: timer <time>\n\n"
      "EXAMPLE:\n"
      "       timer 20s - timer for 20 seconds\n"
      "       timer 3m - timer for 3 minutes\n"
      "       timer 3h40m15s - timer for 3 hours, 40 minutes, and 15 seconds\n";

  if (argc < 2) {
    fprintf(stderr, "%s", usage);
    exit(1);
  }

  bool hasH = false, hasM = false, hasS = false;
  int hours = 0, minutes = 0, seconds = 0;
  char timer[128];

  strcpy(timer, argv[1]);

  for (int i = 0; i < (int)strlen(argv[1]); i++) {
    char c = argv[1][i];

    if (!isdigit(c) && c != 'h' && c != 'm' && c != 's') {
      fprintf(stderr, "%s", usage);
      exit(1);
    }

    if (c == 'h') {
      hasH = true;
    }
    if (c == 'm') {
      hasM = true;
    }
    if (c == 's') {
      hasS = true;
    }
  }

  if (hasH) {
    hours = atoi(strtok(argv[1], "h"));
  }

  if (hasM) {
    if (hasH)
      minutes = atoi(strtok(NULL, "m"));
    else
      minutes = atoi(strtok(argv[1], "m"));
  }

  if (hasS) {
    if (hasH || hasM)
      seconds = atoi(strtok(NULL, "s"));
    else
      seconds = atoi(strtok(argv[1], "s"));
  }

  unsigned int time = hours * 3600 + minutes * 60 + seconds;

  // TODO: show remaining time
  sleep(time);

  char cmd[128];

  sprintf(cmd,
          "osascript -e 'display notification \"Your timer of %s has ended.\" "
          "with title \"Timer ended!\"'",
          timer);

  system(cmd);

  return 0;
}
