
all: histpackloop

histpackloop: histpackloop.c
	$(CC) -o histpackloop histpackloop.c

histpack: histpack.c histpackfn.c
	$(CC) -o histpack histpackfn.c histpack.c

histpackfn.c: genhistpackfnc.pl
	./genhistpackfnc.pl >histpackfn.c
