#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <pthread.h>


/*
--- Day 13: Shuttle Search ---

Your ferry can make it safely to a nearby port, but it won't get much further. When you call to book another ship, you discover that no ships embark from that port to your vacation island. You'll need to get from the port to the nearest airport.

Fortunately, a shuttle bus service is available to bring you from the sea port to the airport! Each bus has an ID number that also indicates how often the bus leaves for the airport.

Bus schedules are defined based on a timestamp that measures the number of minutes since some fixed reference point in the past. At timestamp 0, every bus simultaneously departed from the sea port. After that, each bus travels to the airport, then various other locations, and finally returns to the sea port to repeat its journey forever.

The time this loop takes a particular bus is also its ID number: the bus with ID 5 departs from the sea port at timestamps 0, 5, 10, 15, and so on. The bus with ID 11 departs at 0, 11, 22, 33, and so on. If you are there when the bus departs, you can ride that bus to the airport!

Your notes (your puzzle input) consist of two lines. The first line is your estimate of the earliest timestamp you could depart on a bus. The second line lists the bus IDs that are in service according to the shuttle company; entries that show x must be out of service, so you decide to ignore them.

To save time once you arrive, your goal is to figure out the earliest bus you can take to the airport. (There will be exactly one such bus.)

For example, suppose you have the following notes:

939
7,13,x,x,59,x,31,19

Here, the earliest timestamp you could depart is 939, and the bus IDs in service are 7, 13, 59, 31, and 19. Near timestamp 939, these bus IDs depart at the times marked D:

time   bus 7   bus 13  bus 59  bus 31  bus 19
929      .       .       .       .       .
930      .       .       .       D       .
931      D       .       .       .       D
932      .       .       .       .       .
933      .       .       .       .       .
934      .       .       .       .       .
935      .       .       .       .       .
936      .       D       .       .       .
937      .       .       .       .       .
938      D       .       .       .       .
939      .       .       .       .       .
940      .       .       .       .       .
941      .       .       .       .       .
942      .       .       .       .       .
943      .       .       .       .       .
944      .       .       D       .       .
945      D       .       .       .       .
946      .       .       .       .       .
947      .       .       .       .       .
948      .       .       .       .       .
949      .       D       .       .       .

The earliest bus you could take is bus ID 59. It doesn't depart until timestamp 944, so you would need to wait 944 - 939 = 5 minutes before it departs. Multiplying the bus ID by the number of minutes you'd need to wait gives 295.

What is the ID of the earliest bus you can take to the airport multiplied by the number of minutes you'll need to wait for that bus?

*/
int timestap_test = 939;
#define COL     10
char test[8][COL] = {"7","13","x","x","59","x","31","19"};

int timestamp_samplet = 1004345;
char sample[92][COL] = {"41","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","37","x","x","x","x","x","379","x","x","x","x","x","x","x","23","x","x","x","x","13","x","x","x","17","x","x","x","x","x","x","x","x","x","x","x","29","x","557","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","19",};

char test_1[4][COL] = {"67","7","59","61"};
char test_2[5][COL] = {"67","x","7","59","61"};
char test_3[5][COL] = {"67","7","x", "59","61"};
char test_4[4][COL] = {"1789","37","47", "1889"};

#define NTHREADS 8

	typedef struct bus_id_pos {
		int bus_id;
		int pos;
	} bus_id_pos_t;
	


int product_early_waiting_timestamp(char* data, int num_elements, int timestamp)
{
	int least_wait = timestamp;
	int bus_id = 0;
	for (int i =0; i <  num_elements; i++) 
	{
	    char* str = data;
		if (strcmp(str, "x") != 0) {
			 int value = atoi(str);
			 int waiting = value - (timestamp) % value;
			 if (waiting < least_wait) {
				 least_wait = waiting;
				 bus_id = value;
			 }
		}
		data = data + COL;
	}
	printf ("least_wait %u bus_id %u \n", least_wait, bus_id);
	return least_wait*bus_id;
}

int check_timestamp_pos(bus_id_pos_t* bus_id_pos_holder, int num_elements, long int timestamp) 
{
	for (size_t i =1; i <  num_elements; i++)
	{
		int value  = bus_id_pos_holder[i].bus_id;
		int waiting = bus_id_pos_holder[i].pos;
		if ((value != 0) && 
		     (((timestamp + waiting) % value) != 0) ) {
			return 0;
		}
	}
	return 1;
}

typedef struct thread_args_s {
	int num_bus_ids;
	int factor;
	bus_id_pos_t * bus_id_pos_holder;
	bus_id_pos_t *max_bus_id_pos;
	uint64_t timestamp;
}thread_args_t;

void* my_thread_fun(void *args)
{
	thread_args_t* thread_args =  (thread_args_t*) args;
	
	bus_id_pos_t* bus_id_pos_holder = thread_args->bus_id_pos_holder;
	int num_bus_ids = thread_args->num_bus_ids;
	uint64_t timestamp = thread_args->timestamp;
	int max_bus_id =  thread_args->max_bus_id_pos->bus_id;
	int max_pos = thread_args->max_bus_id_pos->pos;
	int factor = thread_args->factor;
	size_t i =0;
	long int mul = 0;
    //if(num_bus_ids > 8) {	mul = 20000000000;};
	printf("mul %lu max_bus_id %u factor:%u\n", mul, max_bus_id , factor );
	
    do {
		timestamp = (NTHREADS * mul+ factor)*max_bus_id;
		{   
			for (i =0; i <  num_bus_ids; i++)
			{
				if (((timestamp + bus_id_pos_holder[i].pos - max_pos) % bus_id_pos_holder[i].bus_id) != 0) {
					break;
				}
			}
       }
	   	if (num_bus_ids == i) {
				break;
		}
		
		if ( !(mul % 100000000) /*|| mul <= NTHREADS*8*/) {
			//printf("Crazy large mul %lu timestamp %lu factor:%u\n", mul, timestamp , factor );
		}
		mul++;
	}while(mul < 10000000000000000);

	if (mul < 100000000000000) {printf("THIS IS it %lu  mul %lu  factor %u\n ",timestamp-max_pos, mul, factor); /*exit(1);*/}
        thread_args->timestamp = timestamp-max_pos;
	return NULL;
}

uint64_t positon_waiting_timestamp_lcm(char* data, int num_elements)
{
    bus_id_pos_t* bus_id_pos_holder = calloc(num_elements, sizeof(*bus_id_pos_holder));

	int first_bus_id = atoi(data);
	int num_bus_ids = 1;
	data = data + COL;
	bus_id_pos_holder[0].bus_id = first_bus_id;
	bus_id_pos_holder[0].pos = 0;

	bus_id_pos_t max_bus_id_pos = {first_bus_id, 0};
	// timestamp is mulliple of first_bus_id
	for (int i = 1 ; i <  num_elements; i++) 
	{
	    char* str = data;
		if (strcmp(str, "x") != 0) {
			 bus_id_pos_holder[num_bus_ids].bus_id = atoi(str);
	         bus_id_pos_holder[num_bus_ids].pos = i;

			 if (max_bus_id_pos.bus_id < atoi(str)) {
				 max_bus_id_pos.bus_id = atoi(str);
				 max_bus_id_pos.pos = i;
			 }
			 num_bus_ids++;
		}
		data = data + COL;
	}
	
			for (int i = 0; i <  num_bus_ids; i++)
			{
				printf("bus id %u pos %u\n", bus_id_pos_holder[i].bus_id, bus_id_pos_holder[i].pos);
			}
	uint64_t timestamp = 0;
	long int mul = 1; 
	if (num_elements == 92) {
		timestamp = 10000;
		timestamp *= 10000;
		timestamp *= 1000;
		timestamp *= max_bus_id_pos.bus_id;
		printf("Crazy large mul %lu timestamp %lu max_bus_id_pos.bus_id %u  %lu num_bus_ids %u \n", mul, timestamp, max_bus_id_pos.bus_id, (uint64_t)(max_bus_id_pos.bus_id*10000*10000*10000), num_bus_ids);
	}
#if 1	
	if (num_elements > 0) {
		pthread_t threads[NTHREADS];
		thread_args_t thread_args[NTHREADS];
		int rc, i;

	  /* spawn the threads */
	  for (i=0; i<NTHREADS; ++i)
		{
		  thread_args[i].num_bus_ids  = num_bus_ids;
		  thread_args[i].bus_id_pos_holder = bus_id_pos_holder;
		   thread_args[i].max_bus_id_pos = &max_bus_id_pos;
		  thread_args[i].timestamp  = timestamp;
		  thread_args[i].factor  = i;
		  printf("spawning thread %d\n", i);
		  rc = pthread_create(&threads[i], NULL, my_thread_fun, (void *) &thread_args[i]);
		}

	  /* wait for threads to finish */
	  for (i=0; i<NTHREADS; ++i) {
		rc = pthread_join(threads[i], NULL);
	  }
          timestamp = thread_args[0].timestamp;
	  for (i=0; i<NTHREADS; ++i){
             if (timestamp > thread_args[i].timestamp) { timestamp = thread_args[i].timestamp;} 
          	//printf("timestamp %lu :%u \n", thread_args[i].timestamp, i);
          }

         printf("FINAL VALUE timestamp %lu \n", timestamp);
	}
#else
	size_t i =0;
    do {
		timestamp += max_bus_id_pos.bus_id;// - max_bus_id_pos.pos;

		{   
			for (i = 0; i <  num_bus_ids; i++)
			{
				//int value  = bus_id_pos_holder[i].bus_id;
				//int waiting = bus_id_pos_holder[i].pos;
				if (/*(max_bus_id_pos.bus_id != bus_id_pos_holder[i].bus_id) && (bus_id_pos_holder[i].bus_id != 0) && */
					 (((timestamp + bus_id_pos_holder[i].pos  - max_bus_id_pos.pos) % bus_id_pos_holder[i].bus_id) != 0) ) {
					break;
				}
			}
       }
	   	if (num_bus_ids == i) {
				break;
		}
/*
		if (check_timestamp_pos(bus_id_pos_holder, num_bus_ids, timestamp) == 1) {
			break;
		}
*/
		if ( !(mul % 100000000)) {
			printf("Crazy large mul %lu timestamp %lu\n", mul, timestamp);
		}
		mul++;
	}while(1);
		
	//printf ("least_wait %u bus_id %u \n", least_wait, bus_id);
	printf ("mul %lu \n", mul);

#endif
	return timestamp;
}


int main(void) 
{
	printf("Product %u\n", product_early_waiting_timestamp ((char*)test, 8, timestap_test));
	printf("Product %u\n", product_early_waiting_timestamp ((char*)sample, 92, timestamp_samplet));
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)test_1, 4));
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)test_2, 5));	
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)test_3, 5));
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)test_4, 4));		
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)test, 8));
	printf("timestamp %lu\n", positon_waiting_timestamp_lcm ((char*)sample, 92));
}
