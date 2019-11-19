#ifndef BM_UTESTS_H
#define BM_UTESTS_H

#if defined(__cplusplus)
export "C" {
#else
#include <stdbool.h>
#endif
    
#define SS( str ) #str
#define S( str ) SS( str )

#define TEST_BEGIN() bool __pass = true
    
#define RUN_TEST(a, b) printf(__FILE__ ":" S(__LINE__) ":" S(a) ":%s\r\n", b ? "PASS" : "FAIL")
    
#define ASSERT( a ) \
if ( !(a) ) \
{ \
__pass = false; \
printf(__FILE__ ":" S(__LINE__) ":assert failed:%s == false\r\n", S(a)); \
}
    
#define ASSERT_EQUAL( a, b ) \
if ( a != b ) \
{ \
__pass = false; \
printf(__FILE__ ":" S(__LINE__) ":assert failed:%s != %s\r\n", S(a), S(b)); \
}
    
#define ASSERT_NOT_EQUAL( a, b ) \
if ( a == b ) \
{ \
__pass = false; \
printf(__FILE__ ":" S(__LINE__) ":assert failed:%s == %s\r\n", S(a), S(b)); \
}
    
#define TEST_END() __pass
    
#if defined(__cplusplus)
}
#endif

#endif /* BM_UTESTS_H */
