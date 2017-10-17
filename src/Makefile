CC = gcc
CFLAGS = -lGL -lglut -lGLU -lm

EXAMPLES = hello.c  \
		   cube.c   \
		   double.c \
		   clip.c   \
		   smooth.c \
		   planet.c \
		   robot.c \
           light.c

OUTPUTS = $(basename $(EXAMPLES))

.PHONY: all clean

all: $(addprefix bin/,$(basename $(EXAMPLES)))

bin/%: %.c bin
	$(CC) $< -o $@ $(CFLAGS)

clean:
	-rm -rf bin

bin:
	-@mkdir bin
	
