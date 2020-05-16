mis: message.o mis.o step_one.o step_two.o
	gcc -g -o mis message.o mis.o step_one.o step_two.o

message.o: message.c head.h
	gcc -c -g message.c

step_one.o: step_one.c head.h
	gcc -c -g step_one.c

step_two.o: step_two.c head.h
	gcc -c -g step_two.c

mis.o: mis.c step_one.o step_two.o message.o head.h 
	gcc -c -g mis.c

clean:
	del message.o mis.o step_one.o step_two.o