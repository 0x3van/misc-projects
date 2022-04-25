// hangman
// author: 0xEvan
#include <stdio.h>
#include <string.h>


int main() {
    char *word = "hello";
    char guess[strlen(word)];
    int i;
    for (i = 0; i < strlen(word); i++) {
        guess[i] = '*';
    }
    printf("%s\n", guess);
    char c;
    while (1) {
        scanf("%c", &c);
        if (c == '\n') {
            printf("%s\n", guess);
        } else {
            for (i = 0; i < strlen(word); i++) {
                if (word[i] == c) {
                    guess[i] = c;
                }
            }
            printf("%s\n", guess);
        }
    }
    return 0;
}

