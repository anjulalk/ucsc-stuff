default: mymalloc

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c mymalloc.c

driver.o: driver.c mymalloc.h
	gcc -c driver.c

mymalloc: mymalloc.o driver.o
	gcc -o run driver.o mymalloc.o

clean: mymalloc.o driver.o run
	rm mymalloc.o driver.o run

