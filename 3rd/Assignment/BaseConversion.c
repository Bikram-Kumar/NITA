#include <stdio.h>
#include <string.h>

int base_to_decimal(char *str, int base);
char* dec_to_base(char str[], int base, int num);
int char_to_dec(char c);
char dec_to_char(int num);
void reverse_string(char *str);

int main()
{
	int in_base, out_base;
	char str[100], out_num[128];
	printf("Enter input base: ");
	scanf("%d", &in_base);
	printf("Enter output base: ");
	scanf("%d", &out_base);
	printf("Enter number: ");
	scanf("%s", str);
    int dec = base_to_decimal(str, in_base);
    if (dec == -1)  return 0;
    dec_to_base(out_num, out_base, dec);
	printf("Number in base %d: %s\n", out_base, out_num);
	
	return 0;
}



int base_to_decimal(char *str, int base)
{
	int len = strlen(str);
	int power = 1; 
	int num = 0; 

	for (int i = len - 1; i >= 0; i--) {
		
		if (char_to_dec(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
		}

		num += char_to_dec(str[i]) * power;
		power = power * base;
	}

	return num;
}

char* dec_to_base(char str[], int base, int num)
{
	int index = 0; 


	while (num > 0) {
		str[index++] = dec_to_char(num % base);
		num /= base;
	}
	str[index] = '\0';

	reverse_string(str);

	return str;
}

// returns decimal equivalent of char 
int char_to_dec(char c)
{
	if (c >= '0' && c <= '9') return (int)c - '0';
	
	return (int)c - 'A' + 10;
}



// converts decimal number to char
char dec_to_char(int num)
{
	if (num >= 0 && num <= 9) return (char)(num + '0');

	return (char)(num - 10 + 'A');
}


void reverse_string(char *str)
{
	int len = strlen(str);
    char temp;

	for (int i = 0; i < len/2; i++)
	{
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
}


