CC	= gcc
OBJS	= main.o Xvfb.o
PROGRAM	= draw

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)

clean:
	rm $(OBJS) $(PROGRAM)

run:	$(PROGRAM)
	Xvfb :1 -screen 0 1024x768x24 -fbdir . &
	export DISPLAY=:1
	./$(PROGRAM)
	x11vnc -display :1

vnc:
	vncviewer localhost::5900

kill:
	kill $(shell ps -a | grep Xvfb | cut -d' ' -f 2)
