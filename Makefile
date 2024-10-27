CC	= gcc
CFLAGS	= -g
RM	= rm -f


defualt: all

all: tips-fedora

tips-fedora: tips-fedora.c
	$(CC) $(CFLAGS) tips-fedora.c -o tips-fedora

clean veryclean:
	$(RM) tips-fedora
