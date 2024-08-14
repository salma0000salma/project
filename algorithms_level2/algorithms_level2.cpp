// algorithms_level2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <math.h>
#include <ymath.h>


using namespace std;

enum enPrimeNotPrime {Pirme=1, NotPrime = 2};
enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialC = 3, Digit = 4};

int ReadPositiveNumber(string message) {
	int number = 0;
	cout <<message<<endl;
	cin >> number;

	return number;
}

float ReadNumber() {
	float number = 0;
	cout <<"\nPlease enter a number ?\n";
	cin >> number;

	return number;
}

//enPrimeNotPrime CheckPrime(int number) {
//	int m = round(number/ 2);
//	
//
//	for(int counter = 2; counter <= m; counter++) {
//		if(number % counter == 0)
//			return enPrimeNotPrime::NotPrime;
//	}
//	return enPrimeNotPrime::Pirme;
//}

//void PrintNumberType(int number){
//	switch (CheckPrime(number))
//	{
//	case enPrimeNotPrime::Pirme:
//			cout<<"Number is Prime"<<endl;
//			break;
//	case enPrimeNotPrime::NotPrime:
//		cout<<"Number is not Prime"<<endl;
//			break;
//	}
//}

void PrintTableHeader() {
	cout<<"\n\n\t\t\t"<<"Multiplication Table from 1 to 10"<<"\t\t\t\t\t\n"<<endl;
	cout <<"\t";
	for(int i = 1; i <= 10; i++) {
		cout <<i<<"\t";
	}
	//cout <<"\n\n";
	cout<<"\n___________________________________________________________________________________\n";
}

string ColumnSperator(int i) {
	if(i < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiTableFrom1to10() {
	
	PrintTableHeader();
	for(int i = 1; i <= 10; i++) {
		cout <<" "<<i<<ColumnSperator(i) <<"\t";

		for(int j = 1; j <= 10; j++) {
			cout << i * j<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n\n";
}

bool isPerfectNumber(int number) {
	int sum = 0;

	for(int i = 1; i < number; i++){
		if(number % i == 0)
			sum += i;
	}
	return number == sum;
}

void PrintResults(int number) {
	if(isPerfectNumber(number))
		cout <<number<<" is perfect number"<<endl;

	else
		cout <<number<<" is not a perfect number"<<endl;
}

void PrintPerfectNumbersFrom1toN(int number) {
	for(int i = 1; i <= number; i++){
		if(isPerfectNumber(i))
			cout << i <<endl;
	}
}

int ReverseNumber(int number){
	int reminder = 0, number2 = 0;

	while(number > 0) {
		reminder = number % 10;
		number /= 10;
		number2 = number2 * 10 + reminder;
	}

	return number2;
}

bool IsPalindromeNumber(int number) {
	return number == ReverseNumber(number);
}

int CountDigitFrequency(int number, short DigitToCheck){
	int reminder = 0, counter = 0;

	while(number > 0) {
		reminder = number % 10;
		number /= 10;
		
		if(DigitToCheck == reminder)
			counter++;
	}
	return counter;
	
}

void PrintAllDigitFrequency(int number){
		cout <<endl;
		for(int i =0; i < 10; i++) {
			short DigitFrequency = CountDigitFrequency(number, i);
			if(DigitFrequency > 0){
			cout <<"\nDigit "<<i<<" frequency is "<<DigitFrequency<<" time(s).\n";
			}
		}
		cout <<endl;
		
}

int InvertedLetters(int number){
	if(number >= 65 && number <= 90)
		return number;
}

void PrintInvertedLetters(int number) {
	cout<<endl;
	for(int row = 65 + number - 1; row >= 65; row--) {
		for(int col = 1; col <= number - (65 + number - 1 - row); col++) {
			cout<<char(row);
		}
		cout<<endl;
	}
}

void PrintLetters(int number) {
	cout<<endl;
	for(int row = 65; row <=  65 + number - 1; row++) {
		for(int col = 1; col <= number - (65 + number - 1 - row); col++) {
			cout<<char(row);
		}
		cout<<endl;
	}
}

void PrintInvertedNumber(int number) {
	cout<<endl;
	for(int row = number; row >= 1; row--) {
		for(int col = 1; col <= row; col++) {
			cout<<row;
		}
		cout<<endl;
	}
}

void PrintAllWordsFromAAAToZZZ() {
		cout<<endl;
	string word = "";
	for(int i = 65; i <=  90; i++) {
		for(int j = 65; j <= 90; j++) {
			for(int k = 65 ;k <= 90; k++) {
			word = word + char(i);
			word = word + char(j);
			word = word + char(k);

			cout<< word <<endl;
			word = "";
			}
				
			cout<<endl;
		}
		
	}
}

string ReadLetter(string message) {
	string letter = "";
	cout <<message<<endl;
	cin >> letter;

	return letter;
}

bool GuessA3LettersPassword(string letter) {
		cout<<endl;
	string word = "";
	int counter = 0;
	for(int i = 65; i <=  90; i++) {
		for(int j = 65; j <= 90; j++) {
			for(int k = 65 ;k <= 90; k++) {
			counter++;
			word = word + char(i);
			word = word + char(j);
			word = word + char(k);
			
			cout<< "Trail ["<<counter<<"]: "<<word<<endl;
			
			if(word == letter) {
				cout <<"\nPassword is: "<<word<<"\n";
				cout <<"Found after: "<<counter<<" Trial(s)\n";
				return true;
			}
			word = "";
			
			}
				
			cout<<endl;
		}
		
	}
	return false;
}

string ReadText() {
	string Text;

	cout<<"Please, enter text: "<<endl;
	getline(cin, Text);

	return Text;
}

string EncryptText(string Text, short EncryptionKey) {
	for(int i =0; i <= Text.length(); i++) {
		Text[i] = char((int)Text[i] + EncryptionKey);
	}

	return Text;
}

string DecryptText(string Text, short EncryptionKey) {
	for(int i =0; i <= Text.length(); i++) {
		Text[i] = char((int)Text[i] - EncryptionKey);
	}

	return Text;
}

int RandomNumber(int From, int To) {
	int randNumber = rand() % (To - From + 1) + From;
	return randNumber;
}

char GetRandomCharacter(enCharType random) {
	switch (random)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
		break;
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;
	case enCharType::SpecialC:
		return char(RandomNumber(33, 47));
		break;
	case enCharType::Digit:
		return char(RandomNumber(48, 57));
		break;
	default:
		break;
	}
}

string GenerateWord(enCharType CharType, short Length) {
	string word = "";
	for(int i = 0; i < Length; i++) {
		word = word + GetRandomCharacter(CharType);
	}
	return word;
}

string GenerateKey() {
	string Key;
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void GenerateKeys (short numberOfKeys) {
	for(int i = 0; i < numberOfKeys; i++) {
		cout<<"Key ["<<i + 1<<"]: ";
		cout<<GenerateKey()<<endl;
	}
		
}

void ReadArray(int arr[100], int &arrLength) {
	cout<<"\nEnter number of elements: "<<endl;
	cin >> arrLength;

	cout<<"Enter array elements: "<<endl;
	for(int i = 0; i < arrLength; i++) {
		cout<<"Element ["<< i + 1<<"] : ";
		arr[i] = i;
	}
	cout <<endl;
}

void PrintArray(int arr[100], int arrLength) {
	for(int i = 0; i < arrLength; i++)
		cout << arr[i]<<" ";
	cout <<"\n";
}

void FillArrayWithRandomElements(int arr[100] , int &arrLength) {
	cout<<"\nEnter the length of array: "<<endl;
	cin >> arrLength;

	for(int i = 0; i < arrLength; i++) {
		arr[i] = RandomNumber(-100,100);
	}
}

int MaxOfRandomArrayElements(int arr[100], int arrLength) {
	int max = 0;

	for(int i = 0; i < arrLength; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int MinOfRandomArrayElements(int arr[100], int arrLength) {
	int min = arr[0];

	for(int i = 0; i < arrLength; i++) {
		if(arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int SumOfAllRandomNumbers(int arr[100], int arrLength) {
	int sum = 0;

	for(int i = 0; i < arrLength; i++) {
		sum += arr[i];
	}

	return sum;
}

float AverageOfAllRandomNumbers(int arr[100], int arrLength) {

	return (float) SumOfAllRandomNumbers(arr,arrLength) / arrLength; 
}

int TimesRepeated(int number, int arr[100], int arrLength) {
	int count = 0;

	for(int i = 0; i< arrLength; i++) {
		if(number == arr[i])
			count++;
	}
	return count;
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength) {
	for(int i =0; i < arrLength; i++) {
		arrDestination[i] = arrSource[i];
	}

}

//void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrLength2) {
//	int counter = 0;
//
//	for(int i =0; i < arrLength; i++) {
//		if(CheckPrime(arrSource[i]) == enPrimeNotPrime::Pirme) {
//			arrDestination[counter] = arrSource[i];
//			counter++;
//		}	
//	}
//	arrLength2 = --counter;
//}

void SumTwoArrays(int arr[100], int arr2[100], int arrSum[100] ,int arrLength)  {

	for(int i = 0; i < arrLength; i++) {
		arrSum[i] = arr[i] + arr2[i];
	}
}


void Swap(int &A, int &B) {
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

void ShuffleArray(int arr[100], int arrLength){
	
	for(int i = 0; i < arrLength; i++) {
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}

void FillArrayFrom1toN(int arr[100], int arrLength) {

	for(int i = 0; i < arrLength; i++) {
		arr[i] = i + 1;
	}
}

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength) {
	for(int i = 0; i < arrLength; i++) {
		arrDestination[i] = arrSource[arrLength - 1 - i];
	}
}

void FillArrayWithKeys(string arr[100], int arrLength) {
	for(int i = 0; i < arrLength; i++) {
		arr[i] = GenerateKey();
	}
}

void PrintStringArray(string arr[100], int arrLength) {
	cout<<"\nArray Elements: \n\n";

	for(int i = 0; i < arrLength; i++) {
		cout<<"Array["<< i<<"] : "<< arr[i]<<endl;
	}
	cout<<"\n";
}

void SearchNumberInArray(int arr[100], int arrLength) {
	int numberToSearchFor = ReadPositiveNumber("\nPlease enter a number to search for:  \n");
	int number = 0, position;
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] == numberToSearchFor) {
			number = arr[i];
			position = i;
			cout <<"Number you are looking for is: "<<numberToSearchFor<<endl;
			cout <<"The number found at position: "<<position<<endl;
			cout <<"The number found it's order: "<<position+1<<endl;
			return;
		}	
	}
	cout <<"The number is not found :( "<<endl;
	
}

short FindNumberPositionInArray(int number, int arr[100], int arrLength) {
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] == number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(short number, int arr[100], int arrLength) {
	return FindNumberPositionInArray(number, arr, arrLength) != -1;
}

void AddArrayElement(int number, int arr[100], int &arrLength) {
	arrLength++;
	arr[arrLength - 1] = number;
}

void InputUserNumbersInArray(int arr[100], int &arrLength) {
	bool AddMore = true;

	do {
		AddArrayElement(ReadNumber(), arr, arrLength);
		cout<<"Do you want to add more numbers? [0]:No, [1]:Yes? ";
		cin >> AddMore;

	} while (AddMore);
}

void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength) {
	for(int i =0; i < arrLength; i++) {
		
		AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
	}

}

void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength) {
	for(int i =0; i < arrLength; i++) {
		
		if(arrSource[i] % 2 != 0)
		AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
	}

}

//void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength) {
//	for(int i =0; i < arrLength; i++) {
//		
//		if(CheckPrime(arrSource[i]) == enPrimeNotPrime::Pirme)
//		AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
//	}
//
//}

void FillArray(int arr[100], int &arrLength) {
	arrLength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}

void CopyDistincitNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int & DestinationLength)  {
	for(int i = 0; i < SourceLength ; i++) {
		if(!IsNumberInArray(arrSource[i], arrDestination, DestinationLength)) {
			AddArrayElement(arrSource[i], arrDestination, DestinationLength);
		}
	}
}

bool IsPalindromeArray(int arr[100], int arrLength) {
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] != arr[arrLength - i - 1]) {
			return false;
		}
	}

	return true;
}


int CountEvenNumbersInArray(int arr[100], int arrLength) {
	int counter = 0;
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] % 2 == 0) {
			counter++;
		}
	}
	return counter;
}

int CountPositiveNumbersInArray(int arr[100], int arrLength) {
	int counter = 0;
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] >= 0) {
			counter++;
		}
	}

	return counter;
}

int CountNegativeNumbersInArray(int arr[100], int arrLength) {
	int counter = 0;
	for(int i = 0; i < arrLength; i++) {
		if(arr[i] < 0) {
			counter++;
		}
	}

	return counter;
}

float MyABS(float number) {
	if(number > 0) {
		return number;
	}
	return number * -1;
}

float GetFractionPart(float number) {
	return number - int(number);
}

int MyRound(float number) {
	int intPart;
	intPart = int(number);

	float fractionPart = GetFractionPart(number);

	if(abs(fractionPart) >= 0.5) {
		if(number > 0) 
			return ++intPart;
		else
			return --intPart;
	} else {
	return intPart;
	}

}

int MyFloor(float number) {
	if(number >= 0)
		return int(number);
	else
		return int(number) - 1;

}

int MyCeil(float number) {
	if(abs(GetFractionPart(number)) > 0) {
		if(number > 0)
			return int(number) + 1;
		else
			return int(number);
	} else {
		return number;
	}
		

}

float MySqrt(float number) {
	return pow(number, 0.5);
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
   
	int arrSource[100] , SourceLength = 0;
	float number;
	number = ReadNumber();
	//FillArrayWithRandomElements(arrSource, SourceLength);

	/*cout<<"Array Elements: \n";
	PrintArray(arrSource, SourceLength);*/

	cout<<"My sqrt result : \n";
	cout<<MySqrt(number)<<endl;

	cout<<"C++ sqrt result : \n";
	cout<<sqrt(number)<<endl;


	system("pause");
	return 0;
}

