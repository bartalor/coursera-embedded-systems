stats: stats.o
	gcc -Werror stats.o -o stats

stats.o: stats.c
	gcc -Werror -c stats.c -o stats.o

.PHONY: clean

clean:
	rm -f stats.o stats