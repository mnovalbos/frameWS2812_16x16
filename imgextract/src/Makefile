OBJS1=imgextract.o
OBJS2=showimage.o
LDFLAGS= -lSDL2 -lSDL2_image
EXE1=imgextract
EXE2=showimage

CFLAGS=
GCC=g++

all: $(EXE1)
	
$(EXE1): $(OBJS1)
	$(GCC)  $< $(CFLAGS) $(LDFLAGS) -o $@

$(EXE2): $(OBJS2)
	$(GCC)  $< $(CFLAGS) $(LDFLAGS) -o $@


%.o: %.c
	$(GCC) -c $(CFLAGS) $< -o $@
	
