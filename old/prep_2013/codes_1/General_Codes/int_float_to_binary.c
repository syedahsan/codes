/* Floating point decimal number to binary */

/* NOTE: Don't use global arrays to return the answers
 * other function calling the same function may overwrite
 * the array/buffer.
 * Do alloc/free instead
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char fbin[33], ibin[33], uibin[33];
char frbin[101]; /* limit of 100; ie we'll only calculate binary for fractions 
                    to 100 bits; we'll assume rest to be 0
                  */

char *unsigned_int_to_binary(unsigned int num);

char *fraction_to_binary(double num)
{
        memset(frbin, '0', sizeof(frbin)); /* set to 0 */
        frbin[101] = '\0';
        int i;
        double frac, inte;

        for (i = 0; i < 100 && num; i++) {
                num = modf(num * 2, &inte);
                frbin[i] = (int)inte + '0';
        }

        return (frbin);
}

/*
 * 1 bit - sign
 * 8 bits - exponent (bias - 127)
 * 23 bits - mantissa
 */
char *float_to_binary(float num)
{
        memset(fbin, '0', sizeof(fbin)); /* set to 0 */
        fbin[32] = '\0';
        int i, j;
        double fracpart, intpart;
        int exp = 127;

        /* sign of the number - MSB */
        fbin[0] = (num < 0) ? '1' : '0';

        num = fabs(num);
        /* convert the number into binary floating point */
        fracpart = modf((double)num, &intpart);
        char *intbin = unsigned_int_to_binary((unsigned int)intpart);
        char *fracbin = fraction_to_binary(fracpart);

        // Normalize the mantissa
        // find the most significant set bit in binary
        // representation of integral part
        // then look into the fractional part
        char mantissa[133] = {'\0'};
        strncpy(mantissa, intbin, 32);
        strncat(mantissa, fracbin, 100);

        for (i = 0; i < 132; i++)
                if (mantissa[i] == '1')
                        break;

        exp += (31 - i);
        for (j = 0, ++i; j < 23 && i < 132; j++, i++)
                fbin[j+9] = mantissa[i];
        
        char *expbin = unsigned_int_to_binary(exp);
        for (j = 7, i = 31; j >= 0 && i >= 0; j--, i-- )
                fbin[j+1] = expbin[i];

        return (fbin);


}

char *simple_int_to_binary(int num)
{
        memset(ibin, '0', sizeof(ibin)); /* set to 0 */
        ibin[32] = '\0';
        int i = 31;

        while (i) {
                ibin[i--] = ((num & 1) + '0');
                num = num >> 1;
        }

        return (ibin);
}

/* 2's compliment method */
char *int_to_binary(int num)
{
        memset(ibin, '0', sizeof(ibin)); /* set to 0 */
        ibin[32] = '\0';
        int i = 31;
        int neg = 0;

        if (num < 0)
                neg = 1;

        while (num) {
                ibin[i--] = (char)(num % 2 + '0');
                num /= 2;
        }

        if (neg) {
                /* flip bits */
                for (i = 31; i >= 0; i--) {
                        ibin[i] = (ibin[i] - '0') ? '0' : '1';
                }

                /* add 1 */
                int carry = 1;
                for (i = 31; i >= 0; i--) {
                        int bit = 0;
                        bit = ((ibin[i] - '0') ^ carry);
                        carry = ((ibin[i] - '0') & carry);
                        ibin[i] = bit + '0';
                }

                if (carry)
                        /* overflow */
                        fprintf(stderr, "overflow");
        }

        return (ibin);
}

char *unsigned_int_to_binary(unsigned int num)
{
        memset(uibin, '0', sizeof(uibin)); /* set to 0 */
        uibin[32] = '\0';
        int i = 31;

        while (num) {
                uibin[i--] = (char)(num % 2 + '0');
                num /= 2;
        }

        return (uibin);
}

int main()
{
        float f_num;
        int i_num;
        unsigned int ui_num;
        int i, N;

        scanf("%d", &N);

        while (N--) {
                scanf("%f", &f_num);
                i_num = (int)f_num;
                ui_num = (unsigned int)abs(i_num);
                printf("float: %f | int: %d | unsigned int: %d\n\n", f_num, i_num, ui_num);

                printf("float->binary: %s\n", float_to_binary(f_num));
                printf("integer->binary: %s\n", int_to_binary(i_num));
                printf("(simple)integer->binary: %s\n", simple_int_to_binary(i_num));
                printf("unsigned integer->binary: %s\n", unsigned_int_to_binary(ui_num));
        }

        return 0;
}
