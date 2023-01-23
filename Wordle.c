#include <stdio.h>
int start_game();
char* get_word(char* file);
void display();
#define num_letters 5

int main() {
    start_game();
}

void display() {
    
}

int start_game() {
    int num_tries = num_letters+1;
    char initial_word[num_letters] = get_word("five_letter_words.txt");
    for (int i = 0; i <= num_tries; i++) {
        display();
        char guess_word[num_letters];
        scanf("%c", &guess_word);
    }
    return 0;
}

char* get_word(char* file) {
    //Later generalize function so it allows input from any text file.
    int word = rand()%5758;
    char line[255];
    int line_num = 5;
    int current_line = 0;
    FILE *file = fopen("five_letter_words.txt","r");
    while (fgets(line, sizeof(line), file) != NULL) {
        current_line++;
        if (current_line == word) {
            printf("Line %d: %s", line_num, line);
            break;
        }
    }
    fclose(file);
    return 0;
}

// Fetch the initial word from a dictionary/json/database/something else.
// Display the game in command line over time
/* handle 5 letter words as input, see which letters are 
 the same as the origin (green), present in other parts of the word (yellow) */
// check if each letter is in the right word and in the right position
// if right but not in the right position, color letter yellow
// if right and in right positition, color letter green
