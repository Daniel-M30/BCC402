all:
	make run
	make test
	make clean

run:
	gcc semana4.c -o main
	./main < ./txt/input.txt > ./txt/output.txt

test:
	diff ./txt/expect.txt ./txt/output.txt

clean:
	rm -f ./main ./txt/output.txt