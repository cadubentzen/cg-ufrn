CC = gcc
CFLAGS = -lGL -lglut -lGLU -lm

EXAMPLES = hello.c  \
		   cube.c   \
		   double.c \
		   clip.c   \
		   smooth.c \
		   planet.c \
		   robot.c

OUTPUTS = $(basename $(EXAMPLES))

all: $(OUTPUTS)

%: %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	-rm -f $(OUTPUTS)
