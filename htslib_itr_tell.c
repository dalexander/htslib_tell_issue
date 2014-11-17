//
// Can we get the offset of the first alignment within a range?
// The answer seems to be "no".  The offset
//


#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "bgzf.h"
#include "sam.h"

int main(int argc, char *argv[])
{
    samFile* sf;
    bam1_t* b;
    int64_t offset;

    char indexFname[1024];
    hts_idx_t* idx;
    hts_itr_t* iter;

    if ((sf = sam_open(argv[1], "r")) == 0) {
        return 1;
    }
    bam_hdr_t *h = bam_hdr_read(sf->fp.bgzf);
    b = (bam1_t*)calloc(1, sizeof(bam1_t));

    // load the index
    sprintf(indexFname, "%s.bai", argv[1]);
    idx = bam_index_load(indexFname);

    // build an iterator
    iter = sam_itr_queryi(idx, 0, 5000, 6000);

    // enumerate....
    offset = bgzf_tell(sf->fp.bgzf);
    while (bam_itr_next(sf, iter, b) >= 0)
    {
        int32_t pos = b->core.pos;
        printf("0x%-16llx %d\n", offset, pos);
        offset = bgzf_tell(sf->fp.bgzf);
    }

    return 0;
}
