/** SDBM hash algorithm */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * SDBM algorithm implementation
 * @param s NULL terminated string to hash
 * @return 64-bit hash result
 */
uint64_t sdbm(const char* s)
{
    uint64_t hash = 0;
    size_t i = 0;
    while (s[i] != '\0')
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
        i++;
    }
    return hash;
}

/**
 * Test function for ::sdbm
 * \returns None
 */
void test_sdbm()
{
    assert(sdbm("Hello World") == 12881824461405877380);
    assert(sdbm("Hello World!") == 7903571203300273309);
    assert(sdbm("Hello world") == 15154913742888948900);
    assert(sdbm("Hello world!") == 15254999417003201661);
    printf("Tests passed\n");
}


/** Main function */
int main()
{
    test_sdbm();
    return 0;
}
