.PHONY: clean

CC=clang
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c23

PROGRAMS=tc timer ll
BIN=~/.local/bin

%: %.c
	$(CC) $(CFLAGS) -o $@ $^


install:
	mkdir -p $(BIN)
	for p in $(PROGRAMS); do \
		$(CC) $(FLAGS) -o $$p $$p.c || exit 1; \
		mv $$p $(BIN)/; \
	done

clean:
	for p in $(PROGRAMS); do \
  	rm -f $(BIN)/$$p; \
  done

