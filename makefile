all: radix_notation draw_points simple_calculator simple_int_set
radix_notation: radix_notation.o
	g++ -o radix_notation radix_notation.o
radix_notation.o: radix_notation.cc
	g++ -c radix_notation.cc

draw_points: draw_points.o
	g++ -o draw_points draw_points.o
draw_points.o: draw_points.cc
	g++ -c draw_points.cc

simple_calculator: simple_calculator.o
	g++ -o simple_calculator simple_calculator.o
simple_calculator.o: simple_calculator.cc
	g++ -c simple_calculator.cc

simple_int_set: simple_int_set.o
	g++ -o simple_int_set simple_int_set.o
simple_int_set.o: simple_int_set.cc
	g++ -c simple_int_set.cc

clean:
	rm radix_notation.o draw_points.o simple_calculator.o simple_int_set.o

