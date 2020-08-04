cc = g++
prom = bin/test1.bin
source = src/*.cpp
INC = -Isrc/include 

$(prom): $(source)
	$(cc) -o $(prom) $(INC) $(source)

clean:
	rm bin/*
