
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
    float overs_bowled;
};

struct Match {
    char team1[50];
    char team2[50];
    struct Player team1_players[11];
    struct Player team2_players[11];
    int team1_score;
    int team2_score;
    char venue[100];
    char date[20];
};

void addMatch(struct Match *m) {
    printf("Enter match details:\n");
    printf("Team 1 name: ");
    scanf("%s", m->team1);
    printf("Team 2 name: ");
    scanf("%s", m->team2);
    printf("Venue: ");
    scanf("%s", m->venue);
    printf("Date: ");
    scanf("%s", m->date);

    m->team1_score = 0;
    m->team2_score = 0;
}

void updateScore(struct Match *m, int team, int runs) {
    if (team == 1) m->team1_score += runs;
    else m->team2_score += runs;
}

void displayMatch(struct Match m) {
    printf("\nMatch Details:\n");
    printf("%s vs %s\n", m.team1, m.team2);
    printf("Venue: %s\n", m.venue);
    printf("Date: %s\n", m.date);
    printf("Score: %s: %d - %s: %d\n", m.team1, m.team1_score, m.team2, m.team2_score);
}

int main() {
    struct Match match;
    int choice, runs, team;

    do {
        printf("\n1. Add Match\n2. Update Score\n3. Display Match\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addMatch(&match); break;
            case 2: 
                printf("Enter team (1/2): ");
                scanf("%d", &team);
                printf("Enter runs to add: ");
                scanf("%d", &runs);
                updateScore(&match, team, runs);
                break;
            case 3: displayMatch(match); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
void saveMatchToFile(struct Match m, const char* filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&m, sizeof(struct Match), 1, fp);
    fclose(fp);
}

void loadMatchFromFile(struct Match *m, const char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fread(m, sizeof(struct Match), 1, fp);
    fclose(fp);
}

void appendMatchLog(struct Match m) {
    FILE *fp = fopen("match_log.txt", "a");
    if (fp == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    fprintf(fp, "%s vs %s, Date: %s, Venue: %s, Score: %d-%d\n", 
            m.team1, m.team2, m.date, m.venue, m.team1_score, m.team2_score);
    fclose(fp);
}