#CXX = c++

ROOT:=$(dir $(realpath $(lastword $(MAKEFILE_LIST))))
	
RM+=-r

CXXFLAGS:=$(shell pkg-config sfml-all --cflags)
LDLIBS:=$(shell pkg-config sfml-all --libs)

#SRCS:=$(addprefix $(ROOT),$(wildcard src/*))
SRCDIR = $(ROOT)/src/
SRCS:=$(wildcard $(SRCDIR)/*.cpp)
HDRS:=$(wildcard $(SRCDIR)/*.h)

OBJDIR = $(ROOT)/obj/
OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.cpp=.o)))

BUILDDIR = build/

MAIN = main

run: $(MAIN)
	./$(BUILDDIR)/$(MAIN)

$(MAIN): $(OBJS)
	$(CXX) -o $(BUILDDIR)/$(MAIN) $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJDIR):
	mkdir $@

test:
	echo $(SRCS)
	echo $(OBJS)

.PHONY: clean
clean:
	$(RM) $(MAIN) $(OBJDIR)
