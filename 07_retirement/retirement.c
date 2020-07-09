#include <stdio.h>
#include <stdlib.h>

/*Our Struct*/
struct _retire_info{
  int months;
  double contribution, rate_of_return;
};
typedef struct _retire_info retire_info;



/*Computation*/

double computation(double balance, retire_info struct_Data){
  double _new = balance;
  _new  = _new + (_new * (struct_Data.rate_of_return)/1200) + struct_Data.contribution;
  return _new;
}


/*retirement calling compuation*/
void retirement (int startAge, double initial,  retire_info working,  retire_info retired){
  //*Working*//
  double _new = initial;
  int age = startAge;
  for(int i = 0; i < working.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n", age/12, age% 12, _new); /*years = months/12*/ /*month rem 12 gives a number between 0 and 11*/
    _new = computation(_new, working);
    age++;
  }
  /*Retired*/
  for(int i = 0; i<retired.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n", age/12, age % 12, _new);
    _new = computation(_new, retired);
    age++;
  }
}



int main(void){
  /*Starting codintion*/
  int StartAge = 327;
  double balance = 21345;
  /*Working*/
  retire_info Working;
  Working.months = 489; Working.contribution = 1000; Working.rate_of_return = 4.5;

  /*Retired*/
  retire_info Retired;
  Retired.months = 384; Retired.contribution = -4000; Retired.rate_of_return = 1;
  retirement(StartAge, balance, Working, Retired);
  return EXIT_SUCCESS;
}
