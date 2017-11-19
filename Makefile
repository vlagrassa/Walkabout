include config.mk

$(MAIN): $(OBJS) | $(BUILDDIR)
	$(LINK.cpp) $(OUTPUT_OPTION) $^ $(LOADLIBES) $(LDLIBS)

ifdef PRECOMPILED_HEADERS
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(GCHS) | $(OBJDIR) $(OBJSUBDIRS)
	@echo "Using precompiled headers"
else
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDRS) | $(OBJDIR) $(OBJSUBDIRS)
endif
	$(COMPILE.cpp) $(OUTPUT_OPTION) $< 

.SUFFIXES: .hpp.gch .hpp
.SECONDARY: $(GCHS)
.hpp.hpp.gch:
	$(COMPILE.cpp) $(OUTPUT_OPTION) -x c++-header $<

$(BUILDDIR) $(OBJDIR) $(OBJSUBDIRS):
	mkdir -p $@

.DEFAULT: run
.PHONY:   run
run: $(MAIN)
	./$<

.PHONY: clean
clean:
	$(RM) $(OBJDIR) $(BUILDDIR) $(GCHS)
