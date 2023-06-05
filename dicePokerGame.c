#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void display_hand(int hand[], int max_die);
int rank_hand(int hand[], int max_dice);
int roll_die();
void display_rank(int rank);
void deal_hand(int hand[], int max_die);

int main()
{
    srand(time(NULL));
    char inp;
    int player_wins = 0;
    int games_played = 0;
    int dealer_wins = 0;
    int draw = 0;
    printf("Would you like to play dice poker [y|n]?\n");
    scanf("%c", &inp);
    int f = 0;
    char k;
    while (f == 0 && (inp != 'y' && inp != 'n'))
    {
        printf("Please enter either 'y' or 'n'.\n");
        scanf(" %c", &inp);
        if (inp == 'y' || inp == 'n')
        {
            f = 1;
        }
    }
    if (inp == 'y')
    {
        int flag1 = 0;
        while (inp != 'n' && flag1 == 0)
        {
            games_played++;
            int player_hand[5] = {0};
            deal_hand(player_hand, 5);
            /* Display player's hand to the screen. */
            printf("\n\nPlayer's hand:");
            display_hand(player_hand, 5);
            int die_count_player[7] = {0};
            for (int i = 0; i < 5; i++)
            {
                int die_value = player_hand[i];                                // This will store the die value that player's hand had at that time
                die_count_player[die_value] = die_count_player[die_value] + 1; // This will increment the value
            }
            int player_rank = rank_hand(die_count_player, 7); // this function will provide us the rank according to the die_count function
            printf("--Player has ");
            display_rank(player_rank);
            printf("\n");
            int dealer_hand[5] = {0};
            deal_hand(dealer_hand, 5);
            printf("\n\nDealer's hand:");
            display_hand(dealer_hand, 5);
            int die_count_dealer[7] = {0};
            for (int i = 0; i < 5; i++)
            {
                int die_value = dealer_hand[i];
                die_count_dealer[die_value] = die_count_dealer[die_value] + 1;
            }
            int dealer_rank = rank_hand(die_count_dealer, 7);
            printf("--Dealer has ");
            display_rank(dealer_rank);
            printf("\n");
            if (player_rank > dealer_rank)
            {
                printf("**Player wins! **\n");
                player_wins++;
            }
            else if (dealer_rank > player_rank)
            {
                printf("**Dealer wins! **\n");
                dealer_wins++;
            }
            else if (player_rank == dealer_rank)
            {
                printf("**Draw! **\n");
                draw++;
            }
            printf("\n");
            printf("Play Again?(y/n)");
            scanf(" %c", &inp);
            if (inp != 'y' && inp != 'n')
            {
                printf("Please enter either 'y' or 'n'.\n");
            }
            if (inp == 'n')
            {
                flag1 = 1;
            }
        }
    }
    printf("\n");
    printf("Game Summary\n");
    printf("============\n");
    printf("You played %d games\n", games_played);
    printf("|--> Games won: %d\n", player_wins);
    printf("|--> Games lost: %d\n", dealer_wins);
    printf("|--> Games drawn: %d\n", draw);
    printf("\n\n");
    printf("Thanks for playing!\n");
    printf("No worries... another time perhaps... :)\n");
}

void deal_hand(int hand[], int max_die)
{
    for (int i = 0; i < 5; i++)
    {
        int die_num = roll_die(); // this varible will take random number and store it
        hand[i] = die_num;
    }
}

void display_hand(int hand[], int max_die)
{
    int i;
    /*Display die number on the screen*/
    printf("\n%16s", "");
    for (i = 0; i < max_die; i++)
    {
        printf("Die %-4d", i + 1);
    }
    printf("\n%12s", "");

    /*Display face value of the die to the screen*/
    printf("     ");
    for (i = 0; i < max_die; i++)
    {
        printf("[%d]     ", hand[i]);
    }
    printf("\n%12s", " ");

    /*Display the top row of face value to the screen*/
    for (i = 0; i < max_die; i++)
    {
        if (hand[i] == 1)
        {
            printf("%8s", " ");
        }
        else if (hand[i] == 2 || hand[i] == 3)
        {
            printf("%8s", "* ");
        }
        else if (hand[i] == 4 || hand[i] == 5 || hand[i] == 6)
        {
            printf("%8s", "* *");
        }
    }
    printf("\n%12s", " ");
    /*Display the middle row of the face value to the screen*/
    for (i = 0; i < max_die; i++)
    {
        if (hand[i] == 1 || hand[i] == 3 || hand[i] == 5)
        {
            printf("%8s", "* ");
        }
        else if (hand[i] == 6)
        {
            printf("%8s", "* *");
        }
        else
        {
            printf("%8s", " ");
        }
    }
    printf("\n%12s", "");

    /*Display the bottom row of the face value to the screen*/
    for (i = 0; i < max_die; i++)
    {
        if (hand[i] == 1)
        {
            printf("%8s", " ");
        }
        else if (hand[i] == 2 || hand[i] == 3)
        {
            printf("%8s", "* ");
        }
        else if (hand[i] == 4 | hand[i] == 5 || hand[i] == 6)
        {
            printf("%8s", "* *");
        }
    }
    printf("\n\n");
}

int roll_die()
{
    int num = 1 + rand() % 6;
    return num;
}

int rank_hand(int hand[], int max_dice)
{
    /*Made varibles that will store the number of times a number has appeared like count_1 will store 1 , count_2 will store 2 */
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;
    int count_5 = 0;
    for (int i = 0; i < max_dice; i++)
    {
        if (hand[i] == 1)
        {
            count_1 = count_1 + 1;
        }
        else if (hand[i] == 2)
        {
            count_2 = count_2 + 1;
        }
        else if (hand[i] == 3)
        {
            count_3 = count_3 + 1;
        }
        else if (hand[i] == 4)
        {
            count_4 = count_4 + 1;
        }
        else if (hand[i] == 5)
        {
            count_5 = count_5 + 1;
        }
    }
    if (count_2 == 1 && count_3 == 0)
    {
        return 1;
    }
    else if (count_2 == 2)
    {
        return 2;
    }
    else if (count_3 == 1)
    {
        if (count_2 == 1)
        {
            return 4;
        }
        else
        {
            return 3;
        }
    }
    else if (count_4 == 1)
    {
        return 5;
    }
    else if (count_5 == 1)
    {
        return 6;
    }
    else if (count_1 == 5)
    {
        return 0;
    }
}

void display_rank(int rank)
{
    if (rank == 0)
    {
        printf("Nothing special\n");
    }
    else if (rank == 1)
    {
        printf("One pair\n");
    }
    else if (rank == 2)
    {
        printf("Two pairs\n");
    }
    else if (rank == 3)
    {
        printf("Three of a kind\n");
    }
    else if (rank == 4)
    {
        printf("Full house\n");
    }
    else if (rank == 5)
    {
        printf("Four of a kind\n");
    }
    else if (rank == 6)
    {
        printf("Five of a kind\n");
    }
}