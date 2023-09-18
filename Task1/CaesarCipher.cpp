// Example program
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

string getString(char x){
    
    string s(1,x);
    return s;
    
}

string removeDuplicate(string str)
{
    
   string result = getString(str[0]);
   bool isDuplicate = false;
   
  for(int i = 1; i < str.length(); i++){
      for(int j = 0; j < result.length(); j++){
          if(str[i] == result[j]){
            isDuplicate = true;
          }
      }
      if(!isDuplicate){
          result+=getString(str[i]);
      }else{
       isDuplicate = false;   
      }
  }
   return result;
}

int main()
{
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string cipher2 = alphabet;
  string response, result, key2;
  char option;
  int key;
  cout << "Choose what you want to do:\n [e] Encrypting\n [d] Decrypting\n [m] 2 keys\n [n] Decrypt 2 keys" << endl;
  cin >> option;
  cout << "Write the string that you want to encrypt/decrypt:" << endl;
  cin >> response;
  cout << "Write the key to be used:" << endl;
  cin >> key;
  
  result = response;
  
  if(option == 'e'){
  
    for(int i = 0; i < alphabet.length(); i++){
      for(int j = 0; j < result.length(); j++){
          if(alphabet[i] == response[j]){
              result[j] = alphabet[(i+key)%26];    
              }
          else if(alphabet[i] == tolower(response[j])){
              result[j] = toupper(alphabet[(i+key)%26]); 
          }
      }
  }    

  }else if(option == 'd'){
   
  
    for(int i = 0; i < alphabet.length(); i++){
      for(int j = 0; j < result.length(); j++){
          if(alphabet[i] == response[j]){
              result[j] = alphabet[abs((26+i-key)%26)];  
          }else if(alphabet[i] == tolower(response[j])){
              result[j] = toupper(alphabet[abs((26+i-key)%26)]);
          }
      }
  }

  
  }else if(option == 'm'){
      cout << "Write the 2nd key:" << endl;
      cin >> key2;
     
      string united = key2+cipher2;
      cipher2 = removeDuplicate(united);
      
      cout << "The unmoved alphabet is:" << cipher2 << endl;
      
        for(int i = 0; i < alphabet.length(); i++){
      for(int j = 0; j < result.length(); j++){
          if(alphabet[i] == response[j]){
              result[j] = cipher2[(i+key)%26];    
              }
          else if(alphabet[i] == tolower(response[j])){
              result[j] = toupper(cipher2[(i+key)%26]); 
          }
      }
  }   
      
      
  }else if(option == 'n'){
       cout << "Write the 2nd key:" << endl;
      cin >> key2;
     
      string united = key2+cipher2;
      cipher2 = removeDuplicate(united);
      
      cout << "The unmoved alphabet is:" << cipher2 << endl;
  
  for(int i = 0; i < cipher2.length(); i++){
      for(int j = 0; j < result.length(); j++){
          if(cipher2[i] == response[j]){
              result[j] = alphabet[abs((26+i-key)%26)];  
          }else if(cipher2[i] == tolower(response[j])){
              result[j] = toupper(alphabet[abs((26+i-key)%26)]);
          }
      }
  }
  
  
  
  }
  
  
  
  
  cout << result << endl;
}

