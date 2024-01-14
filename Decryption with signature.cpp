using namespace std;
using ll = long long;
#include <bits/stdc++.h>
#include <iostream>

ll Pow_mod ( ll a , ll b, ll n ) {  
    ll power = 1 , i ;  
    for ( i = 1 ; i <= b ; i++) {  
        power = power * a ;
        power = power % n; 
    }  
    return power ;  
} 

/* The function above is used to raise the numeric value of the characters in the message to the power of b, which in the program will be the n not this n above. 

Why I used the mod after every power? That is because C++ is a limited langauge when it comes to deal with the large number. So this helps to lower the value of numbers, with taking into consideration that the value after raised to the power (mod n) = the value raised to power then taking mod and so on.... */

int main() {
    int reverse_sign, reverse, temp, tempss;
   ll n,coprime_numbers_with_n = 0, e, d, encrypted_code_letter, decrypted_code_letter, signuature_code_letter; 
   string encrypted_message, message, signuature,signuature_decoded ; 
   vector<ll>  encrypted_messages_vec, signuature_vec; 
   vector<int>  decrypted_codes_vec, signuature_codes_vec; 
   vector<int> decrypted_messages_vec,signuature_message_vec ;
   
   
   /* What does each variable mean? 
   1. reverse_sign is used in the signuature to store the numeric of each char in the signature to make it stored in signuature_message_vec. 
   2. reverse is used for the same purpose but with the message
   3. temp is 
   
   */
   
   cout << "Please enter n value (from the public key)" << endl;
   cin >>  n; 
   
   cout << "Please enter e value (from the public key)" << endl;
   cin >>  e; 
   
    cout << "Please enter the signuature encoded message with the spaces" << endl;
    cin.ignore();
   getline(cin,signuature);

    stringstream ss(signuature);
    
    while (ss >> tempss) {
        signuature_vec.push_back(tempss);
        ss.ignore();
    }
   
   
   for(ll i = 1; i <n;i++){
       if(__gcd(i,n) == 1){
               coprime_numbers_with_n++;
       }
   }
   cout << "Please enter the encoded message with the spaces" << endl; 
   getline(cin,encrypted_message);

  stringstream ee(encrypted_message);
  
    while (ee >> temp) {
        encrypted_messages_vec.push_back(temp);
        ee.ignore();
    }
    
    for(ll i = 2; i <coprime_numbers_with_n; i++){
        if( ((i*e) % coprime_numbers_with_n == 1) ){
            d = i;
            break;
        }
    }
    
    
    /*Start signuature validation part*/
     for (int i = 0; i < signuature_vec.size(); i++){
        signuature_code_letter = Pow_mod(signuature_vec[i], e, n);
        signuature_codes_vec.push_back(signuature_code_letter);
    }
    
     for(int i = 0; i < signuature_codes_vec.size();i++){
            reverse_sign = signuature_codes_vec[i];
            signuature_message_vec.push_back(reverse_sign);
    }
    
    for(int i = 0; i < signuature_message_vec.size();i++){
         signuature_decoded += char (signuature_message_vec[i]);
    }
    
    cout << "The signature is that: " <<signuature_decoded << endl;
    
    
    /*End signuature validation part*/

     /* Start Decryption  Section for the message*/
    for (int i = 0; i < encrypted_messages_vec.size(); i++){
        decrypted_code_letter = Pow_mod(encrypted_messages_vec[i], d, n);
        decrypted_codes_vec.push_back(decrypted_code_letter);
    }
    
     for(int i = 0; i < decrypted_codes_vec.size();i++){
            reverse = decrypted_codes_vec[i];
            decrypted_messages_vec.push_back(reverse);
    }
    
    for(int i = 0; i < decrypted_messages_vec.size();i++){
         message += char (decrypted_messages_vec[i]);
    }
    cout << "The message is that " << message << endl;
    
    
    if(message == signuature_decoded){
        cout << "This message is authentic" << endl;
    }
    else {
        cout << "Someone is trying to hack or interfere your system" << endl;
    }
      
  /*End Decryption  Section*/

}