#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
--- Day 15: Rambunctious Recitation ---

You catch the airport shuttle and try to book a new flight to your vacation island. Due to the storm, all direct flights have been cancelled, but a route is available to get around the storm. You take it.

While you wait for your flight, you decide to check in with the Elves back at the North Pole. They're playing a memory game and are ever so excited to explain the rules!

In this game, the players take turns saying numbers. They begin by taking turns reading from a list of starting numbers (your puzzle input). Then, each turn consists of considering the most recently spoken number:

    If that was the first time the number has been spoken, the current player says 0.
    Otherwise, the number had been spoken before; the current player announces how many turns apart the number is from when it was previously spoken.

So, after the starting numbers, each turn results in that player speaking aloud either 0 (if the last number is new) or an age (if the last number is a repeat).

For example, suppose the starting numbers are 0,3,6:

    Turn 1: The 1st number spoken is a starting number, 0.
    Turn 2: The 2nd number spoken is a starting number, 3.
    Turn 3: The 3rd number spoken is a starting number, 6.
    Turn 4: Now, consider the last number spoken, 6. Since that was the first time the number had been spoken, the 4th number spoken is 0.
    Turn 5: Next, again consider the last number spoken, 0. Since it had been spoken before, the next number to speak is the difference between the turn number when it was last spoken (the previous turn, 4) and the turn number of the time it was most recently spoken before then (turn 1). Thus, the 5th number spoken is 4 - 1, 3.
    Turn 6: The last number spoken, 3 had also been spoken before, most recently on turns 5 and 2. So, the 6th number spoken is 5 - 2, 3.
    Turn 7: Since 3 was just spoken twice in a row, and the last two turns are 1 turn apart, the 7th number spoken is 1.
    Turn 8: Since 1 is new, the 8th number spoken is 0.
    Turn 9: 0 was last spoken on turns 8 and 4, so the 9th number spoken is the difference between them, 4.
    Turn 10: 4 is new, so the 10th number spoken is 0.

(The game ends when the Elves get sick of playing or dinner is ready, whichever comes first.)

Their question for you is: what will be the 2020th number spoken? In the example above, the 2020th number spoken will be 436.

Here are a few more examples:

    Given the starting numbers 1,3,2, the 2020th number spoken is 1.
    Given the starting numbers 2,1,3, the 2020th number spoken is 10.
    Given the starting numbers 1,2,3, the 2020th number spoken is 27.
    Given the starting numbers 2,3,1, the 2020th number spoken is 78.
    Given the starting numbers 3,2,1, the 2020th number spoken is 438.
    Given the starting numbers 3,1,2, the 2020th number spoken is 1836.

Given your starting numbers, what will be the 2020th number spoken?

Your puzzle input is 18,8,0,5,4,1,20.
*/

int test_1[3] = {0,3,6};
int sample[7] = {18,8,0,5,4,1,20};
typedef struct history_s {
	struct history_s *left;
	struct history_s *right;
	int key;
	int place[2];
} history_t; 

history_t* g_history_head_ptr= NULL; 

history_t* creat_history_node(int key, int pos)
{
	history_t* node = malloc(sizeof(history_t));
	node->left = NULL;
	node->right = NULL;
	node->key = key;
	node->place[0] = pos;
	node->place[1] = -1;
	//node->index_entries = 1;
}


void insert(history_t** root, int key, int pos) {
#if 0	
  if (!(*root))  {
    (*root) = creat_history_node(key, pos);
  }
  else if (key == (*root)->key) {
	  (*root)->key = key;
	  (*root)->place[1]  = (*root)->place[0];
	  (*root)->place[0] = pos;
	}
  else if (key < (*root)->key)
    insert(&(*root)->left, key, pos);
  else  // key > root->key
    insert(&(*root)->right, key, pos);
#endif

  history_t **walk = root;
  while (*walk) { 
    int curkey = (*walk)->key;
    if (curkey == key) {
	  (*walk)->key = key;
	  (*walk)->place[1]  = (*walk)->place[0];
	  (*walk)->place[0] = pos;
      return;
    }
    if (key > curkey) 
      walk = &(*walk)->right;
    else 
      walk = &(*walk)->left;
  }
  *walk = creat_history_node(key, pos);
}

history_t*  search_rec(int key, history_t* node) {
	if ((node == NULL) || (node->key == key)) {
		return node;
	}
	else if (key < node->key) {
		return search_rec(key, node->left);
	}
	else {
		return search_rec(key, node->right);
	}
}
int find_in_history(int key,  int current_place, int *new_value) 
{
        history_t* node = search_rec(key, g_history_head_ptr);

		if ((node) && (node->place[1] != -1)) {
			*new_value = node->place[0] - node->place[1];
			if (*new_value == key) {
				node->place[1] = node->place[0];
				node->place[0] = current_place;
			}
  		    return 1;				 
		}
		else  {
			*new_value = 0;
			return 0;
		}
}

int number_on_turn (int* data,  int num_element,  int turn )
{
	g_history_head_ptr= NULL; 

	int last_value = 0;
	for (size_t i = 0; i < turn; i++) {
		int new_value = 0;
		if (i < num_element) {
			last_value = data[i];
			insert(&g_history_head_ptr, last_value, i);
		}
		else {
				if (find_in_history(last_value, i, &new_value)) {
				if (last_value != new_value) {
					last_value = new_value;
					insert(&g_history_head_ptr, last_value, i);
				}
			}
			else {
				last_value = new_value;
				insert(&g_history_head_ptr, last_value, i);
			}
		}
		if ((i %100000) == 0) {printf("\n Present turn %lu and value %u",i,  last_value);}
	}
	return last_value;
}



int main(void) 
{
	
	//printf("2020th turn no %u\n", number_on_turn (test_1, 3, 2020));
	//printf("2020th turn no %u\n", number_on_turn (sample, 7, 2020));
	//printf("30000000th turn no %u\n", number_on_turn_30000000 (test_1, 3));
	printf("\n30000000th turn no %u\n", number_on_turn (sample, 7, 30000000));
	return 0;
}