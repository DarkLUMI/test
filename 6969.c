#include <stdio.h>
#include<time.h>

struct Product{
	char productName[14]; 
	double productPrice;
	int productQuantity;
};

int main()
{
	{ //file open record
		FILE *pF = fopen("Stock.dat", "w");
	
		struct Product product1 = {"ChicShawarma", 12.70, 55};
		struct Product product2 = {"BeefShawarma", 13.70, 56};
		struct Product product3 = {"CheeseCalzone", 33.00, 57};
		struct Product product4 = {"ChicKebabRice", 30.00, 58};
		struct Product product5 = {"BeefKebabRice", 31.00, 59};
		struct Product product6 = {"MixKebabRice", 30.70, 60};
		struct Product product7 = {"Beer", 12.00, 61};
		struct Product product8 = {"Bebsi", 3.00, 62};

		struct Product products[] = {product1, product2, product3, product4, product5, product6, product7, product8};

		for(int i = 0; i < sizeof(products)/sizeof(products[0]); i++) 
		{
			fprintf(pF, "%s, %.2f, %d\n", products[i].productName, products[i].productPrice, products[i].productQuantity);
		}
	
		fclose(pF);
		
	
	 //interface
		printf("----------------------------------------\n\tWelcome to 69 Restaurant\n----------------------------------------\n");
		printf("Welcome My Friend! Below is our menu:\n");
		printf("\nItem \t\tPrice \t\tQuantity\n");
		printf("**** \t\t***** \t\t********\n");
		printf("1.ChicShawarma \tRM12.70 \t%d\n", products[0].productQuantity);
		printf("2.BeefShawarma \tRM13.70 \t%d\n", products[1].productQuantity);
		printf("3.CheeseCalzone RM33.00 \t%d\n", products[2].productQuantity);
		printf("4.ChicKebabRice RM30.00 \t%d\n", products[3].productQuantity);
		printf("5.BeefKebabRice RM31.00 \t%d\n", products[4].productQuantity);
		printf("6.MixKebabRice \tRM30.70 \t%d\n", products[5].productQuantity);
		printf("7.Beer \t\tRM12.00 \t%d\n", products[6].productQuantity);
		printf("8.Bebsi \tRM3.00 \t\t%d\n", products[7].productQuantity);
		printf("9.Confirm Order\n");
		printf("\nPress the number accordingly to order:");
	
	 //get input from users
		int selections, A=0, B=0, C=0, D=0, E=0, F=0, G=0, H=0;
		double price='\0', total, Ap, Bp, Cp, Dp, Ep, Fp, Gp, Hp;
		
		do{scanf("%d", &selections);
		
			switch(selections){
				case 1: price = 12.70+price;
						A = A+1;
						Ap = 12.70*A;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 2: price = 13.70+price;
						B = +1;
						Bp = 13.70*B;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 3: price = 33.00+price;
						C = +1;
						Cp = 33.00*C;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 4: price = 30.00+price;
						D = +1;
						Dp = 30.00*D;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 5: price = 31.00+price;
						E = +1;
						Ep = 31.00*E;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 6: price = 30.70+price;
						F = +1;
						Fp = 30.70*F;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 7: price = 12.00+price;
						G = +1;
						Gp = 12.00*G;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 8: price = 3.00+price;
						H = +1;
						Hp = 3.00*H;
						printf("Insert number to add more items, press 9 to end: ");
					break;
				case 9: printf("Enter 1 to get 10%% Discount, 2 for 20%%! : ");
					break;
				default: printf("Sorry, please insert a valid number:");
		}
		}while(selections != 9);
		
	//promocode promt
		
		int promo;
		
		scanf("%d", &promo);
		total = price;
		
		switch(promo){
				case 1: total = price/100;
						total = total*90;
						printf("\n10% discount applied in your amount!");
					break;
				case 2: total = price/100;
						total = total*80;
						printf("\n20% discount applied in your amount!");
					break;
				default: printf("Sorry, please insert a valid promo number:");
		}
		
		printf("\nTotal amount before discount is RM%.2lf", price);
		printf("\nTotal amount is RM%.2lf", total);
		
		
	//receipt create
		
		time_t t;
		time(&t);
		
		FILE *pFR = fopen("Recept.txt", "w");
		
		fprintf(pFR, "*** 69 Restaurant ***\n");
		fprintf(pFR, "Date and Time: %s\n\n", ctime(&t));
		fprintf(pFR, "%d", selections);
		
		if(A!=0){
			fprintf(pFR, "\nChicShawarma\tx%d\tRM%.2lf\n", A, Ap);
		}
		else (B!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", B, Bp);
		}
		for(C!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", C, Cp);
		}
		for(D!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", D, Dp);
		}
		for(E!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", E, Ep);
		}
		for(F!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", F, Fp);
		}
		for(G!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", G, Gp);
		}
		for(H!=0){
			fprintf(pFR, "\nBeefShawarma\tx%d\tRM%.2lf\n", H, Hp);
		}
		
		fprintf(pFR, "\nThank You!\n*** 69 Restaurant ***" );
		
		fclose(pFR);
		
	}
	
	
	return 0;
}


