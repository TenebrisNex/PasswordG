#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;


int start(){
  cout << "Whta type of password would you like?" << endl;
  cout << "1 - Random generated password" << endl;
  cout << "2 - Easy to remember password" << endl;
  cout << "3 - A mix of both" << endl;
  cout << "Please choose option 1, 2, or 3" << endl;
  

  int option = 0;

  cin >> option;

  if(option != 1 && option != 2 && option != 3){
    cout << "Invalid, please choose option 1, 2, or 3" << endl;
    return start();

  }else{
    return option;
  }

}

int lP(){
  cout << "How long would you like your password ?" << endl;
  cout << "1 - (10 characters)" << endl;
  cout << "2 - (20 characters)" << endl;
  int l = 0;

  cin >> l;
  if(l != 1 && l != 2){
    cout << "Please enter a valid choice 1 or 2." << endl;
    return lP();

  }else{
    return l;
  }

}

char generateRandomCharacter() {

  srand(static_cast<unsigned int>(time(0)));
  int type = rand() % 3;

  if(type == 0){
    return 'a' + rand() % 26;
  }else if(type == 1){
    return 'A' + rand() % 26;
  }else{
    return '0' + rand() % 10;
  }
}

int generateRandomNumber(int min, int max){
  return min + rand() % (max - min + 1);

}


string createPassword(int type , int size){

  string newPassword(size, ' ');

  if(type == 1){
    for(int i = 0; i < size; i++){
      newPassword[i] = generateRandomCharacter();
      
    }
    return newPassword;

  }else if(type == 2){
    cout << "What is your first name?" << endl;
    string name;
    cin >> name;
    int currs = 0;

    for(int i = 0; i < name.size() && currs < size; i++){
      newPassword[currs++] = name[i];
    }

    if(currs < size){
      cout << "Pick two numbers (a min and a max)" << endl;
      int min, max;
      cin >> min >> max;

      for(int i = currs; i < size; i++){
        int s = generateRandomNumber(min, max);
        newPassword[i] = to_string(s)[0];
      }
    }
    return newPassword;

   

    
  }else if(type == 3){

    cout << "What is your name ?" << endl;
    string name ;
    cin >> name;
    int currs = 0;

    for(int i = 0; i < name.size() && currs < size / 2; i++){
      newPassword[currs++] = name[i];
    }


    cout << "Pick two numbers (a min and a max)" << endl;
    int min, max;
    cin >> min, max;

    for(int i = currs; i < size; i++){
      int s = generateRandomNumber(min, max);
      newPassword[i] = to_string(s)[0];
    }

    return newPassword;




  }
  
  return "";  
  
}



int main(){
  srand(static_cast<unsigned int>(time(0)));
  int option = start();
  int length = lP();

  string password = createPassword(option, length);
    
  cout << "Your generated password is: " << password << endl;

  return 0;
}
