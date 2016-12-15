#include <iostream>


// Helper functions
//
inline void swap(char *a, char *b){
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

// Remove whitespace from both ends of a given string
//
void Trim(std::string &input){
    
    std::string t("");
    
    int i = 0, j = input.size()-1;
    
    while(true){
    	if(input[i] == ' ') i++;
    	if(input[j] == ' ') j--;

    	if(input[i] != ' ' && input[j] != ' ') break;
    }
        
    while(i <= j){
      t += input[i];
      i++;
    }

    input = t;
}

// This problem is done in stages.  The trick is to reverse 
// the characters in the entire sentence.  Then we go through the string
// and reverse each individual word.
//
void reverseSentence(std::string &input){
  int j = input.size()-1, i = 0;
  int spaces = 0;
  
  Trim(input);
  
  while(i < j){
    swap(&input[i++], &input[j--]);
  }
}


void reverseWord(int start, int end, std::string &input){
    
    int i = start;
    int j = end;
        
    while(i < j){
      swap(&input[i++], &input[j--]);
    }
}

void reverseWords(std::string &input){
  
  int start = 0, end = 0;

  for(int i = 0; i <= input.size(); ++i){
      if(input[i] == '\0'){
        reverseWord(start, end-1, input);
      }
      
      else if(input[i] == ' '){
      	// we have hit a space so we guess we've ended
      	// with a word
        reverseWord(start, end-1, input);
        start = end+1;
      }
      ++end;
  }
}


int main() {
    
    std::string input("Hello There   ");
    
    Trim(input);
    std::cout << "Trimmed: " << input << std::endl;
    reverseSentence(input);
    std::cout << "Reversed Sentence:" << input << std::endl;
    reverseWords(input);
    std::cout << "REversed Words: " << input << std::endl;
}

