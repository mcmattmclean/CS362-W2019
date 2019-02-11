#ifndef _TESTHELPERS_H
#define _TESTHELPERS_H

// assertTrue macro source: https://piazza.com/class/jpu18p346423vs?cid=159
#define assertTrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

#endif