#include<stdio.h>
#include<string.h>
struct{
	char engine[20];
	char fueltype[20];
	int seatingcap;
	int fuelcap;
	int citymileage;
}car1,car2;//global scope-->works for all
int main(){
	strcpy(car1.engine,"V8");
	strcpy(car1.fueltype,"Petrol");
	car1.fuelcap=10;
	car1.seatingcap=5;
	car1.citymileage=7;
	
	strcpy(car2.engine,"Electric");
	strcpy(car2.fueltype,"Battery");
	car2.fuelcap=20;
	car2.seatingcap=8;
	car2.citymileage=120;
	
	printf("-----------------------------------------------------------------------------------\n");
	printf("| %-10s | %-10s |  %-10s |  %-10s |  %-10s |  %-10s |\n","S.No","Engine","Fueltype","Fuelcap","Seats","Mileage");
   	printf("-----------------------------------------------------------------------------------\n");
	printf("| %-10d | %-10s | %-10s | %-10d | %-10d | %-10d |\n",1,car1.engine,car1.fueltype,car1.seatingcap,car1.fuelcap,car1.citymileage);
	printf("-----------------------------------------------------------------------------------\n");
	printf("| %-10d | %-10s | %-10s | %-10d | %-10d | %-10d |\n",2,car2.engine,car2.fueltype,car2.seatingcap,car2.fuelcap,car2.citymileage);
	printf("-----------------------------------------------------------------------------------\n");
}//output
//-----------------------------------------------------------------------------------
//| S.No       | Engine     |  Fueltype   |  Fuelcap    |  Seats      |  Mileage    |
//-----------------------------------------------------------------------------------
//| 1          | V8         | Petrol     | 5          | 10         | 7          |
//-----------------------------------------------------------------------------------
//| 2          | Electric   | Battery    | 8          | 20         | 120        |
//-----------------------------------------------------------------------------------