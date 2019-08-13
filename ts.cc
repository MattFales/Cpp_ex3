//--------------------------Includes---------------------------
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <vector>
//-------------------------------------------------------------
using namespace std;
//-------------------------------------------------------------
int start_s=clock(); // global var they need to be seen 
string global=""; // global varible
string current="";
int linefile=0;
bool flag = true;


//==============================================================
void failed(){
	cout << "----------------------------"<< '\n';
	cout << "Line of File: " << linefile << '\n';
	cout << "Input: " << current << '\n';
	cout << "Invalid" << '\n';  // if so print out invalid
	int stop_s=clock();
	cout << "Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << '\n';
	current="";
	global="";
	flag = false;
	//exit(1); // exit right away after displayed the invalid	
}
void pass(){
	global="";   // global is done so nothing left not need but keeps morel ogic going
	cout << "----------------------------"<< '\n';
	cout << "Line of File:  " << linefile << '\n';
	cout << "Input: " << current << '\n';
        cout << "Valid" <<'\n';  // Print valid
        int stop_s=clock();
        cout << "Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << '\n';
	current="";
	//flag =true;
	//exit(1);  // exit right away after displayed the valid just die and exit
}
string check(string st){
//-----------------------------------------------------------------------------------------------------------
//------------------if it starts with ) } ] are illegal cases------------------------------------------------
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;
int count6=0;
int odd=0;  	  // for the ocunt of of size of string to check if it is an odd number
for (unsigned int l=0; l <st.size(); l++) {
	char nst1=st[0]; // check first charcter i nthe string
		
		if(nst1 == ')' ){
			failed();
		return st;	
		}
		if(nst1 == ']' ){ 
			failed();
		return st;
		}
		if(nst1 == '}' ){ 
			failed();
		return st;
		}
		
	
	}// end of for loop
	for(unsigned int i =0; i < st.size(); i++){
	odd++;          // keeps count of string
		if(st[i]=='('){
		count1+=1;	
		}
		if(st[i]=='{'){
		count2+=1;
		}
		if(st[i]=='['){
		count3+=1;	
		}
		if(st[i]==')'){
		count4+=1;	
		}
		if(st[i]=='}'){
		count5+=1;	
		}
		if(st[i]==']'){
		count6+=1;	
		}


	}
	//cout << "c1" << count1 <<'\n';
	//cout << "c2" << count2 <<'\n';
	//cout << "c3" << count3 <<'\n';
	//cout << "c4" << count4 <<'\n';
	//cout << "c5" << count5 <<'\n';
	//cout << "c6" << count6 <<'\n';
	//cout << "st: " << st << '\n';
	if (odd%2==1){                      // mod it see if it is odd
		failed();
		return st;
	}

	if (count1 !=count4){
	failed();
	return st;
	}
	if (count2 !=count5){
	failed();
	return st;
	}
	if(count3 !=count6){
	failed();
	return st;
	}
	


return st;
}
string encode(string st){
//-------------------------------------Encodes it in number 1-6-------------------------------------------------
// Not needed but i thought it was easier to deal with adn debug if i saw a string of numbers

global="";
	for (unsigned int i=0; i <st.size(); i++){
	
	char nst=st[i]; // gets the each charcer at i to start it encode
	char ch= '(';   // get mapped to 1
	char ch1='{';   // get mapped to 2
	char ch2='[';   // get mapped to 3
	char ch3=')';   // get mapped to 4
	char ch4='}';   // get mapped to 5
	char ch5=']';   // get mapped to 6
		if(nst == ch ){       // check if mapped (
			global+="1";  // change it to a 1 as building new string
		}
		if(nst == ch1 ){     // check if mapped {
			global+="2"; // change it to a 2 as building new string
		}
		if(nst == ch2 ){     // check if mapped [
			global+="3"; // change it to a 3 as building new string
		}
//---------------closing ones--------------------------------------------------
		if(nst == ch3 ){     // check if mapped )
			global+="4"; // change it to a 4 as building new string
		}
		if(nst == ch4 ){     // check if mapped }
			global+="5"; // change it to a 5 as building new string
		}
		if(nst == ch5 ){     // check if mapped ]
			global+="6"; // change it to a 6 as building new string
		}
	}// end of for loop
//--------------------------------------------------------------------------------------------------------------
//-----------if there odd number of characters this invalid everything has to be paired-------------------------
	
return global;
}
string valid(string global){
//-------------------------------------------------------------------------------------------------------------
// This i meant to scan every two characters and find the valid pair it will delete when it find it
// it keeps doing this until everything has been deleted
// for invalid cases  it will loop forever but after a 1000 times in the loop it fails means it is probably invalid
unsigned int gsize = 1; // need it to be able to enter the loop
char tmp0; 
char tmp1;
int count=0;
unsigned int sizeG=0;

	while (gsize > 0) { // this loops until sting is being tested if valid
	
//cout << "size " << global.size()  << " " << global<< '\n';
		sizeG = global.size();
	if (sizeG==0){
			return global;
	}





		//cout  << "golbal: " << global << '\n';
		for (unsigned int j=0; j < global.size(); j++){  // loops through  and will work to group first character
		count++;	// this is keep track how many this goes through assume over 1000 it is invalid so i fail it at that point also takes almost no more time to run this check
			for (unsigned int k =j+1; k < global.size(); k++){ // Will always be ahead of so this allow every two characters 
				tmp0 = global[j]; // grabs char 1
				tmp1 = global[k]; // grabs char 2 just keep going down the string each interation 
				if (tmp0 == '1' ) {  // check if this valid
					if (tmp1 == '4'){ // check if 1 and 4 this is valid
						if(global.size()==2){ //when size of this is 2 means just two are left ost now this valid case
							pass();
							return global;
						}	
					global.erase(global.begin()+j);   // will always be the one with the next char erase if 1 valid
					global.erase(global.begin()+k-1); // offset minus keeps in getting every to chars erase if 4 valid
					}
				}
				if (tmp0 == '2' ) {// check if this valid
					if (tmp1 == '5'){ // check if 2 and 5 this is valid
						if(global.size()==2){
							
							pass();
							return global;
						}
					global.erase(global.begin()+j); // will always be the one with the next char also erase if 2 valid
					global.erase(global.begin()+k-1);// offset minus keeps in getting every to chars if 5 valid
					}
				}
				if (tmp0 == '3' ) {// check if this valid
					if (tmp1 == '6'){ // check if 3 and 6 this is valid
						if(global.size()==2){
							pass();
							return global;
						}
					global.erase(global.begin()+j); // will always be the one with the next char this also erase if 3  valid
					global.erase(global.begin()+k-1);// offset minus keeps in getting every to chars  also erase if 6 valid
					}
				}
			//cout << "test before: " <<global << '\n';
			//cout << "test " << '\n'; 
				if ((tmp0 == '1' ) &&  (tmp1 == '5')){ // cases like (}
					failed();
//cout << "test1" << '\n';
				return global;
				}
				if ((tmp0 == '1' ) &&  (tmp1 == '6')){ // cases like (]
					failed();
//cout << "test1" << '\n';
				return global;
				}
				if ((tmp0 == '2' ) &&  (tmp1 == '4')){ // cases like {)
					failed();
//cout << "test2" << '\n';
				return global;
				}
				if ((tmp0 == '2' ) &&  (tmp1 == '6')){ // cases like {]
					failed();
//cout << "test3" << '\n';
				return global;
				}
				if ((tmp0 == '3' ) &&  (tmp1 == '4')){ // cases like {)
					failed();
//cout << "test4" << '\n';
				return global;
				}
				if ((tmp0 == '3' ) &&  (tmp1 == '5')){ // cases like (}
					failed();
//cout << "test5" << '\n';
				return global;
				}
		
		j++; // main increment 
			}


	}
	if(sizeG == global.size() ){
		//failed();
		//cout << "hi" << '\n';
		global="";
		current="";
		return global;
		}

//cout << "hi" << '\n';

	//if (count == 10){  // if this has loop 1000 times you either have insane legal sting or most likely invalid and it cant handle cause no more valid cases
	//	failed();
	
	//cout << "test" <<   count<<'\n';
	//break;
	//}
	gsize= global.size();
//	if (gsize==global.size()){
	//	return global;


	//}
	//cout << "gsize" << gsize << '\n';
	}

return global;
}



//=================================================================================================
int main(int argc, char *argv[]) {
//cout << "You have put in " << argc << " arguments" << '\n';  // if i use -Wno-unused-parameter stops from complain if im not using it
//---------------------------------error check----------------------------------------
	//if((argc >2) || (argc <2)){ // it has to be 2 so fail if it is not
	//	cout << "You have put in " << argc << "arguments you need to ahve 2 arguments the program name and the part you want evaluated make sure it is '' like '({[]})'" << '\n';
	//	failed();
	//}
string str= argv[1];
fstream read;
read.open(str);
string s;
vector<string> vec;

while(getline(read,s)){
	vec.push_back(s);
}
read.close();


for(unsigned int i =0; i < vec.size(); i++){
//cout << vec[i]<< '\n';
	flag=true;
	linefile=i;
	string st= vec[i];    // gets what is in index 1 of argv 
	current=vec[i];


	check(st);     // Call for check
	
	//cout << "hi im here" << st.size() << '\n';
	if (flag==true){
	encode(st);    // passes string in
	//cout << "gl " << global << '\n';
	valid(global); // call to check if it is valid	


}
	
}






    return 0;
}