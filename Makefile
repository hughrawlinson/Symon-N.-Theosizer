CC = g++
CFLAGS = -lfltk -lrtaudio -lrtmidi

all: maximilian.o synth.o
	$(CC) $(CFLAGS) main.cpp -o "Symon N. Theosizer"

maximilian.o:
	$(CC) -c maximilian.cpp

synth.o:
	$(CC) -c synth.cpp

clean:
	rm *.o
	rm Symon\ N.\ Theosizer