//Flower Garden

//http://www.ieeeuestcoj.com/contest/1/problem/2/


#include <iostream>
#include <vector>
#include <cmath>


typedef struct  point
{
    int x;
    int y;
}FlowerPoint;

typedef struct  record
{
    int flowers_number; //number of flowers
    int max_total_distance;//maximum total distance
}TestRecord;


int distance(FlowerPoint a,FlowerPoint b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int countFlowers(std::vector<TestRecord> list,int n)
{
    int flowers=0;
    for(int i=0;i<n;i++)
        flowers+=list[i].flowers_number;
    return flowers+1*(n+1);
}
bool isPrime( int num )  

{  
				if(num ==1 )  
                                 return 0 ;  
                 //两个较小数另外处理  
                 if(num ==2|| num==3 )  
                                 return 1 ;  
                 //不在6的倍数两侧的一定不是质数  
                 if(num %6!= 1&&num %6!= 5)  
                                 return 0 ;  
                 int tmp =sqrt( num);  
                 //在6的倍数两侧的也可能不是质数  
                 for(int i= 5;i <=tmp; i+=6 )  
                                 if(num %i== 0||num %(i+ 2)==0 )  
                                                 return 0 ;  
                 //排除所有，剩余的是质数  
                 return 1 ;  
}    
int main()
{
    int t;//talen test times
	std::vector<FlowerPoint> flist;
    std::vector<TestRecord> rlist;
	int i,j;

  //  talen
    std::cin>>t;
	
    
    //test loop read data
    for(i=0;i<t;i++)
    {
     //   std::cout<<"test "<<i<<std::endl;
		FlowerPoint flower_tmp={0,0};
        TestRecord record_tmp;
        std::cin>>record_tmp.flowers_number>>record_tmp.max_total_distance;
        rlist.push_back(record_tmp);

        //读数据
		
		  flist.push_back(flower_tmp);
        for(j=0;j<record_tmp.flowers_number;j++)
        {       
		//	 std::cout<<"  flower"<<j<<":"<<std::endl;
            std::cin>>flower_tmp.x>>flower_tmp.y;
            flist.push_back(flower_tmp);
        }
        
    }
  
    for(int i=0;i<t;i++)
    {
       // std::cout<<"test"<<i<<std::endl;;
        int total_distance=0,total_flower=0;
		 int flower_pointer=countFlowers(rlist,i);
        for(int j=0;j<rlist[i].flowers_number;j++)
        {
           
            total_distance+=distance(flist[flower_pointer+j], flist[flower_pointer+j-1]);
			
			//	std::cout<<"re:"<<total_distance<<std::endl;
				
			if(total_distance<=rlist[i].max_total_distance) 
				total_flower=j+1;
			else
				break;

           
        }
      if(isPrime(total_flower))
		std::cout<<total_flower<<std::endl;
	  else
		  std::cout<<0<<std::endl;
    }
    
   getchar();
    return 0;
}

