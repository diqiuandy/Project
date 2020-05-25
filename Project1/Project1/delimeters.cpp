#include <iostream>
#include <cassert>
#include "project_1.hpp"
// Function declarations
int main();     //this creates the main function
void print_program();
bool does_delimiter_match( char del );
bool do_delimiters_nest();
// Function definitions
int main() {

print_program();

std::cout << does_delimiter_match( '(' ) << std::endl;      //using the created functions inside the main function.

std::cout << does_delimiter_match( '[' ) << std::endl;

std::cout << does_delimiter_match( '{' ) << std::endl;

std::cout << do_delimiters_nest() << std::endl;

return 0;
}

void print_program(){
ece150::start_reading_file();
while(ece150::at_eof()!=true){      //if not reaching the end of the file, do the following
    std::cout << ece150::get_next_character();      //print out the next character
    }
}
bool does_delimiter_match(char del){
    ece150::start_reading_file();
    int open{0};
    char next;
    if(del == '('){     //if del is (, meaning to check ('s status
        int counter1{0};
        while(ece150::at_eof()!=true){
            next=ece150::get_next_character();
            if(next == '('){        //find the number of (
                open = open+1;
            }
            else if(next ==')'){    //if it is closed, there is a match, depending on the number of the opening (
                if(open-1 < 0 ){
                    std::cout<<"Unmatched )"<<std::endl;    //not a match, it results a unmatched of )
                    counter1++;
                }
                else{
                    open = open-1;      // a match
                }
            }
       }
       if(open!=0){             //if there are still opening, meaning too many open (, it results a missing
        std::cout<<"Missing ";
        counter1++;
        while(open!=0){
        if(open == 1){
            std::cout<<")"<<std::endl;
        open--;
        }
        else{
        std::cout<<")";     //to print in separate line for the bool.
        open--;
       }
       }
       return false;
       }
       else if(counter1!=0){
        return false;
       }
       else{
        return true;
       }
       }
       else if(del == '{'){                        //important; The above comments apply to the following else if, just the changing of sign.
        int counter2{0};
        while(ece150::at_eof()!=true){
            next=ece150::get_next_character();
            if(next == '{'){
                open = open+1;
            }
            else if(next =='}'){
                if(open-1 < 0 ){
                    std::cout<<"Unmatched }"<<std::endl;
                    counter2++;
                }
                else{
                    open = open-1;
                }
            }
       }
       if(open!=0){
        std::cout<<"Missing ";
        while(open!=0){
        if(open == 1){
        std::cout<<"}"<<std::endl;
        open--;
        }
        else{
        std::cout<<"}";
        open--;
        }
       }
       return false;
       }
       else if(counter2!=0){
        return false;
       }
       else{
        return true;
       }
       }
       else if(del == '['){
        int counter3{0};
        while(ece150::at_eof()!=true){
            next=ece150::get_next_character();
            if(next == '['){
                open = open+1;
            }
            else if(next ==']'){
                if(open-1 < 0 ){
                    std::cout<<"Unmatched ]"<<std::endl;
                    counter3++;
                }
                else{
                    open = open-1;
                }
            }
       }
       if(open!=0){
        std::cout<<"Missing ";
        while(open!=0){
        if(open == 1 ){
        std::cout<<"]"<<std::endl;
        open--;
        }
        else{
            std::cout<<"]";
        open--;
        }
       }
       return false;
       }
       else if(counter3!=0){
        return false;
       }
       else{
        return true;
       }
       }
       else{
        return false;
       }
}
bool do_delimiters_nest(){
    ece150::initialize_table();
    ece150::start_reading_file();
    char next{};            //create local variables
    char before{};
    char right_most;
    int counter4{0};
    int counter5{0};
    while(ece150::at_eof()!=true){
        next = ece150::get_next_character();
        right_most = ece150::get_right_most_character();
        if(next == '('||next == '{'||next == '['){
            ece150::place_character(next);          //place the character if there is a open ([{
           }
        else if(next == ')'){       //if the system detects a closing )
            if(right_most == '('){
                ece150::erase_right_most_character();   //if the right most character(opening)matches the detected closing, it's a match.
            }
            else{
                std::cout<<"Unmatched )"<<std::endl;   //otherwise, return unmatched with the sign, in this case, )
                counter4++;
            }
        }
        else if(next == '}'){               //the above comments also applies to the following code, just changing the sign.
            if(right_most == '{'){
                ece150::erase_right_most_character();
            }
            else{
                std::cout<<"Unmatched }"<<std::endl;
                counter4++;
            }
        }
        else if(next == ']'){
            if(right_most == '['){
                ece150::erase_right_most_character();
            }
            else{
                std::cout<<"Unmatched ]"<<std::endl;
                counter4++;
            }
        }
    }
    if(ece150::is_table_empty()==true&&counter4==0){
        return true;
    }
    else if(ece150::is_table_empty()!=true){                           //checking the missing situation
        std::cout<<"Missing ";
        counter5++;
        while(ece150::is_table_empty()!= true){         //if the table is not empty, do the following
            before = ece150::get_right_most_character();
            if(before == '{'){
                std::cout<<"}";
                ece150::erase_right_most_character();   //after find the missing, erase the right most, and look for the next missing situation
            }
            else if(before == '['){
                std::cout<<"]";
                ece150::erase_right_most_character();
            }
            else if(before == '('){
                std::cout<<")";
                ece150::erase_right_most_character();
            }
        }
        if(counter4>0||counter5>0){
        std::cout<<'\n';            //print the bool on a separate line
        return false;
        }
        else{
            return true;
        }
    }
}
