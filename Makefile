
build:
	gcc -g -I ../htslib/htslib htslib_tell.c ../htslib/libhts.a -lz -o htslib_tell

clean:
	-rm -rf *~ htslib_tell htslib_tell.dSYM
