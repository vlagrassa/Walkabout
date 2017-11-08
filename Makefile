#CXX = c++
RM        += -r

ROOT      := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

CXXFLAGS  := $(shell pkg-config sfml-all --cflags)
LDLIBS    := $(shell pkg-config sfml-all --libs)

SRCDIRSHORT= src
SRCDIR     = $(ROOT)/$(SRCDIRSHORT)
#SRCFOLDERS = $(shell find src -type f -name '*.cpp')

CXXFLAGS  += -I $(SRCDIR)

#SRCS      := $(addprefix $(ROOT), $(shell find src -type f -name '*.cpp'))
SRCS      := $(shell find src -type f -name '*.cpp')
HDRS      := $(wildcard $(SRCDIR)/*.h)

OBJDIRSHORT= obj
OBJDIR     = $(ROOT)/$(OBJDIRSHORT)
OBJS       = $(subst $(SRCDIRSHORT),$(OBJDIRSHORT),$(SRCS:.cpp=.o))
#OBJS       = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))

#$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

BUILDDIR   = $(ROOT)/build/
MAIN       = main

run: $(MAIN)
	/$(BUILDDIR)/$(MAIN)

$(MAIN): $(OBJS) | $(BUILDDIR)
	$(CXX) -o $(BUILDDIR)/$(MAIN) $(OBJS) $(LDLIBS)

$(OBJDIRSHORT)/%.o: $(SRCDIRSHORT)/%.cpp | $(OBJDIR)
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJDIR):
	mkdir $@
	mkdir $@/region/

$(BUILDDIR):
	#@echo SRCDIR:
	#@echo $(SRCDIR)
	#@echo $(SRCDIRSHORT)
	#@echo SRCS:
	#@echo $(SRCS)
	#@echo OBJDIR:
	#@echo $(OBJDIR)
	#@echo $(OBJDIRSHORT)
	#@echo OBJS:
	#@echo $(OBJS)
	#@echo $(subst $(SRCDIRSHORT),$(OBJDIRSHORT),$(SRCS:.cpp=.o))
	mkdir $@

test:
	echo $(SRCS)
	echo $(OBJS)

.PHONY: clean
clean:
	$(RM) $(MAIN) $(OBJDIR) $(BUILDDIR)
