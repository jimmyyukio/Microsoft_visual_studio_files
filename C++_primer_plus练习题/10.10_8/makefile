main.exe: func1.o func2.o
	g++ -o main.exe -g func1.o func2.o

func1.o: func1.cpp head.h
	g++ -c func1.cpp

func2.o: func2.cpp head.h
	g++ -c func2.cpp

clean:
	del func1.o func2.o main.exe