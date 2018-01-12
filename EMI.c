#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float P,temp ,Ammount,Rate_of_Interest,Tenor;
	printf("Enter Loan Ammount(in Rs):\n");
	scanf("%f",&Ammount);
	printf("Enter Rate of Interest(percent per year): \n" );
	scanf("%f",&Rate_of_Interest);
	printf("Enter Tenor(in Months):\n");
	scanf("%f",&Tenor);
	Rate_of_Interest=Rate_of_Interest/100;
	// scanf("%llf",Ammount);
	// scanf("%llf",Ammount);
	P = (Ammount*Rate_of_Interest/12)/(1 - pow((1 + Rate_of_Interest/12),(-Tenor)));
	printf("EMI:\t %f \n", P );
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("| No.\t| EMI \t \t| Principal o/s at begning | \t Interest  \t| Principal Repayment |\t o/s at  end \t|\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	float IPMT;
	int i;
	float Principal_Repayment,Outstanding_Balance=Ammount,PV=Ammount;
	for (i = 1; i <=Tenor ; ++i)
	{

	IPMT=-(pow((1+Rate_of_Interest/12),(i-1))*(-PV*Rate_of_Interest/12+P)-P);
	Principal_Repayment=P-IPMT;
	temp=Outstanding_Balance;
	Outstanding_Balance= Outstanding_Balance - Principal_Repayment;
	// PV=Outstanding_Balance;
	printf("|%d \t| %f \t| %f\t \t| \t %f\t|%f\t\t|%f\t|\n",i,P,temp,IPMT,Principal_Repayment,Outstanding_Balance );
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	return 0;
}