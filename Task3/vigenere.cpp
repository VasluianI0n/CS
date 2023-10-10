#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;



string encryptText(string str, string key){
    string encrypted_text;
 
    for (int i = 0; i < str.size(); i++){
        if (!isalpha(str[i])) {
            return "Please write letters only from the alphabet";
        }
        char x = (str[i] + key[i]) %26;
        x += 'A';
        encrypted_text.push_back(x);
    }
    return encrypted_text;
}

string decryptText(string encrypted_text, string key){
    string decrypted_text;
    
    for (int i = 0 ; i < encrypted_text.size(); i++){
        if (!isalpha(encrypted_text[i])) {
            return "Please write letters only from the alphabet";
        }
        char x = (encrypted_text[i] - key[i] + 26) %26;
        x += 'A';
        decrypted_text.push_back(x);
    }
    return decrypted_text;
}

string generateKey(string str, string key){
    int x = str.size();
 
    for (int i = 0; ; i++){
        if (x == i){
            i = 0;
        }
        if (key.size() == str.size()){
            break;
        }
        key.push_back(key[i]);
    }
    return key;
}

int main(){
  char option;
  string response;
  string keyword;
  cout << "Choose what you want to do:\n [e] Encrypting\n [d] Decrypting\n" << endl;
  cin >> option;
 
  if(option == 'e'){
    cout << "Write the keyword to be used:" << endl;
    cin >> keyword;
    cout << "Write the string that you want to encrypt:" << endl;
    cin >> response;
    
    string key = generateKey(response, keyword);
    
    cout << encryptText(response, key) << endl;
  }    

  else if(option == 'd'){
    cout << "Write the keyword to be used:" << endl;
    cin >> keyword;
    cout << "Write the string that you want to decrypt:" << endl;
    cin >> response;
    
    
    string key = generateKey(response, keyword);
    
    cout << decryptText(response,key) << endl;
    
  }

}
  
