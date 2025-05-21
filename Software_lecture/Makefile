BINARIES= \
	demo-c \
	demo-cpp \
	demo-go \
	demo-pointer \

CFLAGS=		-O0 -g
CXXFLAGS=	-O0 -g

all: $(BINARIES)
run: $(BINARIES)
	./demo-c
	./demo-cpp
	./demo-go

demo-c: vm.c Makefile
	$(CC) $(CFLAGS) vm.c -o demo-c

demo-cpp: vm.cpp Makefile
	$(CXX) $(CXXFLAGS) vm.cpp -o demo-cpp

demo-go: vm.go Makefile
	go build -o demo-go vm.go

demo-pointer: pointer.cpp Makefile
	$(CXX) $(CXXFLAGS) pointer.cpp -o demo-pointer


clean:
	rm -f *.o $(BINARIES) a.out
