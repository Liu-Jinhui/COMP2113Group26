#makefile

FLAGS = -pedantic-errors -std=c++11

calculate.o: calculate.cpp calculate.h
	g++ $(FLAGS) -c $<

menu.o: menu.cpp menu.h
	g++ $(FLAGS) -c $<

move.o: move.cpp move.h
	g++ $(FLAGS) -c $<

print.o: print.cpp print.h calculate.h
	g++ $(FLAGS) -c $<

status.o: status.cpp status.h
	g++ $(FLAGS) -c $<

main.o: main.cpp calculate.h menu.h move.h print.h status.h
	g++ $(FLAGS) -c $<

main: main.o calculate.o menu.o move.o print.o status.o 
	g++ $(FLAGS) $^ -o $@