/*
 * tc: Long Lines
 * Returns lines longer than 80 characters.
 *
 * Author: Fulvia Mourikis
 * Date: 2026-11-02
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024

bool isLineTooLong(char *line);

int main(int argc, char **argv) {
  char *usage = "usage: ll <file1> [<file2> <file3> ...]\n\n";

  if (argc < 2) {
    fprintf(stderr, "%s", usage);
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    printf("[%s]:", argv[i]);

    FILE *fp = fopen(argv[i], "r");

    char line[MAX_LINE_SIZE];
    int lineNum = 0;
    bool isFileOk = true;

    while ((fgets(line, sizeof(line), fp))) {
      lineNum++;
      isFileOk = !isLineTooLong(line);
      if (!isFileOk) {
        printf("\n\t%d. %.80s...\n", lineNum, line);
      }
    }

    if (isFileOk) {
      printf(" OK\n");
    }
    fclose(fp);
  }
  return 0;
}

bool isLineTooLong(char *line) {
  int charCount = 0;

  while (line[charCount] != '\n') {
    if (charCount == MAX_LINE_SIZE) {
      return true;
    }
    charCount++;
  }

  if (charCount > 80) {
    return true;
  }
  return false;
}
