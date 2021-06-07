terminal-tac-toe : 
	g++ src/main.cpp -o terminal-tac-toe 	
clean : terminal-tac-toe
	rm terminal-tac-toe
install: terminal-tac-toe
	sudo mv terminal-tac-toe /usr/bin/
