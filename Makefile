CURRENTDIR :=$(shell pwd)
LIBDIR :=$(addsuffix /lib,$(CURRENTDIR))
INCLUDES := -I$(LIBDIR)

CFLAGS := -Wall -g 

BINDIR :=$(CURRENTDIR)/bin

export INCLUDES CFLAGS BINDIR

EXCLUDEDIRS :=$(CURRENTDIR)/bin $(CURRENTDIR)/lib $(CURRENTDIR)

SUBDIRS := $(shell find $(CURRENTDIR) -maxdepth 10 -type d)

MAKEDIRS :=$(filter-out $(EXCLUDEDIRS),$(SUBDIRS))


default:
	@for d in $(MAKEDIRS); do (cd $$d && $(MAKE)); done
	
install:
	@for d in $(MAKEDIRS); do (cd $$d && $(MAKE) install); done

clean:
	@for d in $(MAKEDIRS); do (cd $$d && $(MAKE) clean); done

p:
	@echo $(MAKEDIRS)
cleanbin:
	-$(RM) -r $(BINDIR)/* 
	

.PHONY: default install clean