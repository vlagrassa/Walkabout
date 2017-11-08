#CXX = c++
RM        += -r

ROOT      := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

CXXFLAGS  := $(shell pkg-config sfml-all --cflags)
LDLIBS    := $(shell pkg-config sfml-all --libs)

SRCDIR     = src
#SRCFOLDERS = $(shell find src -type f -name '*.cpp')

CXXFLAGS  += -I $(SRCDIR)

SRCS      := $(shell find src -type f -name '*.cpp')
HDRS      := $(wildcard $(SRCDIR)/*.h)

OBJDIR     = obj
OBJS       = $(subst $(SRCDIRSHORT),$(OBJDIRSHORT),$(SRCS:.cpp=.o))

BUILDDIR   = $(ROOT)/build/
MAIN       = main

run: $(MAIN)
	/$(BUILDDIR)/$(MAIN)

$(MAIN): $(OBJS) | $(BUILDDIR)
	$(CXX) -o $(BUILDDIR)/$(MAIN) $(OBJS) $(LDLIBS)

$(OBJDIRSHORT)/%.o: $(SRCDIRSHORT)/%.cpp | $(OBJDIR)
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(OBJDIR):
	mkdir $@
	mkdir $@/region/

$(BUILDDIR):
	mkdir $@

test:
	echo $(SRCS)
	echo $(OBJS)

.PHONY: clean
clean:
	$(RM) $(MAIN) $(OBJDIR) $(BUILDDIR)
