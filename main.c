#include <stdio.h>
void start_game();
char* get_word(char* file);
void display();
int check_word(char* guess, char* word)
#define num_letters 5
#define num_attempts num_letters+1
char past_attempts[num_tries][num_letters];

int main() {
    start_game();
}

void display() {
    printf()
}

void start_game() {
  printf("How long would you like the word to be?")
char[6][20] files = ["","","","","four_letter_words.txt","five_letter_words.txt","","seven_letter_words.txt"]
  int b;
  scanf("Enter an integer:%d",&b)
  char initial_word[num_letters] = get_word("/home/runner/WordleCppProject-ESD22F-PostAPCS-D-1/words/%s", files[]);
  for (int i = 0; i <= num_tries; i++) {
    display();
    char guess_word[num_letters];
    scanf("%*c", &guess_word);
    for (int k = 0; k < num_letters; k++) {
      past_attempts[i][k] = guess_word[k];
    }
    
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
            return line;
            break;
        }
    }
    fclose(file);
    return 0;
}

int* check_word(char* guess, char* word) {
  int* colors[num_letters];
  for(i = 0; i < num_letters; ++i){
    for (j = 0; j < num_letters; ++j){
      if (guess[j] == word[i] && j == i)
        colors[i] = 1
      else if(guess[j] == word[i] && j != i)
        colors[i] = 2
      else
        colors[i] = 3
    }   
  return colors;
}


// Fetch the initial word from a dictionary/json/database/something else.
// Display the game in command line over time
/* handle 5 letter words as input, see which letters are 
 the same as the origin (green), present in other parts of the word (yellow) */
// check if each letter is in the right word and in the right position
// if right but not in the right position, color letter yellow
// if right and in right positition, color letter green
// make two arrays and check second array for each letter in the first array 
// have six chances to guess the word before game ends 

