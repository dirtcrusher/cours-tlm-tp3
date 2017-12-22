CC=gcc
INCLUDE=-I. -I../../
CFLAGS=$(INCLUDE) -c

main.o: ../main.c hal.h ../../native-wrapper/native_wrapper.cpp ../../native-wrapper/native_wrapper.h
	$(CC) $(CFLAGS) ../main.c -o $@

.PHONY: clean realclean
clean:
	$(RM) main.o

realclean: clean
	-$(RM) *~
