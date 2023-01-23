#include <stdio.h>
int start_game();
char* get_words();
void display();
#define num_letters 5

int main() {
    start_game();
}

void display() {
    
}

int start_game() {
    int num_tries = num_letters+1;
    char initial_word[num_letters] = get_words();
    for (int i = 0; i <= num_tries; i++) {
        display();
        char guess_word[num_letters];
        scanf("%c", &guess_word);
    }
    return 0;
}

// Fetch the initial word from a dictionary/json/database/something else.
// Display the game in command line over time
/* handle 5 letter words as input, see which letters are 
 the same as the origin (green), present in other parts of the word (yellow) */
