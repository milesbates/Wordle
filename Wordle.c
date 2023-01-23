#include <stdio.h>

int main() {
    printf("hello");
}

void display() {
    
}

int start_game() {
    int num_letters;
    printf("How many letters would you like to play with?");
    scanf("%d", &num_letters);
}

// Fetch the initial word from a dictionary/json/database/something else.
// Display the game in command line over time
/* handle 5 letter words as input, see which letters are 
 the same as the origin (green), present in other parts of the word (yellow) */
// check if each letter is in the right word and in the right position
// if right but not in the right position, color letter yellow
// if right and in right positition, color letter green