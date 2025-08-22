#include <stdio.h>
#include <locale.h>

int digitsCount(long long int number);
int luhnAlgorithm(long long int number, int totalDigits);
int cardBanner(long long int number, int totalDigits);

int main() {
	setlocale(LC_ALL, "");
	
	long long int creditCard;
	int totalDigits, cardValidation, banner;
	
	printf("Digite o numero do cartão: ");
	scanf("%lld", &creditCard);
	totalDigits = digitsCount(creditCard);
	
	cardValidation = luhnAlgorithm(creditCard, totalDigits);
	banner = cardBanner(creditCard, totalDigits);
	
	if (luhnAlgorithm(creditCard, totalDigits) % 10 != 0) {
		printf("Cartão INVÁLIDO\n");
	} else if (banner == 1 && cardValidation % 10 == 0) {
		printf("AMERICAN EXPRESS. Válido\n");
	} else if (banner == 2 && cardValidation % 10 == 0) {
		printf("VISA. Válido\n");
	} else {
		printf("MASTERCARD. Válido\n");
	}
	return 0;
}


//---FUNÇÕES---------------------------------

int digitsCount(long long int number) {
	int count = 0;
	
	while (number > 0) {
		number /= 10;
		count++;
	}
	return count;
}

int luhnAlgorithm(long long int number, int totalDigits) {
	int digitsVector[totalDigits], count = 0;
	
	while (number > 0) {
		digitsVector[count] = number % 10;
		number /= 10;
		count++;
	}
	
	int multiplierCount = 0;
	for (int i = 1; i < totalDigits; i++) {
		multiplierCount++;
		i++;
	}
	
	int multiplierVector[multiplierCount], count2 = 0, sum1 = 0, sumDoubles = 0;
	for (int i = 1; i < totalDigits; i++) {
		multiplierVector[count2] = digitsVector[i] * 2;
		
		if (multiplierVector[count2] > 9) {
			sum1 += multiplierVector[count2] / 10;
			sumDoubles += multiplierVector[count2] % 10;
		} else {
			sum1 += multiplierVector[count2];
		}
		count2++;
		i++;
	}
	
	int multiplierVectorTotal = sum1 + sumDoubles;
	for (int i = 0; i < totalDigits; i++) {
		multiplierVectorTotal += digitsVector[i];
		i++;
	}
	
	return multiplierVectorTotal;
}

int cardBanner(long long int number, int totalDigits) {
	int digitsVector[totalDigits], count = 0;
	
	while (number > 0) {
		digitsVector[count] = number % 10;
		number /= 10;
		count++;
	}
	
	if ((totalDigits == 15 && digitsVector[totalDigits - 1] == 3) && 
	   (digitsVector[totalDigits - 2] == 4 || digitsVector[totalDigits -2] == 7)) {
	   	return 1;
	   } else if ((totalDigits == 13 || totalDigits == 16) && (digitsVector[totalDigits - 1] == 4)) {  
				 	return 2;
				 } else if ((totalDigits == 16 && digitsVector[totalDigits - 1] == 5) &&
				 		   (digitsVector[totalDigits - 2] == 1 ||
							digitsVector[totalDigits - 2] == 2 ||
							digitsVector[totalDigits - 2] == 3 ||
							digitsVector[totalDigits - 2] == 4 ||
							digitsVector[totalDigits - 2] == 5)) {
				 	return 3;
				 }
}
	
