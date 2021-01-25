lib:
	g++ -c ./src/*.cpp -I./include 	
	mv *.o ./build/
test:
	g++ -c mytest.cpp -I./include
	mv *.o ./build/
	g++ -o test ./build/*.o
run:
	g++ -c mytest.cpp -I./include
	mv *.o ./build/
	g++ -o test ./build/*.o
	./test
	rm test
clean:
	rm ./build/*.o
