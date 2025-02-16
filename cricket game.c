#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_instructions() {
    printf("Welcome to the Text-Based Cricket Game!\n");
    printf("Instructions:\n");
    printf("1. Choose your run (1-6) for each ball.\n");
    printf("2. A random run will be generated for the bowler.\n");
    printf("3. If your run matches the bowler's run, you're out!\n");
    printf("4. If not, your run is added to your total score.\n");
    printf("Let's play!\n\n");
}

int get_player_run() {
    int run;
    printf("Enter your run (1-6): ");
    scanf("%d", &run);
    while (run < 1 || run > 6) {
        printf("Invalid input! Please enter a run between 1 and 6: ");
        scanf("%d", &run);
    }
    return run;
}

int get_bowler_run() {
    return (rand() % 6) + 1;
}

void play_innings(const char *player_name, int *score) {
    int player_run, bowler_run;
    *score = 0;
    while (1) {
        player_run = get_player_run();
        bowler_run = get_bowler_run();

        printf("Bowler's run: %d\n", bowler_run);

        if (player_run == bowler_run) {
            printf("Out! %s scored %d runs.\n", player_name, *score);
            break;
        } else {
            *score += player_run;
            printf("Current Score: %d\n", *score);
        }
    }
}

int main() {
    srand(time(0));

    display_instructions();

    int player_score, computer_score;

    printf("\n--- Player's Innings ---\n");
    play_innings("Player", &player_score);

    printf("\n--- Computer's Innings ---\n");
    play_innings("Computer", &computer_score);

    printf("\n--- Match Result ---\n");
    if (player_score > computer_score) {
        printf("Congratulations! You won by %d runs.\n", player_score - computer_score);
    } else if (player_score < computer_score) {
        printf("Computer won by %d runs. Better luck next time!\n", computer_score - player_score);
    } else {
        printf("It's a tie! What a game!\n");
    }

    return 0;
}
