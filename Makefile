#CXX = c++
RM        += -r

ROOT      := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

CXXFLAGS  := $(shell pkg-config sfml-all --cflags)
LDLIBS    := $(shell pkg-config sfml-all --libs)

SRCDIR     = $(ROOT)/src/
#SRCFOLDERS = $(shell find src -type f -name '*.cpp')

CXXFLAGS  += -I $(SRCDIR)

SRCS      := $(shell find src -type f -name '*.cpp')
HDRS      := $(wildcard $(SRCDIR)/*.h)

OBJDIR     = $(ROOT)/obj/
OBJS       = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.cpp=.o))

#$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

BUILDDIR   = $(ROOT)/build/
MAIN       = main

run: $(MAIN)
	./$(BUILDDIR)/$(MAIN)

$(MAIN): $(OBJS) | $(BUILDDIR)
	$(CXX) -o $(BUILDDIR)/$(MAIN) $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJDIR):
	echo $(OBJS)
	mkdir $@

$(BUILDDIR):
	echo $(OBJS)
	mkdir $@

test:
	echo $(SRCS)
	echo $(OBJS)

.PHONY: clean
clean:
	$(RM) $(MAIN) $(OBJDIR) $(BUILDDIR)
