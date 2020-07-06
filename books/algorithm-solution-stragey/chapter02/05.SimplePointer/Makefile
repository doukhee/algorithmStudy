CC = gcc

SRCS = simplePointer.c

TARGET = SimplePointer

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean cratedirs build

cratedirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) -o $@ -c $<

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

clean:
	rm -rf $(BUILDDIR)


.SUFFIXES: .c .o