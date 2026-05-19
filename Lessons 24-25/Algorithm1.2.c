void change (int *pa, int*pb) 

{  

int c; 

c = *pa; 

*pa = *pb;

*pb = c;
} 

 

void main () 

{ 

int x = 10, y=15; 

change(&x, &y); 

printf(“x=%d, y=%d”, x,y) 

 

} 
