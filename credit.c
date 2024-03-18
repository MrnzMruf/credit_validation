#include <cs50.h>
#include <stdio.h>
#include <string.h>

// American Express uses 15-digit numbers, start with 34 or 37; -->if (digit_count == 15 &&
// (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37)) MasterCard uses
// 16-digit numbers, start with 51, 52, 53, 54, or 55 -->if (digit_count == 16 && (card_number /
// 100000000000000 == 51 || card_number / 100000000000000 == 52 || card_number / 100000000000000 ==
// 53 || card_number / 100000000000000 == 54 || card_number / 100000000000000 == 55)) Visa uses 13-
// and 16-digit numbers, start with 4. --> if ((digit_count == 13 || digit_count == 16) &&
// (card_number / 1000000000000 == 4))

// check checksum by Luhn algorithms: --> (sum % 10 == 0)   must be True

int main(void)
{
    string card_num;
    int digit_count = 0;
    int sum = 0;
    card_num = get_string("Number: ");

    // calculate the checksum by Luhn algorithms
    for (int i = strlen(card_num) - 1; i >= 0; i--)
    {
        int digit = card_num[i] - '0';
        if (digit < 0 || digit > 9)
        {
            printf("INVALID\n");
            return 0;
        }
        if (digit_count % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int doubled_digit = digit * 2;
            sum += (doubled_digit % 10) + (doubled_digit / 10);
        }
        digit_count++;
    }

    // check checksum valid then check another info about cards
    if (sum % 10 == 0)
    {
        if ((digit_count == 13 || digit_count == 16) && (card_num[0] == '4'))
        {
            printf("VISA\n");
        }
        else if (digit_count == 15 &&
                 (card_num[0] == '3' && (card_num[1] == '4' || card_num[1] == '7')))
        {
            printf("AMEX\n");
        }
        else if (digit_count == 16 &&
                 (card_num[0] == '5' && (card_num[1] >= '1' && card_num[1] <= '5')))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
