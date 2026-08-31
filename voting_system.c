/*
 * SIMPLE VOTING SYSTEM (Educational Purpose Only)
 * -------------------------------------------------
 * This program simulates a basic voting system with 10 Indian
 * political parties + NOTA (None Of The Above).
 *
 * Concepts used: variables, loops, if/else if/else, arrays,
 * basic input validation. No advanced C features.
 */

#include <stdio.h>

int main() {

    /* -----------------------------------------------------
     * STEP 1: Vote counters for each party + NOTA
     * We use one variable per party so beginners can clearly
     * see each counter (instead of a complex array of structs).
     * ----------------------------------------------------- */
    int votesBJP = 0;
    int votesINC = 0;
    int votesAAP = 0;
    int votesBSP = 0;
    int votesCPIM = 0;
    int votesCPI = 0;
    int votesSP = 0;
    int votesTMC = 0;
    int votesDMK = 0;
    int votesTDP = 0;
    int votesNOTA = 0;

    int totalVoters;   /* how many people will vote */
    int choice;        /* the option chosen by each voter */
    int i;              /* loop counter */

    /* -----------------------------------------------------
     * STEP 2: Ask how many voters will cast their vote
     * ----------------------------------------------------- */
    printf("=== SIMPLE VOTING SYSTEM ===\n");
    printf("Enter the number of voters: ");
    scanf("%d", &totalVoters);

    /* -----------------------------------------------------
     * STEP 3: Loop once for every voter
     * ----------------------------------------------------- */
    for (i = 1; i <= totalVoters; i++) {

        printf("\n---------------------------------\n");
        printf("Voter #%d, please choose a party:\n", i);
        printf("1. BJP\n");
        printf("2. INC\n");
        printf("3. AAP\n");
        printf("4. BSP\n");
        printf("5. CPI(M)\n");
        printf("6. CPI\n");
        printf("7. SP\n");
        printf("8. TMC\n");
        printf("9. DMK\n");
        printf("10. TDP\n");
        printf("11. NOTA\n");
        printf("Enter your choice (1-11): ");
        scanf("%d", &choice);

        /* -------------------------------------------------
         * STEP 4: Process the vote using if / else if / else
         * Each choice increases ONLY its own counter.
         * No vote is ever redirected to another party.
         * ------------------------------------------------- */
        if (choice == 1) {
            votesBJP++;
            printf("Vote recorded for BJP.\n");
        } else if (choice == 2) {
            votesINC++;
            printf("Vote recorded for INC.\n");
        } else if (choice == 3) {
            votesAAP++;
            printf("Vote recorded for AAP.\n");
        } else if (choice == 4) {
            votesBSP++;
            printf("Vote recorded for BSP.\n");
        } else if (choice == 5) {
            votesCPIM++;
            printf("Vote recorded for CPI(M).\n");
        } else if (choice == 6) {
            votesCPI++;
            printf("Vote recorded for CPI.\n");
        } else if (choice == 7) {
            votesSP++;
            printf("Vote recorded for SP.\n");
        } else if (choice == 8) {
            votesTMC++;
            printf("Vote recorded for TMC.\n");
        } else if (choice == 9) {
            votesDMK++;
            printf("Vote recorded for DMK.\n");
        } else if (choice == 10) {
            votesTDP++;
            printf("Vote recorded for TDP.\n");
        } else if (choice == 11) {
            votesNOTA++;
            printf("Vote recorded for NOTA.\n");
        } else {
            /* Invalid input handling.
               This vote is simply not counted for anyone. */
            printf("Invalid choice! This vote will not be counted.\n");
            i--; /* decrease i so this voter can try again */
        }
    }

    /* -----------------------------------------------------
     * STEP 5: Display the final results
     * ----------------------------------------------------- */
    printf("\n=================================\n");
    printf("           FINAL RESULTS\n");
    printf("=================================\n");
    printf("BJP     : %d votes\n", votesBJP);
    printf("INC     : %d votes\n", votesINC);
    printf("AAP     : %d votes\n", votesAAP);
    printf("BSP     : %d votes\n", votesBSP);
    printf("CPI(M)  : %d votes\n", votesCPIM);
    printf("CPI     : %d votes\n", votesCPI);
    printf("SP      : %d votes\n", votesSP);
    printf("TMC     : %d votes\n", votesTMC);
    printf("DMK     : %d votes\n", votesDMK);
    printf("TDP     : %d votes\n", votesTDP);
    printf("NOTA    : %d votes\n", votesNOTA);
    printf("=================================\n");

    /* -----------------------------------------------------
     * STEP 6: Find the winner (or detect a tie)
     * We do this WITHOUT arrays, using simple comparisons,
     * so it stays beginner-friendly.
     *
     * Approach:
     * 1. Find the highest vote count among all parties
     *    (NOTA is excluded from "winning", as is standard
     *    practice, but you can include it if you like).
     * 2. Count how many parties have that highest vote count.
     * 3. If more than one party has the highest count, it's a tie.
     * ----------------------------------------------------- */

    int highest = votesBJP;

    if (votesINC > highest) highest = votesINC;
    if (votesAAP > highest) highest = votesAAP;
    if (votesBSP > highest) highest = votesBSP;
    if (votesCPIM > highest) highest = votesCPIM;
    if (votesCPI > highest) highest = votesCPI;
    if (votesSP > highest) highest = votesSP;
    if (votesTMC > highest) highest = votesTMC;
    if (votesDMK > highest) highest = votesDMK;
    if (votesTDP > highest) highest = votesTDP;

    /* Count how many parties share this highest vote count */
    int winnerCount = 0;

    if (votesBJP == highest) winnerCount++;
    if (votesINC == highest) winnerCount++;
    if (votesAAP == highest) winnerCount++;
    if (votesBSP == highest) winnerCount++;
    if (votesCPIM == highest) winnerCount++;
    if (votesCPI == highest) winnerCount++;
    if (votesSP == highest) winnerCount++;
    if (votesTMC == highest) winnerCount++;
    if (votesDMK == highest) winnerCount++;
    if (votesTDP == highest) winnerCount++;

    printf("\n--- ELECTION OUTCOME ---\n");

    if (winnerCount > 1) {
        /* More than one party has the same highest votes -> tie */
        printf("It's a TIE! The following parties are tied with %d votes each:\n", highest);

        if (votesBJP == highest)  printf("- BJP\n");
        if (votesINC == highest)  printf("- INC\n");
        if (votesAAP == highest)  printf("- AAP\n");
        if (votesBSP == highest)  printf("- BSP\n");
        if (votesCPIM == highest) printf("- CPI(M)\n");
        if (votesCPI == highest)  printf("- CPI\n");
        if (votesSP == highest)   printf("- SP\n");
        if (votesTMC == highest)  printf("- TMC\n");
        if (votesDMK == highest)  printf("- DMK\n");
        if (votesTDP == highest)  printf("- TDP\n");

    } else {
        /* Exactly one party has the highest votes -> clear winner */
        if (votesBJP == highest)
            printf("Winner: BJP with %d votes!\n", highest);
        else if (votesINC == highest)
            printf("Winner: INC with %d votes!\n", highest);
        else if (votesAAP == highest)
            printf("Winner: AAP with %d votes!\n", highest);
        else if (votesBSP == highest)
            printf("Winner: BSP with %d votes!\n", highest);
        else if (votesCPIM == highest)
            printf("Winner: CPI(M) with %d votes!\n", highest);
        else if (votesCPI == highest)
            printf("Winner: CPI with %d votes!\n", highest);
        else if (votesSP == highest)
            printf("Winner: SP with %d votes!\n", highest);
        else if (votesTMC == highest)
            printf("Winner: TMC with %d votes!\n", highest);
        else if (votesDMK == highest)
            printf("Winner: DMK with %d votes!\n", highest);
        else if (votesTDP == highest)
            printf("Winner: TDP with %d votes!\n", highest);
    }

    printf("(NOTA received %d votes and is not counted as a winning party.)\n", votesNOTA);

    return 0;
}
