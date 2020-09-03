CC = g++
SRCDIR := .
SRCS   := $(shell find $(SRCDIR) -name "*.cpp")
OBJ_FILES = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
LIBS =
FLAGS = -std=c++17 -stdlib=libc++

INCLUDES = -Isrc
INCLUDES += -I../Burst/src


ifeq ($(mode),debug)
 FLAGS += -D _DEBUG -D _BURST_DEBUG -g
 EXEC = bin/debug/BurstTester.out
 OBJDIR := ./bin-int/debug
else
 mode = release
 EXEC = bin/release/BurstTester.out
 OBJDIR := ./bin-int/release
endif

all: $(EXEC)

clean :
	$(shell find bin-int -name "*.o" -delete)

$(EXEC) : $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LIBS) $(INCLUDES) $(FLAGS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(FLAGS) $(INCLUDES)  -o $@ -c $<

$(OBJDIR)/%.o: %.cc | $(OBJDIR)
	$(CC) $(FLAGS) $(INCLUDES)  -o $@ -c $<

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	mkdir -p $@