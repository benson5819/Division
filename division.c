/*
 *  Perform a long division method, in binary way
 *  To do this, both the operands need to be positive
 *
 *  Example: 11('1011') / 2('10')
 *  <1> '10' << 2 => '1000';
 *      '1011' - '1000' => '11'; ==> New dividend
 *      result += 1 << 2; ==> result == 4;
 *  <2> '10' << 0 => '10';
 *      '11' - '10' => '1'; ==> New dividend
 *      result += 1 << 0; ==> result == 5;
 *  <3> '1' less than '10' => abort
 */

int divide(int dividend, int divisor) {
    long a = (long)dividend;
    long b = (long)divisor;
    long result = 0;

    // Get the sign bit and only set the sign variable when the two numbers: one neg / one pos
    bool sign = (dividend ^ divisor) & (1 << ((sizeof(int) << 3) - 1));

    // Handle 0 for exception
    if (a == 0)
    {
        return 0;
    }
    
    // Make sure both of the numbers are positive
    if (a < 0)   a = (0 - a);
    if (b < 0)    b = (0 - b);
    
    printf("%ld / %ld, with sign: %d\n", a, b, sign);
    
    while (a >= b)
    {
        long temp = b;
        int shift = 0;
        
        while (((temp << 1) > 0) && ((temp << 1) <= a))
        {
            temp = temp << 1;
            shift++;
            
            printf("temp: %x\n", temp);
        }
        
        result += ((long long)1 << shift);
        a -= temp;
        
        printf("temp result: %lx\n", result);
    }
    
    if (sign)
    {
        result = (0 - result);
    }
    
    // Handle overflow case
    if (result > 0x7fffffff)
    {
        result = 0x7fffffff;
    }

    printf("result: %ld\n", result);
    
    return (int)result;
}
