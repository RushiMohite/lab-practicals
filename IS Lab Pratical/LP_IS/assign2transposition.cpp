#include<bits/stdc++.h>

using namespace std;

string removeSpace(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str;
}

string encrypt (string message, int cols)
{
	message = removeSpace(message);
	
	int rows = message.length() / cols;
    
    char arr[rows][cols];
    
    int m = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m < message.length()) {
                arr[i][j] = message[m++];
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

  string ciphertext = "";
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            ciphertext += arr[i][j];
        }
    }
    
    return ciphertext;
}

string decrypt (string ciphertext, int cols)
{
	ciphertext = removeSpace(ciphertext);
	
	int rows = ciphertext.length() / cols;
	
	char arr[rows][cols];
	
	int m = 0;
	for (int j = 0; j < cols; j++){
		for (int i = 0; i < rows; i++){
			if ( m < ciphertext.length()){
				arr[i][j] = ciphertext[m++];
				
			}
			else
			{
				arr[i][j] = ' ';
			}
		}
	}
	
	string message = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            message += arr[i][j];
        }
    }
    
    return message;
}

int main()
{
	string message, ciphertext , decrypted;
	int cols;
	
	cout<< "Enter a message to encrypt: ";
	getline(cin, message);
	
	cout<< " Enter the number of columns: ";
	cin>>cols;
	
	ciphertext = encrypt(message, cols);
	cout<<"Encrypted message :"<<ciphertext<< endl;

    decrypted = decrypt(ciphertext, cols);
    cout<<"Decrypted message:"<<decrypted<< endl;

    return 0;
}
