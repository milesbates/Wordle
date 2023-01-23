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

char* getWord(char* file) {
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