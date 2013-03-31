CC=clang -g -Wall
all:
	$(CC) -o parser-url-schema parser-url-schema.c
	$(CC) -o external-strstr external-strstr.c

