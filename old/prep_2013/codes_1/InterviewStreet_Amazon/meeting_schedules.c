/* 
 Given M busy-time slots of N people, You need to print all the available time slots when all the N people can schedule a meeting for a duration of K minutes.
Event time will be of form HH MM ( where 0 <= HH <= 23 and 0 <= MM <= 59 ), K will be in the form minutes.
 
Input Format:
 
M K [ M number of busy time slots , K is the duration in minutes ]
Followed by M lines with 4 numbers on each line.
Each line will be of form StartHH StartMM EndHH EndMM  [ Example 9Am-11Am time slot will be given as 9 00 11 00 ]
An event time slot is of form [Start Time, End Time ) . Which means it inclusive at start time but doesn’t include the end time. 
So an event of form 10 00  11 00 => implies that the meeting start at 10:00 and ends at 11:00, so another meeting can start at 11:00.
 
Sample Input:
5 120
16 00 17 00
10 30 14 30
20 45 22 15
10 00 13 15
09 00 11 00
 
Sample Output:
00 00 09 00
17 00 20 45
 
Sample Input:
8 60
08 00 10 15
22 00 23 15
17 00 19 00
07 00 09 45
09 00 13 00
16 00 17 45
12 00 13 30
11 30 12 30
 
Sample Output:
00 00 07 00
13 30 16 00
19 00 22 00
 
Constraints :
1 <= M <= 100
 
Note: 24 00 has to be presented as 00 00.
*/

/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#define DAY_MIN 1440 /* #minutes in a day */

int main()
{
    int day[DAY_MIN] = {0};
    int m, k;
    int i, j;
    int a, b, c, d;
    
    scanf("%d %d", &m, &k);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (j = a*60 + b; j != c*60 + d; j = (j+1)%DAY_MIN) {
        //for (j = a*60 + b; j != c*60 + d; ++j) {
            day[j] = 1;
        }
    }
    
    int flag = -1;
    int start = -1;
    for (i = 0; i < DAY_MIN; ++i) {
        if (day[i] == 0 && flag != 0) {
            start = i;
            flag = 0;
        } else if (day[i] == 1 && flag != 1) {
            flag = 1;
            if (start != -1 && i - start >= k) {
                printf("%02d %02d %02d %02d\n", start/60, start%60, i/60, i%60);
            }
        }
    }
    if (flag != 1 && i - start >= k) {
           printf("%02d %02d 00 00\n", start/60, start%60);
    }
    
    return 0;
}
