# Makefile for GNU Make.
# $Id: GNUmakefile 21 2005-01-23 00:03:02Z hex $

include ../../../Makedefs.faerion.include

PROG    = test-03
DEFS   += RASCAL_HELPERS
LIBS   += rascal faeutil stdc++
SRCS    = $(wildcard *.cc)
LIBDIR += ../../$(MDF_LIBARCH)

ifeq ($(MDF_OSNAME),NT)
  SRCS += $(wildcard *.rc)
  PROG := $(PROG).exe
  LIBS += pthreadGCE
else
  LIBS += pthread
endif

include ../../../Makedefs.faerion

run: all
	@echo " "
	@rm -f resolver-packet-?????.?
	@PATH=$(LIBDIR):$(PATH) ./$(PROG) $(ARGS)

debug: all
	@echo " "
	@rm -f resolver-packet-?????.?
	@PATH=$(LIBDIR):$(PATH) gdb $(PROG)
