#include<stdio.h>
char sample[323][31] = {".........#..##.##..............",
"#...#.#..#.....................",
".#...#..#...................#..",
"........##..#...#..............",
".#.#.....#..#..##......#.......",
"....#..#...#..##........#..##..",
"...#....##........#.......#.#..",
"....#................#...###..#",
"...#...#.#..#....#.......####.#",
".....#...#..........#...#..#.#.",
"....#..#............#.#.#.#..#.",
"..#....#.###..#............#...",
".....#.............#.#.........",
".#.##............##.........#..",
"...##...#..#....#.##..#.....#..",
"..............#.#.........#.##.",
"...........#.....##....##......",
".......#............#...#......",
"............#.#....#....#..#..#",
"....#................####......",
"...#.........................##",
"..........#........#.#.........",
"....#.#....#...........#......#",
"..#.#..##......##..##..#..#.#..",
"...#.....##......#.#.#.........",
".........#.#....#...#.#.#......",
".......#.......###.#.......#...",
"..#............##..#.......#...",
"...#....#......#...#...#...#...",
"......#..#.#.....##......#.....",
"...........##...##...#....#.##.",
"#.##..#.....##..#.#............",
".#.#.....##......#.##........#.",
"..#...#...#...#..........#...##",
"...##.........................#",
".....#......#.....##....#.....#",
"..#........#...................",
"#......#..#.#..#..#.#..#...#...",
"...............#..........#....",
".....#...........#......#....#.",
"........#..#...............#...",
".........#...#.......#.#..#...#",
"..#..#......#.##..........#....",
".#...#....#.....#.............#",
".##.....#.........#......#..#..",
"........#..##.......#......#...",
".......#.....###......#..#.....",
".......#.#.......#.............",
"...#................##.#.......",
"..##..#...#.#...#.#..#.#.#.##..",
".......#.#............#...#....",
"#...#.....#......#..........##.",
".#.......#......#.......#.#.#..",
".#.##.#.#...........#..........",
".......#.....#....#.#.##......#",
".###..#...#.............##.....",
"......#......#.................",
"##...#.#...##...#.#.....#....#.",
"#.............#....##...#....#.",
"#.#...#....#........#.###..##..",
"......#.........#......#.#.#.#.",
"..#.#.#.....#........#..#...#..",
"#.##....#.#......#...........#.",
".#.#.####.........#..#.##....##",
"......##...............#......#",
".......#.........#........#.#..",
"....#....#..#.##.........#..#..",
".#..........#.##....#.#..#.....",
"#..#.#............#..#....#.#.#",
"..................#..#.........",
"##..##.#....#.................#",
"..................#........#..#",
".....#.........#.......##......",
".....................#.#..#...#",
".....#.........#..........#.#..",
"...#.#..#..#.#.#.......#.......",
".....#.....#.#.........#.....##",
".............##....#....##.#...",
".#......#........##..#...###...",
"........#.......##.##.#......#.",
"..#....................#.##..#.",
"......#.......#..#....##.#.....",
"...#....#.......##...#.......#.",
".#.#..#.#..........##..........",
"....#.......##...........#.....",
"###....#.......#..#...#.....##.",
"...#......#.........#..#.#..#.#",
"#.........#..##.#..............",
".#.....#..##.#..#..###.....##.#",
"..........#..#....##.......#...",
".#..#.#...#...##.#..#.##.#.....",
"#....#...#........#......##....",
"..#.####....#.#........#....#..",
"#......#............#.#........",
"...#..#.......##...........#...",
".........#..#.#..#.###.#...#..#",
"..#....##.......#.............#",
"............#..#......#........",
"........#......#..............#",
"..#.#.#...........#............",
"...........#......##.#.#.......",
".#..........#...........#..#...",
".....#...#..#.........##...#...",
".......#....##....#.#.........#",
"..#.#......#.......#...##.#....",
".....#..........#........#.....",
"#.......#.......#............#.",
"..##.#.....#.##.#.#.#..#.......",
"..#...#.......#.###............",
".#...#..#....#...#...#..#....##",
".....#.....#...................",
".......................#......#",
"......#...##.........#...#..#..",
".....#..#.....#..............#.",
".#.##..#..#....................",
"....#..#...#....#.............#",
"..###..#...#......#.....#......",
"..#......###....#.....#.....###",
"...#.##..#...#.....#........#..",
".#.#...........##....#...#.##..",
".......#...##......#..#..#.....",
"#.............#..#...##.#..#..#",
"..........#......#.......#.....",
"...............#.#.#....#...#..",
"#.......#.#..#.....#........#..",
".#.#.#.......#..#.........##...",
"......#.....#.#....#...........",
"..#.....##.#........##.#......#",
"...###...#..#.........#........",
"....#...................#..#...",
".##........#...................",
"....#..#...........#.#.........",
".....#.......#...#....#.#......",
".........#...#.......#.#...#...",
".......#.#..#....#....#.......#",
"..#.............#..............",
".#...#..#.#.#..#............#..",
"...#.##.##..#..#...........##..",
"...........#...#..#.#........#.",
"....#...#.....#...#.#....#...#.",
".......#.#...##..#.............",
".......................#....#..",
"..#..#.....#...........#....#..",
".#..#...#.##........##....#....",
"#.....##.#.#.......#.....#...#.",
".#....#.......................#",
"#..##..###...#.........#.......",
"..##...#...#..........#....#...",
"......#..##......##.#.........#",
"................#........#..#..",
".....#.#..#.....#.......#..#...",
"..#..#.....#.......#..#..#...#.",
".#....#...#...#......##.....#..",
"....#........#...#......##....#",
"..#..........##......#......#..",
"#.#.....#.....#.......#........",
"...#...#......#....##.#..#...##",
"...#....#...#.#...........##...",
"#....##...#...#....#...........",
"...#.#..#...#..............##..",
"#..#..........##.#.#.....#.....",
"..#...#.........#.#..........#.",
"....#.....#..........#.........",
"........................#......",
".#.....#.#...###...#....#......",
"....##....#....#..#.##........#",
"..#........#.........#.......#.",
".....#.#......#...#...#........",
"........#..#.....#....###....#.",
"...........#..#.#....#.#....##.",
".......#.....##.#............#.",
"...............#........##.##..",
".............#...##......#...#.",
"#...##.#.......#......###.....#",
"..........#...#........#..#....",
"....#....................#...#.",
".#......#...#.......#....#.#...",
"....#.......................#..",
"#...#...#...#.##....##.........",
"..........#.#...##.#...#.......",
"..#...............#....#..#...#",
"#..#..#...#..#.........#...#...",
".....#..#..........#.##.#..##..",
"........#......##.....#........",
".#....#.#.........#...#..#.#...",
"....#..............##..........",
"#...............#..............",
"..###.........#....##.........#",
".........#.#....##........#...#",
"....#.#..#......#...#..........",
"...#.#.....#....#..#....#.#..#.",
"............#..#.....#...##....",
"...........#....#.#.#...#......",
"#...............#....###.......",
".........#.....##.#..#..#......",
"...#...##...###...............#",
".#......#.#.#.................#",
".........##..#............#....",
"..#..#.....#.....#.#...........",
".#......##............#.#....#.",
".#.##..##.##..#.........#.....#",
"...##.##......##.##......#.....",
"##.....#.#...#...#...#..#......",
"....................#......#...",
".....#.................#...###.",
"...........#..#.........#.#....",
"...#........#..#........#....#.",
"#................#......###...#",
".............##.#.....#.#......",
"...#...#.##..#........##.......",
"#..#.##...#....#.#.............",
".#.........#.#..#...........#..",
"....#...#.....#.#..........#...",
".#.#....###.......##.....#.##..",
".##....##......#......#.#....#.",
"..#...#.#........#...#..##.....",
"..............###..........##..",
"#....#..##.....#.....#.....#...",
"...#...#....................#..",
".#....#.#.....#.#..#..##.......",
"#...##..###......#.............",
"..........#.#....##.#........##",
"..#..#.....#...#....#.#.#......",
"#.....#........#..##.#.........",
"....#.....#..........##......#.",
"......#..#.....#........#.....#",
".....#..#....#...........#.##..",
".#....................#....#..#",
"........#..#...........#.......",
"#....#.#.......#........#.#..#.",
"........#.....#...#............",
"..#........#........#....#...#.",
".....##.......#..#..........#..",
"......#.#......###...#....##..#",
".#..#.............#.#..........",
"#.....##.#.#.#.#.#.....#.....#.",
".#..#.....#.......#.#.....#....",
"###....##...#.#...#..#......###",
".#................#.....#.##...",
"....##....#.#........###.#.#...",
"#.#....#........#.....#.......#",
"..........#..........#.##...#..",
"....#....#..##......#..#.......",
".....#..........#.##...........",
"##......#.#......#.##..........",
"##..........##.......##........",
"..#.....#....#.##..#..#..#.....",
"......###...#...........#...###",
"#..#.............##............",
"...#.###.....#..#.........#.#..",
"......#...............#...#.#..",
".....#...##.#...#.....#.#..#...",
"..#..#.#....#.#................",
"...............##.....#........",
"......#.#.....#...#.........#..",
"........#..#...#.#...#......#..",
"#...........#.......#...##...#.",
"........#.#...#..##..#.#...#...",
"..#....#...#......#..........##",
"..#..............##...##.#.....",
"...#....#..#....##.........#.#.",
".#.#....#..........#.......#...",
"...##....#.#....#....#.#...#...",
"..............#..##........#..#",
"..........#.#...##......#..#.#.",
"#...##..#......................",
".......#........##.#.#.#.......",
".........##..#.#.......####....",
"..#.............#..#........##.",
"##..#..#...#....#.....#...#..#.",
"..#.#...#.#.....#..............",
"..#....#....#..##...#.#........",
"##.....#..#...#................",
"#....#.....................#...",
"..............###.....#.#.#....",
"..#......##.#....#.#...##......",
"#...#.#......#...#.#......#....",
"....#...................##.#...",
".........##......#.....#.####..",
"##..#........#.....#......##..#",
"...#..#...#...#.............#..",
"#..#..#.#......###...#.........",
".......#.#..#........#....##..#",
"............#..##.....#.#.#....",
"#..#.....#.....#....##........#",
"......#..........##............",
".....#...#...........#.........",
"...........#....#...#....#.#...",
"....#.........##.##.......#....",
"......#....#...........#.##...#",
".##.#.#..##...#.....##.#...#...",
".......#.#....#...#...#....#...",
".#...##.#.#.....#..#....#......",
".#....###..#.......#......#...#",
"..#.#.........#.........#.....#",
".......#.#.##..#.#.......##..#.",
".##............#.........#....#",
".#...##.###..#........##.#..#..",
"..#........#.#.....##..##.#....",
"...........#...........#.....#.",
".#...######..##...#.....#......",
".#.##.#.......#......#......#..",
".#.....#.....#........#........",
"...#..#...#.##...#...........#.",
".......#.....#.......#.........",
"............#...###...........#",
"...#.......#.......##....#..#..",
"##.......#....#....####........",
".......#.#......#..........#..#",
"#.....##..#..#.....#....#...#..",
"#............#........##.......",
".#.#...#.............#..##.....",
".#....#..#.#......#.##.......##",
"...................##...##..###",
"..#.....#...#................#.",
"..#...#....#...#.#.#...#.....#.",
".....#............#....#...#..#",
".#.....#....#..#......#.#.....#",
"............#.#.....####.##....",
"....#......###....#...#....#...",
"#.....#..#.....#..#...#.......#",
"..#.#...#....#....##..#...##...",
".##..#..#..##....##...#........"};

char test[11][11] ={"..##.......",
"#...#...#..",
".#....#..#.",
"..#.#...#.#",
".#...##..#.",
"..#.##.....",
".#.#.#....#",
".#........#",
"#.##...#...",
"#...##....#",
".#..#...#.#"};

int num_trees(void* arg, int numRows,int numCols)
{
	int trees = 0;
	int right = 0;
	char* sample = (char*)arg;
	for(size_t i=1; i<numRows; i++) {
		right += 3;
		if(*(sample + i*numCols + right % (numCols -1))== '#') {trees++;}
	}
	
}

int num_trees_test(void)
{
	int trees = 0;
	int right = 0;
	for(size_t i=1; i<323; i++) {
		right += 3;
		if(sample[i][right & 31] == '#') {trees++;}
	}
}
int main(void)
{
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<11; i++) {
			right += 1;
			if(test[i][right % 11] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<11; i++) {
			right += 3;
			if(test[i][right % 11] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<11; i++) {
			right += 5;
			if(test[i][right % 11] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<11; i++) {
			right += 7;
			if(test[i][right % 11] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=2; i<11; i = i+2) {
			right += 1;
			if(test[i][right % 11] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
	}
	



  int trees_each_option[5] = {0};

	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<323; i++) {
			right += 1;
			if(sample[i][right % 31] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
		trees_each_option[0] = trees;
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<323; i++) {
			right += 3;
			if(sample[i][right % 31] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
		trees_each_option[1] = trees;
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<323; i++) {
			right += 5;
			if(sample[i][right % 31] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
		trees_each_option[2] = trees;
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=1; i<323; i++) {
			right += 7;
			if(sample[i][right % 31] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
		trees_each_option[3] = trees;
	}
	{
		int trees = 0;
		int right = 0;
		for(size_t i=2; i<323; i= i+2) {
			right += 1;
			if(sample[i][right % 31] == '#') {trees++;}
		}
		
		printf("%u\n", trees);
		trees_each_option[4] = trees;
	}
	printf("product %u\n", trees_each_option[0]*trees_each_option[1]*trees_each_option[2]*trees_each_option[3]*trees_each_option[4]);
return 0;
}