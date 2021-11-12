/*
 * CSc103 Project 4: uncommenting C/C++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 15-hrs
 */

#include <cstdio> // printf and friends
// strings might help if you want to do a nice job removing whitespace
#include <string>
using std::string;

int main()
{
	/* TODO: write me... */
 enum state {
  normal,
  slash,
  slashslash,
  slashstar,
  star,
  dquotes,
  dquotesSlash,
  squote,
  squoteSlash,
  other
  };

  state s = normal;
  char c;
  while(scanf("%c", &c) > 0){
   switch(s){

    case normal:
     if(c == '/'){
      s = slash;
     } else if(c == '\''){
      s = squote;
      printf("%c",c);
     } else if(c == '\"'){
      s = dquotes;
      printf("%c",c);
     }
     //else if(c == '\n'){
     //printf("\n");
     //}
     else {
     printf("%c",c);
     } break;
 //-------------------------------------------------
    case slash: // /
     if(c == '/'){
      s = slashslash;
     } else if (c == '*'){
      s = slashstar;
     } else {
      printf("%c",'/');
      printf("%c",c);
      s = normal;
     } break;
 //-------------------------------------------------
    case slashslash: // //
     if(c == '\n'){
      s = normal;
      printf("%c", c);
     }
     break;
 //-------------------------------------------------
    case slashstar:
     if(c == '*'){
      s = star;
     }
     break;
 //-------------------------------------------------
    case star:
     if(c == '/'){
      s = normal;
     } else {
      s = slashstar;
     }
     break;
 //-------------------------------------------------
  case squote:
   if(c == '\\'){
    s = squoteSlash;
   } else {
    s = other;
   } printf("%c",c);
    break;
 //-------------------------------------------------
  case squoteSlash:
   printf("%c",c);
   s = other;
   break;
 //-------------------------------------------------
  case other:
   if(c =='\''){
     s = normal;
   }
   printf("%c",c);
   break;
 //-------------------------------------------------
  case dquotes:
   if(c == '\\'){
     s = dquotesSlash;
   } else if(c == '\"'){
     s = normal;
   }
   printf("%c",c);
   break;
 //-------------------------------------------------
  case dquotesSlash:
   printf("%c",c);
   s = dquotes;
   break;
 //-------------------------------------------------
  }
 }
	return 0;
}
