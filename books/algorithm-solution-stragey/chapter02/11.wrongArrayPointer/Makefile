CC = gcc

SRCS = wrongArrayPointer.c

TARGET = wrongArrayPointer

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS):$(BUILDDIR)/%.o : %.c
	-$(CC) -o $@ -c $<

build: $(COBJS)
	-$(CC) -o $(BUILDDIR)/$(TARGET) $^

clean:
	rm -rf $(BUILDDIR)

SUFFIXES: .c .o


