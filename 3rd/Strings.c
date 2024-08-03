#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif




int len_str(char* str);
void reverse_str(char* str);
int get_num_vowels(char* str);
int get_num_consonants(char* str);
int get_num_sentences(char* str);
void get_num_words_dup(char* str, int* num_words, int* num_dup);
bool arr_contains_str(char** arr, int len, char* str);
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

    int len = strlen(sentences);

    // remove last line feed if there
    if ((n > 0) && (sentences[len-1] == '\n')) sentences[len-1] = '\0';

    printf("Entered sentences: %s\n", sentences);
    printf("Number of vowels: %d\n", get_num_vowels(sentences));
    printf("Number of consonants: %d\n", get_num_consonants(sentences));
    printf("Number of sentences: %d\n", get_num_sentences(sentences));

    int num_words, num_dup;
    get_num_words_dup(sentences, &num_words, &num_dup);

    printf("Number of unique words: %d\n", num_words - num_dup);
    printf("Number of duplicate words: %d\n", num_dup);
    
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
    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int get_num_consonants(char *str)
{
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (strchr(consonants, str[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int get_num_sentences(char *str)
{
    char stops[] = ".?!";
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(stops, str[i]) != NULL) {
            count++;
        }
    }

    if ((count == 0) && (len > 0) && (str[0] != '\n')) return 1;
    
    return count;
}

void get_num_words_dup(char* str, int* num_words, int* num_dup)
{
    int length = strlen(str);
    char* words[length];
    
    *num_words = 0;
    words[*num_words] = strtok(str, " ,.?!");

    while (words[*num_words] != NULL) {
        puts(words[*num_words]);
        (*num_words)++;
        words[*num_words] = strtok(NULL, " ,.?!");
    }

    *num_dup = 0;

    for (int i = 0; i < *num_words; i++) {
        if (arr_contains_str(words, i, words[i])) {
            (*num_dup)++;
        }
    }

}


bool arr_contains_str(char **arr, int len, char *str)
{
    for (int i = 0; i < len; i++) {
        if (strcmp(str, arr[i]) == 0) return true;
    }
    return false;
}
