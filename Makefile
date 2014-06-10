all:
	g++ -c maximilian.cpp
	g++ -c synth.cpp
	g++ -lfltk -lrtaudio main.cpp -o "Symon N. Theosizer" -v

clean:
	rm *.o