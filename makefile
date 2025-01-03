obj:=$(patsubst %.c, %.o, $(wildcard *.c))
main.exe:$(obj)
	gcc -o $@ $^
clean:
	rm *.o *.exe