#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;
int KeepCounting();
string NumberConversion();
void Upc_Calculator();
void Upc_Check();
int Menu();

int main()
{
	Menu();
	system("pause");
	return 0;

}

int Menu()
{
	int choice = 0;
	do {
		cout << "FoPC4S Mini Applications\n ------------------ \n Please select an option: \n 1) Keep Counting Game \n 2) Number Conversion Tool \n 3) Universal Product Code Calculator \n 4) Universal Product Code Checker \n 5) Quit\n";
		cout << "Please enter option: \n";
		cin >> choice;
		// Menu system using switch and case statements
		switch (choice) {
		case 1:
			KeepCounting();
			break;
		case 2:
			NumberConversion();
			break;
		case 3:
			Upc_Calculator();
			break;
		case 4:
			Upc_Check();
			break;
		case 5:
			cout << "Exiting now.\n";
			break;
		}
	} while (choice != 5);
	return 0;
}

int KeepCounting()
{
	// Initialise random number generation.
	srand((int)time(NULL));
	srand(time(0));
	cout << "Keep Counting\n ---------- \n You will be presented with 8 addition questions. \n After the first question, the left-hand operand is the result of the previous addition \n Press enter to start...\n";
	int random_number_one = rand() % 9;
	int random_number_two = rand() % 9;
	int random_number_three = (rand() % 2) + 1;
	int answer_one;
	int number_of_correct_answers = 0;
	// Starting the clock, and storing the relevant data in a variable.
	clock_t start;
	double timetaken;
	start = clock();
	// Point of Divergence: random number generation determines whether we go into addition or subtraction.
	if (random_number_three == 1)
	{
		int correct_answer = random_number_one + random_number_two;
		cout << "Question 1: " << random_number_one << " + " << random_number_two << "\n";
		cin >> answer_one;
		// if the user gets q1 right, we enter the loop.
		if (answer_one == correct_answer)
		{
			cout << "Correct!\n";
			// Loop begins here, breaks if the user gets one wrong.
			for (int i = 2; i < 9; i++)
			{
				int random_number_two = rand() % 9;
				cout << "Question" << i << ": " << correct_answer << " + " << random_number_two << " .\n";
				cin >> random_number_one;
				correct_answer = correct_answer + random_number_two;
				// displays the correct answer to the user if they get a question wrong.
				if (random_number_one != correct_answer)
				{
					cout << "Correct answer was " << correct_answer << ". Unlucky!\n";
					break;
				}
				else {
					cout << "Correct!\n";
					number_of_correct_answers = number_of_correct_answers + 1;
				}
			}
		}
		// Handles what happens if the user gets them all right - the time taken is calculated in seconds from the raw data and outputted.
		if (number_of_correct_answers == 7)
		{
			timetaken = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Questions complete in " << timetaken << " seconds. \n";
		}
		// Displays the correct answer to the user if they get Q1 wrong.

	}
	else if (random_number_three == 2)
	{
		// Enter the subtraction loop.
		int correct_answer = random_number_one - random_number_two;
		cout << "Question 1: " << random_number_one << " - " << random_number_two << "\n";
		cin >> answer_one;
		// If the answer to Q1 is correct, we enter the for loop.
		if (answer_one = correct_answer)
		{
			cout << "Correct!\n";
			// Again the for loop will cover the rest of the 8 questions, until the user either gets them all correct or gets one wrong.
			for (int i = 2; i < 9; i++)
			{
				int random_number_two = rand() % 9;
				cout << "Question" << i << ": " << correct_answer << " - " << random_number_two << " .\n";
				cin >> random_number_one;
				correct_answer = correct_answer - random_number_two;
				if (random_number_one != correct_answer)
				{
					cout << "Correct answer was " << correct_answer << ". Unlucky!\n";
					break;
				}
				else {
					cout << "Correct!\n";
					number_of_correct_answers = number_of_correct_answers + 1;
				}
			}
		}
		// Time output: calculated in seconds from raw data from earlier.
		if (number_of_correct_answers == 7)
		{
			timetaken = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Questions complete in " << timetaken << " seconds. \n";
		}


	}

	return 0;
}

string NumberConversion()
{
	// ESTABLISH INITIAL VALUES
	int denary_number = 0;
	int hex_int = 0;
	int x = 0;
	string hex_number = "";
	char hex_values[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	string binary_number = "";
	cout << "Number Conversion Tool \n Please choose which base you want to input.\n 1) Positive Decimal \n 2) Hexadecimal \n 3) Binary ";
	int base_choice = 0;
	cin >> base_choice;
	// CHOICE OF BASE
	switch (base_choice) {
	case 1:
	{
		cout << "Please input a positive decimal number.";
		cin >> denary_number;
		// COPY OF DENARY INPUT
		int denary_number_2 = denary_number;
		// HEX CALCULATION
		while (denary_number > 0)
		{
			x = denary_number % 16;
			hex_number = hex_values[x] + hex_number;
			denary_number = denary_number / 16;
		}
		int remainder = 0;
		int binary[32];
		int i = 0;
		// BINARY CALCULATION
		while (denary_number_2 != 0)
		{
			binary[i] = denary_number_2 % 2;
			denary_number_2 = denary_number_2 / 2;
			i++;

		}
		cout << "Binary: \n";
		// BINARY AND HEX OUTPUT
		for (int j = i - 1; j >= 0; j--)
		{
			cout << binary[j];
		}
		cout << "\n";
		cout << "Hex: " << hex_number << ".\n";
		break;
	}
	case 2:
	{
		cout << "Please input a Hexadecimal number.\n";
		char hex_input[20];
		int i, r, len, decimal = 0;
		cout << "Enter a hexadecimal number : ";
		cin >> hex_input;
		// Length of the inputted hexadecimal value.
		len = strlen(hex_input);
		// Use of ASCII numerical values to convert from hex, writing to the value DECIMAL for the decimal equivalent.
		for (i = 0; hex_input[i] != '\0'; i++)
		{
			len--;
			if (hex_input[i] >= '0' && hex_input[i] <= '9')
				r = hex_input[i] - 48;
			else if (hex_input[i] >= 'a' && hex_input[i] <= 'f')
				r = hex_input[i] - 87;
			else if (hex_input[i] >= 'A' && hex_input[i] <= 'F')
				r = hex_input[i] - 55;
			decimal += r * pow(16, len);
		}
		cout  << hex_input << "'s decimal equivalent is " << decimal << " .\n";
		int binary_value[32];
		int y = 0;
		// calculating the binary using the calculated hex-equivalent value.
		while (decimal != 0)
		{
			binary_value[y] = decimal % 2;
			decimal = decimal / 2;
			y++;
		}
		cout << hex_input << "'s binary equivalent is: ";
		// outputting the binary value.
		for (int j = y - 1; j >= 0; j--)
		{
			cout << ""<<binary_value[j]<<"";
		}
		cout << "\n";
		break;
	}
	case 3:
		int number_value, remainder_value, decimal_value, number_input, i;
		char hex_values[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
		int X = 0;
		cout << "Enter a binary number : \n";
		cin >> number_input;
		string hex_number = "";
		decimal_value = 0;
		i = 0;
		// Binary to decimal, working backwards to calculate. 
		while (number_input != 0)
		{
			remainder_value = number_input % 10;
			number_input /= 10;
			decimal_value += remainder_value * pow(2, i);
			++i;
		}
		cout << "Decimal number is: " << decimal_value << " .\n";
		// Hex from the binary-equivalent decimal.
		while (decimal_value > 0)
		{
			X = decimal_value % 16;
			hex_number = hex_values[X] + hex_number;
			decimal_value = decimal_value / 16;
		}
		cout << "Hex: " << hex_number << ".\n";
	}
	return hex_number;
}
void Upc_Calculator()
{
	int original_number;
	int check_digit = 0;
	int original_number_array[7];
	// TEST DATA used: 567567. Expected UPC: 8.
	cout << "Universal Product Code (UPC) calculator\n -------------------------------------- \nThis calculator will take a 6 - digit product code \n and generate a trailing 7th check digit to produce \n the final 7 - digit UPC. \n Please enter 6 - digit code to generate final UPC code : \n";
	cin >> original_number;
	string original_number_s = to_string(original_number);
	if (original_number > 999999 || original_number<=0)
	{
		cout << "Invalid number.";
	}
	else
	{
		cout << "Calculating your UPC. \n ";
		int digit_collection[7];
		int remainder;
		size_t n = sizeof(digit_collection) / sizeof(digit_collection[0]);
		// UPC Calculation loop.
		for (size_t i = 0; i < n ; i++)
		{
			remainder = original_number % 10;
			original_number = original_number / 10;
			digit_collection[i] = remainder;
		}
		// Calculating the Check Digit.
		int odds_total, rem;
		odds_total = digit_collection[0] + digit_collection[2] + digit_collection[4];
		odds_total = odds_total * 3;
		odds_total = odds_total + (digit_collection[1] + digit_collection[3] + digit_collection[5]);
		rem = odds_total % 10;
		if (rem == 0)
		{
			check_digit = 0;
		}
		else if (rem > 0)
		{
			check_digit = 10 - rem;
			// moving bits around in the array to correctly append the check digit.
			const int COPY1 = digit_collection[0];
			const int COPY2 = digit_collection[1];
			const int COPY3 = digit_collection[2]; 
			const int COPY4 = digit_collection[3]; 
			const int COPY5 = digit_collection[4];
			const int COPY6 = digit_collection[5]; 
			const int COPY7 = digit_collection[6];
			digit_collection[6] = check_digit;
			const int COPY8 = digit_collection[6];
			digit_collection[6] = COPY6, digit_collection[5] = COPY5, digit_collection[4] = COPY4, digit_collection[3] = COPY3, digit_collection[2] = COPY2, digit_collection[1] = COPY1, digit_collection[0] = COPY8;
		}
		cout << "The 7 digit final UPC is: ";
		// Tested with test data 567567, this returned 5675678 as expected.
		for (size_t i = 7; i--;)
		{
			cout << "" << digit_collection[i] << "";
		}
		cout << "\n";
	}
}
void Upc_Check()
{
	cout << "Universal Product Code (UPC) Checker \n ------------------------------------ \n Please enter 7 - digit UPC to check : \n ";
	// Initial values.
	int upc_value; 
	cin >> upc_value;
	int upc_value_array[7];
	int upc_remainder;
	// Calculating array size to iterate through, using size_t to avoid overflow errors.
	size_t n = sizeof(upc_value_array) / sizeof(upc_value_array[0]);
	for (size_t i = 0; i < n; i++)
	{
		upc_remainder = upc_value % 10;
		upc_value = upc_value / 10;
		upc_value_array[i] = upc_remainder;
	}
	// Check digit calculation
	int valid_check_digit;
	int total_of_odds, rem_upc;
	total_of_odds = upc_value_array[0] + upc_value_array[2] + upc_value_array[4];
	total_of_odds = total_of_odds * 3;
	total_of_odds = total_of_odds + (upc_value_array[1] + upc_value_array[3] + upc_value_array[5]);
	rem_upc = total_of_odds % 10;
	// Handling the situation when the check digit should be 0.
	if (rem_upc == 0)
	{
		valid_check_digit = 0;
		if (valid_check_digit = upc_value_array[0])
		{
			cout << "The UPC is valid.\n";
		}
		else {
			cout << "The UPC is not valid.\n";
		}

	}
	// Handling the situation when the check digit is not 0.
	else if (rem_upc > 0)
	{
		valid_check_digit = 10 - rem_upc;
		if (valid_check_digit = upc_value_array[0])
		{
			cout << "The UPC is valid.\n";
		}
		else {
			cout << "The UPC is not valid.\n";
		}
	}
}