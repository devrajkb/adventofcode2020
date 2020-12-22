#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/*
--- Day 22: Crab Combat ---

It only takes a few hours of sailing the ocean on a raft for boredom to sink in. Fortunately, you brought a small deck of space cards! You'd like to play a game of Combat, and there's even an opponent available: a small crab that climbed aboard your raft before you left.

Fortunately, it doesn't take long to teach the crab the rules.

Before the game starts, split the cards so each player has their own deck (your puzzle input). Then, the game consists of a series of rounds: both players draw their top card, and the player with the higher-valued card wins the round. The winner keeps both cards, placing them on the bottom of their own deck so that the winner's card is above the other card. If this causes a player to have all of the cards, they win, and the game ends.

For example, consider the following starting decks:

Player 1:
9
2
6
3
1

Player 2:
5
8
4
7
10

This arrangement means that player 1's deck contains 5 cards, with 9 on top and 1 on the bottom; player 2's deck also contains 5 cards, with 5 on top and 10 on the bottom.

The first round begins with both players drawing the top card of their decks: 9 and 5. Player 1 has the higher card, so both cards move to the bottom of player 1's deck such that 9 is above 5. In total, it takes 29 rounds before a player has all of the cards:

-- Round 1 --
Player 1's deck: 9, 2, 6, 3, 1
Player 2's deck: 5, 8, 4, 7, 10
Player 1 plays: 9
Player 2 plays: 5
Player 1 wins the round!

-- Round 2 --
Player 1's deck: 2, 6, 3, 1, 9, 5
Player 2's deck: 8, 4, 7, 10
Player 1 plays: 2
Player 2 plays: 8
Player 2 wins the round!

-- Round 3 --
Player 1's deck: 6, 3, 1, 9, 5
Player 2's deck: 4, 7, 10, 8, 2
Player 1 plays: 6
Player 2 plays: 4
Player 1 wins the round!

-- Round 4 --
Player 1's deck: 3, 1, 9, 5, 6, 4
Player 2's deck: 7, 10, 8, 2
Player 1 plays: 3
Player 2 plays: 7
Player 2 wins the round!

-- Round 5 --
Player 1's deck: 1, 9, 5, 6, 4
Player 2's deck: 10, 8, 2, 7, 3
Player 1 plays: 1
Player 2 plays: 10
Player 2 wins the round!

...several more rounds pass...

-- Round 27 --
Player 1's deck: 5, 4, 1
Player 2's deck: 8, 9, 7, 3, 2, 10, 6
Player 1 plays: 5
Player 2 plays: 8
Player 2 wins the round!

-- Round 28 --
Player 1's deck: 4, 1
Player 2's deck: 9, 7, 3, 2, 10, 6, 8, 5
Player 1 plays: 4
Player 2 plays: 9
Player 2 wins the round!

-- Round 29 --
Player 1's deck: 1
Player 2's deck: 7, 3, 2, 10, 6, 8, 5, 9, 4
Player 1 plays: 1
Player 2 plays: 7
Player 2 wins the round!


== Post-game results ==
Player 1's deck: 
Player 2's deck: 3, 2, 10, 6, 8, 5, 9, 4, 7, 1

Once the game ends, you can calculate the winning player's score. The bottom card in their deck is worth the value of the card multiplied by 1, the second-from-the-bottom card is worth the value of the card multiplied by 2, and so on. With 10 cards, the top card is worth the value on the card multiplied by 10. In this example, the winning player's score is:

   3 * 10
+  2 *  9
+ 10 *  8
+  6 *  7
+  8 *  6
+  5 *  5
+  9 *  4
+  4 *  3
+  7 *  2
+  1 *  1
= 306

So, once the game ends, the winning player's score is 306.

Play the small crab in a game of Combat using the two decks you just dealt. What is the winning player's score?

*/
char test_player1[5][10] ={"9",
"2",
"6",
"3",
"1",};

char test_player2[5][10] ={"5",
"8",
"4",
"7",
"10",};

char player1[25][10] = {"14",
"23",
"6",
"16",
"46",
"24",
"13",
"25",
"17",
"4",
"31",
"7",
"1",
"47",
"15",
"9",
"50",
"3",
"30",
"37",
"43",
"10",
"28",
"33",
"32",};

char player2[25][10] = {"29",
"49",
"11",
"42",
"35",
"18",
"39",
"40",
"36",
"19",
"48",
"22",
"2",
"20",
"26",
"8",
"12",
"44",
"45",
"21",
"38",
"41",
"34",
"5",
"27",};

typedef struct node_s {
	struct node_s* next;
	int value;
} node_t;

void prepare_list(char* data_player1, char* data_player2, int num_entries,  node_t** first_player1,  node_t** first_player2,   node_t** last_player1,  node_t** last_player2)
{
	char* data_player1_base = data_player1;
	char* data_player2_base = data_player2;
	for (size_t i = 0; i < num_entries; i++) {
		 data_player1 = data_player1_base+ i*10;
		 data_player2 = data_player2_base+ i*10;
		 {
			 node_t* node_1 =  malloc(sizeof(node_t)); 
			 node_1->next = NULL;
			 node_1->value =  atoi(data_player1);
			 if ( *first_player1 == NULL) {
				 *first_player1 = node_1;
				 *last_player1 = node_1;
			 }
			 else {
				 (*last_player1)->next = node_1;
				 *last_player1 = node_1;
			 }
		 }
		 {
			 node_t* node_2 =  malloc(sizeof(node_t)); 
			 node_2->next = NULL;
			 node_2->value =  atoi(data_player2);
			 if ( *first_player2 == NULL) {
				 *first_player2 = node_2;
				 *last_player2 = node_2;
			 }
			 else {
				 (*last_player2)->next = node_2;
				 *last_player2 = node_2;
			 }
		 }
	}
}

void print_list(node_t * first_player1,  node_t * first_player2)
{
	{
		node_t* node = first_player1;
		printf("\n Player1: ");
		int i=0;
		while(node != NULL) {
			 printf(" %2u:%2u", i++, node->value );
			 node = node->next;
		 };
	}
	{
		node_t* node = first_player2;
		printf("\n Player2: ");
		int i=0;
		while(node != NULL) {
			 printf(" %2u:%2u", i++, node->value );
			 node = node->next;
		 };
	}
	
}

int value_calc(node_t* first_player1, node_t* first_player2, int num_entries)
{
	 int win_value = 0;
	 int place= 2*num_entries;
	 node_t* node = NULL;
	 printf("\n");
	 if(first_player1 != NULL) {
		node = first_player1;
	 }
	 else{
		 node = first_player2;
	 }
	 while(node != NULL) {
		 win_value += place*node->value;
		 printf(" %2u:%2u", place, node->value );
		 place--;
		 node = node->next;
	 };
	 return win_value;
}


int find_winner_and_swap(node_t* node_1,  node_t* node_2,  node_t** first_player1,  node_t** first_player2,   node_t** last_player1,  node_t** last_player2) 
{
	 int winner_player1 = 0;
	 //printf("\n node1: %u node2: %u last %u:%u", node_1->value, node_2->value, (*last_player1)->value, (*last_player2)->value);
	 if (node_1->value > node_2->value) {
		 (*last_player1)->next =  node_1;
		 node_1->next = node_2;
		 *last_player1 = node_2;
		 node_2->next = NULL;
		 //printf("->%2u:%u", last_player1->value, count);
		 if (*first_player1 == NULL) {
			 *first_player1 = node_1;
			 printf("\n node1: %u node2: %u first %u: last %u", node_1->value, node_2->value, (*first_player1)->value, (*last_player1)->value);
		 }
		 winner_player1 =1;
	 }
	 else {
		 (*last_player2)->next =  node_2;
		 node_2->next = node_1;
		 *last_player2 = node_1;
		 node_1->next = NULL;
		 //printf("->%2u:%u", last_player2->value, count);
		 if (*first_player2 == NULL) {
			 *first_player2 = node_2;
			 printf("\n node1: %u node2: %u first %u: last %u", node_1->value, node_2->value, (*first_player2)->value, (*last_player2)->value);
		 }
	 }
	 return winner_player1;
}
int winner_value(char* data_player1, char* data_player2, int num_entries)
{
	node_t *first_player1 = NULL;
	node_t *last_player1 = NULL;
	node_t *first_player2 = NULL;
	node_t *last_player2 = NULL;
    
	prepare_list(data_player1, data_player2, num_entries, &first_player1, &first_player2, &last_player1, &last_player2); 
    print_list(first_player1, first_player2);
	
	printf("\n\n");
	int count = 0;
     while ((first_player1 != NULL) && (first_player2 != NULL) ) {
		 node_t* node_1 = first_player1;
		 first_player1 = first_player1->next;
		 node_t* node_2 = first_player2;
		 first_player2 = first_player2->next;
		 count++;
		 //printf("\n%2u:%2u", node_1->value, node_2->value);
        find_winner_and_swap(node_1, node_2, &first_player1, &first_player2, &last_player1, &last_player2);
	 };
     
    return value_calc(first_player1, first_player2, num_entries);
}
int sub_game_count = 0;
int find_winner_sub_game(node_t* first_player1_org,  node_t* first_player2_org, int num_entries_1, int num_entries_2)
{
	node_t *first_player1 = NULL;
	node_t *last_player1 = NULL;
	node_t *first_player2 = NULL;
	node_t *last_player2 = NULL;
    int winner_player1 = 0;
	
	printf("\nSubgame %u: num_entries_1 %u num_entries_2 %u \n", ++sub_game_count, num_entries_1, num_entries_2);
	
	node_t* node_org = first_player1_org;
	 for (int  i = 0; i< num_entries_1; i++) {
		 node_t* node_1 =  malloc(sizeof(node_t)); 
		 node_1->next = NULL;
		 node_1->value =  node_org->value;
		 printf("%2u:%2u",i, node_org->value);
		 if ( first_player1 == NULL) {
			 first_player1 = node_1;
			 last_player1 = node_1;
		 }
		 else {
			 (last_player1)->next = node_1;
			 last_player1 = node_1;
		 }
		 node_org = node_org->next;
	 }
	
	node_org = first_player2_org;
	 for (int  i = 0; i< num_entries_2; i++) {
		 node_t* node_1 =  malloc(sizeof(node_t)); 
		 node_1->next = NULL;
		 node_1->value =  node_org->value;
		 printf("%2u:%2u",i, node_org->value);
		 if ( first_player2 == NULL) {
			 first_player2 = node_1;
			 last_player2 = node_1;
		 }
		 else {
			 last_player2->next = node_1;
			 last_player2 = node_1;
		 }
		 node_org = node_org->next;
	 }
	 
	 int player1_entries = num_entries_1;
	 int player2_entries = num_entries_2;
	 int count = 0;
	 while ((first_player1 != NULL) && (first_player2 != NULL) ) {
		 node_t* node_1 = first_player1;
		 first_player1 = first_player1->next;
		 player1_entries--;
		 node_t* node_2 = first_player2;
		 first_player2 = first_player2->next;
		 player2_entries--;
		 count++;
		 
		 if ((node_1->value <= player1_entries) && (node_2->value <= player2_entries) )  {
			 if(find_winner_sub_game(first_player1,  first_player2, node_1->value , node_2->value )) {
				 last_player1->next =  node_1;
				 node_1->next = node_2;
				 last_player1 = node_2;
				 node_2->next = NULL;
				 player1_entries += 2;
				 //printf("->%2u:%u", last_player1->value, count);
				 if (first_player1 == NULL) {
					 first_player1 = node_1;
				 }
			}
			else {
				 last_player2->next =  node_2;
				 node_2->next = node_1;
				 last_player2 = node_1;
				 node_1->next = NULL;
				 player2_entries += 2;
				 //printf("->%2u:%u", last_player2->value, count);
				 if (first_player2 == NULL) {
					 first_player2 = node_2;
				 }
			}
		 }
		 else{
			if (find_winner_and_swap(node_1, node_2, &first_player1, &first_player2, &last_player1, &last_player2)) {
				player1_entries += 2;
			}
			else {
				player2_entries += 2;
			}
		 }
	 
		 if ((player1_entries == num_entries_1) && (player2_entries == num_entries_2)) {
			 printf("\n %u:%u->%u:%u", player1_entries,  num_entries_1, player2_entries, num_entries_2);
			 node_t* node_org = first_player1_org;
			 node_t* node         = first_player1;
			 int index_player1 = 0;
			 int index_player2 = 0;		 
			 for (index_player1 = 0; index_player1 < num_entries_1; index_player1++) {
				if (node_org->value != node->value) {
					break;
				}
				node_org = node_org->next;
				node        = node->next;
			 }
		 
			 node_org = first_player2_org;
			 node         = first_player2;
			 for (index_player2 = 0;  index_player2 < num_entries_2; index_player2++) {
				if (node_org->value != node->value) {
					break;
				}
				node_org = node_org->next;
				node        = node->next;
			 }
		 
			 if ((index_player1 == num_entries_1) && (index_player2 == num_entries_2)) {
				 winner_player1 = 1;
				 break;
			 }
		}
	};
	
	if (first_player2 == NULL) 
	{
		winner_player1 = 1;
	}
	
	return winner_player1;
}
int winner_value_rec(char* data_player1, char* data_player2, int num_entries)
{
	node_t *first_player1 = NULL;
	node_t *last_player1 = NULL;
	node_t *first_player2 = NULL;
	node_t *last_player2 = NULL;
    
	prepare_list(data_player1, data_player2, num_entries, &first_player1, &first_player2, &last_player1, &last_player2); 
    print_list(first_player1, first_player2);
	
	int player1_entries = num_entries;
	int player2_entries = num_entries;

	printf("\n\n");
	int count = 0;
     while ((first_player1 != NULL) && (first_player2 != NULL) ) {
		 node_t* node_1 = first_player1;
		 first_player1 = first_player1->next;
		 player1_entries--;
		 node_t* node_2 = first_player2;
		 first_player2 = first_player2->next;
		 player2_entries--;
		 count++;
		 
		 if ((node_1->value <= player1_entries) && (node_2->value <= player2_entries) )  {
			 if(find_winner_sub_game(first_player1,  first_player2, node_1->value , node_2->value )) {
				 last_player1->next =  node_1;
				 node_1->next = node_2;
				 last_player1 = node_2;
				 node_2->next = NULL;
				 player1_entries += 2;
				 //printf("->%2u:%u", last_player1->value, count);
				 if (first_player1 == NULL) {
					 first_player1 = node_1;
				 }
			}
			else {
				 last_player2->next =  node_2;
				 node_2->next = node_1;
				 last_player2 = node_1;
				 node_1->next = NULL;
				 player2_entries += 2;
				 //printf("->%2u:%u", last_player2->value, count);
				 if (first_player2 == NULL) {
					 first_player2 = node_2;
				 }
			}
		 }
		 else{
			if (find_winner_and_swap(node_1, node_2, &first_player1, &first_player2, &last_player1, &last_player2)) {
				player1_entries += 2;
			}
			else {
				player2_entries += 2;
			}
		 }
	 };


    return value_calc(first_player1, first_player2, num_entries);
}

int main(void)
{
	printf("\nValue %u\n", winner_value((char*)test_player1, (char*)test_player2 , 5));
	printf("\nValue %u\n", winner_value((char*)player1, (char*)player2 , 25));
	
	sub_game_count = 0;
    printf("\nValue %u\n", winner_value_rec((char*)test_player1, (char*)test_player2 , 5));
	sub_game_count = 0;
	printf("\nValue %u\n", winner_value_rec((char*)player1, (char*)player2 , 25));
	return 0;
}