
build:
	gcc -g -I ../htslib/htslib htslib_read_tell.c ../htslib/libhts.a -lz -o htslib_read_tell
	gcc -g -I ../htslib/htslib htslib_itr_tell.c  ../htslib/libhts.a -lz -o htslib_itr_tell

clean:
	-rm -rf *~ htslib_itr_tell htslib_read_tell *.dSYM
