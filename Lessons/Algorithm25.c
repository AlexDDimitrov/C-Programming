#include <stdio.h>
//да се изведе кой ден от годината е//
void main()
{
    int d, m, y, brd, vis, den_num, i;
    den_num=0;
    do{
        printf("Enter the day = ");
        scanf("%d", &d);
        printf("Enter the month = ");
        scanf("%d", &m);
        printf("Enter the year = ");
        scanf("%d", &y);

        if (y%4==0)
        {
            if(y%100) vis=1;
            else
                if(y%400) vis=0;
                else vis=1;
        }
        else vis=0;
        switch (m)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: brd=31; break;
            case 4: case 6: case 9: case 11: brd=30; break;
            case 2: brd=28+vis; break;
        }
    } while (y<0 || m<1 || m>12 || d<1 || d>brd);
    for (i=1;i<m;i++)
        {
            switch (i)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: den_num+=31; break;
            case 4: case 6: case 9: case 11: den_num+=30; break;
            case 2: den_num+=28+vis; break;
        }
        }
    den_num+=d;
    printf("The date is the %d day of the year", den_num );

}