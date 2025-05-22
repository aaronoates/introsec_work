CFLAGS=		-g
COV=		llvm-cov
COVFLAGS=	-show-line-counts-or-regions
DUMPFLAGS=	-d

BINARIES=	matrix matrix-cov matrix-fuzz
DUMPS=		$(BINARIES:=.dump)

.PHONY:		show_coverage

all: $(BINARIES) $(DUMPS)

clean:
	rm -rf *.core *.dump *.o *.prof* findings $(BINARIES) 

#
# A pretty typical C program
#
matrix: matrix.c
	$(CC) $(CFLAGS) matrix.c -o matrix

matrix.dump: matrix
	objdump $(DUMPFLAGS) matrix > matrix.dump

#
# The same program, but this time built with coverage tooling
#
matrix-cov: matrix.c
	$(CC) $(CFLAGS) -fprofile-instr-generate -fcoverage-mapping matrix.c -o matrix-cov

matrix-cov.dump: matrix-cov
	objdump $(DUMPFLAGS) matrix-cov > matrix-cov.dump

#
# The same program again, but this time built with AFL support
# 	
matrix-fuzz: matrix.c
	afl-cc $(CFLAGS) matrix.c -o matrix-fuzz

matrix-fuzz.dump: matrix-fuzz
	objdump $(DUMPFLAGS) matrix-fuzz > matrix-fuzz.dump

#
# Support for printing nice coverage data:
#

# Show coverage results, based on aggregated profiling data
show_coverage: cov.profdata matrix-cov
	$(COV) show ./matrix-cov -instr-profile=cov.profdata $(COVFLAGS)

# Build aggregated profile data from a set of test cases (in this example, just one test)
cov.profdata: 4x4.prof
	llvm-profdata merge -sparse 4x4.prof -o cov.profdata

# Generate profile data for a single test case
4x4.prof: matrix-cov
	LLVM_PROFILE_FILE="4x4.prof" ./matrix-cov tests/4x4
