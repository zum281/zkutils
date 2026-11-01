/*
 * tc: Temperature converter
 * Convert between Celsius and Farhenheit
 *
 * Author: Fulvia Mourikis
 * Date: 2026-11-31
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  char *usage =
      "usage: tc {c|f} <temperature>\n\n"
      "       {c|l} indicates what the input needs to be converted to\n\n"
      "EXAMPLE:\n"
      "       tc c 100 - converts 100ºF to ºC\n";

  if (argc < 3) {
    fprintf(stderr, "%s", usage);
    exit(1);
  }

  if (strlen(argv[1]) > 1) {
    fprintf(stderr, "%s", usage);
    exit(1);
  }

  char type = argv[1][0]; // {c|f}

  if (type != 'c' && type != 'f') {
    fprintf(stderr, "%s", usage);
    exit(1);
  }

  double input = strtod(argv[2], NULL);
  double output = 0.0;

  if (type == 'c') {
    output = (input - 32) * 5 / 9;
  } else {
    output = (input * 9 / 5) + 32;
  }

  printf("%.2fº%c\n", output, toupper(type));
  return 0;
}
