CURRENTDIR := $(shell pwd)

TARGET:=$(addsuffix .out,$(notdir $(CURRENTDIR)))

OBJDIRS :=$(shell find $(CURRENTDIR) -maxdepth 10 -type d)

SRC := $(foreach dir,$(OBJDIRS),$(wildcard $(dir)/*.c))

OBJS :=$(patsubst %.c,%.o,$(SRC))

all:$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)
	
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


install:
	cp $(TARGET) $(BINDIR)/

clean:
	-$(RM) -r $(OBJS) 
	-$(RM) -r $(TARGET) 


p:
	@echo SRC is:$(SRC)
	@echo OBJS is:$(OBJS)
.PHONY:all install clean

