CC = gcc

SRCS = binaryTreeReverseTravel.c stack.c

C_HEADER = node.h

C_INC = $(patsubst %,-I%, $(C_HEADER))

TARGET = binaryTreeReverseTravel

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES: .c .o