CC = gcc

SRCS = LL_Traverse.c queue.c

C_HEADER = node.h

C_INC = $(patsubst %,-I%, $(C_HEADER))

TARGET = LL_Traverse

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
