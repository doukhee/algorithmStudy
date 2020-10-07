CC = gcc

SRCS = RR_Traverse.c Queue.c

C_HEADER = node.h

C_INC = $(patsubst %,-I%, $(C_HEADER))

TARGET = RR_Traverse

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir $(BUILDDIR))

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)


.SUFFIXES: .c .o