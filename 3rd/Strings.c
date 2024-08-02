#include <stdio.h>
#include <string.h>

int len_str(char* str);
void reverse_str(char* str);
int get_num_vowels(char* str);
int get_num_consonants(char* str);
int get_num_sentences(char* str);
int get_num_unique_words(char* str);
int get_num_repeating_words(char* str);
void p1(), p2();

int main () {

    // p1();
    p2();

    return 0;

}

// Find length of string, then reverse it
void p1() {
    char str[512];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_str(str);
    printf("Length: %d\nReversed: %s\n", len_str(str), str);
}


// Input sentences of length n. Count the number of vowels and consonants, number of sentences,
// number of unique words, number of repeating words
void p2() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    char sentences[n+1];
    printf("Enter sentences (%d):\n", n);
    fflush(stdin);
    fgets(sentences, n+1, stdin);
    printf("%s\n", sentences);
    printf("Number of vowels: %d\n", get_num_vowels(sentences));
    printf("Number of consonants: %d\n", get_num_consonants(sentences));
    printf("Number of sentences: %d\n", get_num_sentences(sentences));
    
}



int len_str(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void reverse_str(char *str) {
    int length = len_str(str);
    char tmp;

    for (int i = 0; i < length/2; i++) {
        tmp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = tmp;
    }
}

int get_num_vowels(char *str)
{
    char vowels[] = "aeiouAEIOU";
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (strchr(vowels, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int get_num_consonants(char *str)
{
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (strchr(consonants, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int get_num_sentences(char *str)
{
    char stops[] = ".?!";
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (strchr(stops, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int get_num_unique_words(char *str)
{
    int length = strlen(str);
    char words[length][length];
    


    return 0;
}

int get_num_repeating_words(char *str)
{
    return 0;
}
