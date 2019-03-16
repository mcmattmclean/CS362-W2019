CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

testHelpers.o: testHelpers.h testHelpers.c dominion.o
	gcc -c testHelpers.c -g $(CFLAGS)

randomtestcard1: testHelpers.o randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o testHelpers.o $(CFLAGS)

randomtestcard2: testHelpers.o randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o testHelpers.o $(CFLAGS)

randomtestadventurer: testHelpers.o randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o testHelpers.o $(CFLAGS)

randomtestresults: randomtestcard1 randomtestcard2 randomtestadventurer
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	rm *.gcov *.gcda

	./randomtestcard1 >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	rm *.gcov *.gcda

	./randomtestcard2 >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	rm *.gcov *.gcda

runtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer
	./unittest1 >> testresults.out
	./unittest2 >> testresults.out
	./unittest3 >> testresults.out
	./unittest4 >> testresults.out
	./cardtest1 >> testresults.out
	./cardtest2 >> testresults.out
	./cardtest3 >> testresults.out
	./cardtest4 >> testresults.out
	./randomtestadventurer >> testresults.out
	./randomtestcard1 >> testresults.out
	./randomtestcard2 >> testresults.out
	gcov -b -f dominion.c >> testresults.out
	cat dominion.c.gcov >> testresults.out

unittest1: testHelpers.h unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: testHelpers.h unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: testHelpers.h unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: testHelpers.h unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: testHelpers.h cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: testHelpers.h cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: testHelpers.h cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: testHelpers.h cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestcard1 randomtestcard2 cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4
