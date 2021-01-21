CC = gcc

SRCS = main.c

TARGET = BlockStack

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir $(BUILDDIR))

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)
	rm -rf output.txt

.SUFFIXES: .c .o
