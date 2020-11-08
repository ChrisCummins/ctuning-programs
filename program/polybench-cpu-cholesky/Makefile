# Actions

CC ?= gcc
LD ?= $(CC)
TARGET ?= a.out
TARGET ?= o
CLEAN ?= rm -f *.out *.exe *.obj *.lib *.o *.a *.s *.i *.I
LD_FLAGS ?= -lm


all:		
	$(CM_PREFIX) $(CC) $(CFLAGS) -c *.c 
	$(LD) *.$(OBJ_EXT) $(LD_FLAGS) -o $(TARGET)
clean:
	$(CLEAN)
