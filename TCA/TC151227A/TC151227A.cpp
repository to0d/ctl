#include <lt_help/lt.h>

/* 
射击运动员10枪打90环的打发有多少种？用一段程序实现，将每种打发打印出来。
（每法成绩均为整数，且在0到10环之间，可为0环也可为10环） */

static int hit_index   = 0;
const int ignore_index = 92300;

#define TRACE printf
//#define TRACE

int try_hit_10(int* hit_buf, int hit_pos, int hit_total, int hit_left)
{
    if( hit_left < 0 ||  hit_left > (hit_total - hit_pos) * 10 ) 
        return 0;
    
	if( hit_pos == hit_total - 1 || hit_left == 0) 
	{ 
        if( hit_index++ < ignore_index)
            return 0; 
            
        hit_buf[ hit_pos++ ] =  hit_left;
        while ( hit_pos++ < 10 ) 
            hit_buf[ hit_pos++ ] = 0;
        
        TRACE("%03d: ",hit_index);
        for(int i =0; i < 10; ++i)	
            TRACE(" %2d,",hit_buf[i]);
        
	    TRACE("\n");   
    	return 1;
	}
    
    int hit = 0;

	for(int i =0; i <= 10; ++i)
	{   hit_buf[hit_pos] = i;
		hit += try_hit_10(hit_buf, hit_pos + 1, hit_total, hit_left - i); 
	}
    
    return hit;
}

int try_hit(){
    int a[10];
	return try_hit_10(a, 0, 10, 90);
}

void test()
{
    int count = try_hit();
    cout << "output: " << count << endl;
}


int main(void)
{    
    test();
    return 0;
}