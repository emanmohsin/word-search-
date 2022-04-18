
#include <iostream>
#include <conio.h>
#include <fstream>


#include <cstring>
#include <windows.h>
#include <string>
using namespace std;


int check(string em[]) { //function to find longest string
//function to fund word occcurance or to place it in an board
	int ooc, ncheck;
	for (int i = 0; i < 8; i++) //incrementing the loop
	// checking loop
	{
		ooc = em[0].length();//finding occurance
		if (em[i].length() < em[i + 1].length())
		//incrementing lgth
		 {
			ncheck = em[i + 1].length();
		}
		if (ncheck > ooc)
		//incrementing condition
		
		 {
			ooc = ncheck;
		}
	}
	return ooc;
}
void read(string str[]) { //file read function reading from file 
	ifstream fin;
	fin.open("input.txt");//opening input
	string word;
	int a= 0;
	while (!fin.eof()) {
		getline(fin, word,'\n');//taking words
		str[a] = word;
		fin >> str[a];
		a++;
	}
	fin.close();
	cout<<"PROVIDED WORDS ARE:"<<endl;
	for(int j=0; j<a; j++) {
		cout<<str[j]<<endl;
	}
}


void Gdo(int l, string opa[]) 
// game function board printing work
{
	char board[l][l];//decalaration
	int a;
	char b;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			a = rand() % 26;//generates random number between 0 and 26
			b= 'a' + a;//add the random number generated above 'r' into the ASCII value of 'a'
			board[i][j] = b;//board initializer
		}
	}
	int t=0;
	int s=0;
	for (int index = 0; index < 7; index++) {

		if (opa[index].length() == l||t==0) {
			// put word diagonally
			int row = 0;
			int col = 0;
			for (int i = 0; opa[index][i] != '\0'; i++, row++, col++) {
				board[row][col] = opa[index][i];
			}
			t++;
		} else if (opa[index].length() % 2 == 0) {
			// put word horizontally front hori and back hori
			int row = rand() % l;//randomiizing
			int col = (rand() % 3)+4;//randomizing col
			if(t==1)//decl
				row--;//decre
			else if(t==2)
				row++;//inr conditoon
			for (int i = 0; opa[index][i] != '\0'; i++, col++) {
				board[row][col] = opa[index][i];//assign
			}
			t++;//increment
		} else {
			int row=(rand()%4)+1;//using rand to sort 
			int col=rand()%5;//modulus operator
			if(s==0)
				col++;//incrementing columns
			for (int i = 0,j=index; opa[index][i] != '\0'; i++, row++) 
			// declaring board to third variable 
			{
				board[row][col] = opa[index][i];//assignemt
			}
			s++;
		}
	}
	ofstream fout("output.txt");//putting the board in an output.txt file
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			fout << board[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
int main() {
	int l = 0;//declarationm
	string em[7];//string
	read(em);//to read the input file given by the user
	l = check(em);//to check if any word is longer than the standard size of the matrix
	if (l < 10)//con
	//condition
	 {
		l = 10;
	}
	Gdo(l, em);//function called for initializing the word puzzle
	cout<<"The words are stored in file output.txt"<<endl;//that the work
	system("pause");
	return 0;
}
