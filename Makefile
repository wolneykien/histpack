
all: histpack

histpack: histpack.c
	$(CC) -o histpack histpack.c

histpacknoloop: histpacknoloop.c histpackfn.c
	$(CC) -o histpacknoloop histpackfn.c histpacknoloop.c

histpackfn.c: genhistpackfnc.pl
	./genhistpackfnc.pl >histpackfn.c


clean:
	rm -fv histpack histpacknoloop histpackfn.c
