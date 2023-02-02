#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define K_NUM_LETTERS 4
#define num_tries K_NUM_LETTERS + 1
#define YELLOW "\e[0;33m"
#define GREEN "\e[0;32m"
#define REG "\e[0;37m"
#define BLACK "\e[0;30m"

void start_game();
void get_word(char *file, char *out);
void display();
void check_word(int *colors, char *guess, char *word);
void game_end(int num_attempts, char* word);
void get_color(char *color, int num);

char past_attempts[num_tries][K_NUM_LETTERS];
int past_colors[num_tries][K_NUM_LETTERS];
int alphabet_colors[26];
char files[3][30] = {"words/four_letter_words.txt",
                    "words/five_letter_words.txt",
                    "words/six_letter_words.txt"};

int main() { start_game(); }

void display() {
  system("clear");
  for (int i = 0; i < num_tries; i++) {
    for (int k = 0; k < K_NUM_LETTERS; k++) {
      char color[8];
      get_color(color, past_colors[i][k]);
      if (past_attempts[i][k] == '\0') {
        printf("_");
      }
      printf("%s%c", color, past_attempts[i][k]);
    }
    printf("\n%s", REG);
  }
  for (int i = 0; i < 26; i++) {
    char color[8];
    get_color(color, alphabet_colors[i]);
    printf("%s%c ", color, i+97);
    // printf("%d ", alphabet_colors[i]);
  }
  printf("\n%s", REG);
}
void get_color(char *color, int num) {
  switch (num) {
    case 0:
      strcpy(color, REG);
      break;
    case 1:
      strcpy(color, YELLOW);
      break;
    case 2:
      strcpy(color, GREEN);
      break;
    case 3:
      strcpy(color, BLACK);
      break;
  }
}

void start_game() {
  system("clear");
  memset(past_attempts, 0, sizeof(past_attempts[0][0]) * K_NUM_LETTERS * num_tries);
  memset(past_colors, 0, sizeof(past_colors[0][0]) * K_NUM_LETTERS * num_tries);
  memset(alphabet_colors, 0, sizeof(alphabet_colors[0]) * 26);
  // printf("How long would you like the word to be?\n");
  // int index;
  // scanf("%d", &index);
  char filename[] = "/home/runner/WordleCppProject-ESD22F-PostAPCS-D-1/words/";
  // printf("filename: %s", files[index-4]);
  // strcat(filename, files[index-4]);
  char initial_word[K_NUM_LETTERS + 1];
  get_word(files[K_NUM_LETTERS-4], initial_word);
  for (int i = 0; i < num_tries; i++) {
    display();
    printf("Word to guess for: %s\n", initial_word);
    // leave extra space at the end of string arrays for null character
    char guess_word[K_NUM_LETTERS + 1];
    printf("Your guess: ");
    scanf("%s", guess_word);
    int colors[K_NUM_LETTERS] = {0};
    check_word(colors, guess_word, initial_word);
    strcpy(past_attempts[i], guess_word);
    int win = 1;
    for (int k = 0; k < K_NUM_LETTERS; k++) {
      past_colors[i][k] = colors[k];
      if(colors[k] != 2) {win = 0;}
    }
    if(win) {
      game_end(i+1, initial_word);
    }
  }
  game_end(num_tries, initial_word);
}

void game_end(int num_attempts, char* word) {
  display();
  if(num_attempts == num_tries) {
    printf("You lose! The word was %s", word);
  } else {
    printf("You got it in %d tries!\n", num_attempts);
  }
  char replay_input;
  printf("Would you like to play again? (Y/N) ");
  scanf("%s", &replay_input);
  if(replay_input == 'Y') {
    start_game();
  } else if(replay_input == 'N') {
    printf("Thanks for playing!");
    exit(EXIT_SUCCESS);
  }
}

void get_word(char *file, char *out) {
  // Later generalize function so it allows input from any text file.
  srand(time(NULL));
  char line[K_NUM_LETTERS+2];
  int current_line = 0;
  FILE *filename = fopen(file, "r");
  if (filename == NULL) {
    perror("File not found / opened.");
  }
  fgets(line, sizeof(line), filename);
  int num_words = atoi(line);
  int word = rand() % num_words;
  while (fgets(line, sizeof(line), filename) != NULL) {
    current_line++;
    if (current_line == word) {
      // printf("Line %d: %s", current_line, line);
      for (int i = 0; i <= K_NUM_LETTERS; i++) {
        out[i] = line[i];
      }
      return;
    }
  }
  fclose(filename);
  return;
}

void check_word(int *colors, char *guess, char *word) {
  int taken_locations[K_NUM_LETTERS] = {0};
  for (int i = 0; i < K_NUM_LETTERS; ++i) {
    int index = guess[i] - 97;
    if(guess[i] == word[i]) {
      colors[i] = 2;
      taken_locations[i] = 1;
      alphabet_colors[index] = 2;
    } else {
      int char_found = 0;
      for (int j = 0; j < K_NUM_LETTERS; ++j) {
        if(guess[i] == word[j] && taken_locations[j] == 0) {
          colors[i] = 1;
          taken_locations[j] = 1;
          char_found = 1;
          // index = word[j] - 97;
          if(alphabet_colors[index] != 2) {
            alphabet_colors[index] = 1;
          }
        }
      }
      if(char_found == 0) {
        colors[i] = 3;
        if(alphabet_colors[index] == 0) {
          alphabet_colors[index] = 3;
        }
      }
    }
  }
}

int check_validity(char *guess){
  // Check if word is in the corresponding file
  // Handle capitalization properly
  // Prompt for input again if the word isn't in the file
}

// int check_win()

// Fetch the initial word from a dictionary/json/database/something else.
// Display the game in command line over time
/* handle 5 letter words as input, see which letters are
 the same as the origin (green), present in other parts of the word (yellow) */
// check if each letter is in the right word and in the right position
// if right but not in the right position, color letter yellow
// if right and in right positition, color letter green
// make two arrays and check second array for each letter in the first array
// have six chances to guess the word before game ends
