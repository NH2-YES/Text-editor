#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 300
#define LINES 1000


  void Create_New_File();
  void Open_File();
  void Edit_File();
  void Save_File();
  void Display_File_Content();
  void Delete_File();
  void Append_File();
  void Search_Word();
  void Replace_Word();
  void Count_Words();
  void Exit_Editor();

  int main(){
    int choice;
    char ch;
    char name[50];
    printf("Enter your name Please: ");
    scanf("\a%s", name);
    getchar();

    printf("Assalamoualeykoum %s hope you're fine now let's start: ", name);

  while(1){
    printf("\n\a%s Text Editor:\n Choose an Option: \n", name);
    printf("1.Create a New File:\n");
    printf("2.Open a File:\n");
    printf("3.Edit The File:\n");
    printf("4.Save File:\n");
    printf("5.Display The File Content:\n");
    printf("6.Append_File:\n");
    printf("7.Search_Word:\n");
    printf("8.Delete_File:\n");   
    printf("9.Replace_Word:\n");
    printf("10.Count_Words_Lines:\n");
    printf("11.Exit_Editor:\n");

    scanf("%d", &choice);
    getchar();

    switch (choice){
      case 1:
        Create_New_File(2, (char*[]){"Ready.c", "Neww.txt"});
        break;
      case 2:
        Open_File(2, (char*[]){"Ready.c", "Myfile"});
        break;
      case 3:
        Edit_File(2, (char*[]){"Ready.c", "Myfile"});
        break;
      case 4:
        Save_File(2, (char*[]){"Ready.c", "Myfile"});
        break;
        case 5:
        Display_File_Content(2, (char*[]){"Ready.c", "New.txt"});
        break;
        case 6:
        Append_File(2, (char*[]){"Ready.c", "Myfile"});
        break;
        case 7:
        Search_Word(2, (char*[]){"Ready.c", "Myfile"});
        break;
        case 8:
        Delete_File(2, (char*[]){"Ready.c", "Myfile"});
        break;  
        case 9:
        Replace_Word(2, (char*[]){"Ready.c", "Myfile"});
        break;  
        case 10:
        Count_Words(2, (char*[]){"Ready.c", "Myfile"});
        break;                
        case 11:
        Exit_Editor();
        break;
        default:
          printf("Invalid choice please enter the correct number for an option: ");
        
    }
  }
  return 0;
}
  void Create_New_File(int argc, char argv[]){
    FILE *fp;
  
    if(argc!=2){
      printf("Usage: <filename> incorrect number of arguments\n ");
      exit(1);
    }
    if((fp=fopen(argv[1], "w"))==NULL){
      printf("File %s doesn't exist\n", argv[1]);
      exit(1);
    }
    fclose(fp);
    printf("File %s created successfully! \n", argv[1]);

}

void Open_File(int argc, char *argv[]){
  FILE *fp;
  char ch;
  if(argc!=2){
    printf("Usage: <File name> Enter the correct name of the File\n");
    exit(1);
  }
  if((fp=fopen(argv[1], "r"))==NULL){
    printf("Cannot open file %s", argv[1]);
    exit(1);
  }
  while((ch=getc(fp))!=EOF){
    putchar(ch);
  }
  fclose(fp);
}

void Edit_File(int argc, char *argv[]){
  FILE *fp;
  char ch;
  char str[LENGTH];
  int pos;  
  if(argc!=2){
    printf("Usage: <filename> Enter file name");
    exit(1);
  }

  if((fp=fopen(argv[1], "r+"))==NULL){
    printf("Cannot open file %s", argv[1]);
    exit(1);
  }

  printf("Enter the text to be added to the file: ");
  fgets(str, LENGTH, stdin);
  str[strcspn(str, "\n")] = 0;
  
  printf("Enter the position in bytes where you want to add the text: ");
  if((scanf("%d", &pos))!=1){
    printf("Invalid position\n");
    fclose(fp);
    exit(1);
  }
  getchar();

  fseek(fp, pos, SEEK_SET); 

  fprintf(fp, "%s", str);
  fclose(fp);
  printf("The File has been successfully Modified\n");  
}

void Save_File(int argc, char *argv[]){
  FILE *fp;
  char ch;
  char str[LENGTH]; 
  if(argc!=2){

    printf("Usage: <filename> Enter file name");
    exit(1);
  }
  if((fp=fopen(argv[1], "a"))==NULL){
    printf("Cannot open file %s", argv[1]);
    exit(1);
  }
  printf("Enter the text to be added to the file: ");
  fgets(str, LENGTH, stdin);
  str[strcspn(str, "\n")] = 0;

  fputs(str,fp);    
  fclose(fp);
  printf("File successfully saved!");
}
void Display_File_Content(int argc, char *argv[]){
  FILE *fp;
  char ch;

  printf("Your file content is: \n");
  if(argc!=2){
    printf("Usage: <filename> Enter file name");
    exit(1);
  }
  if((fp=fopen(argv[1], "r"))==NULL){
    printf("Cannot open file %s", argv[1]);
    exit(1);
  }
  while((ch=getc(fp))!=EOF){
    putchar(ch);
  }
  fclose(fp); 
}

void Exit_Editor(){
  printf("Exiting the Editor\n");
  exit(0);
}


  void Append_File(int argc, char *argv[]){
    FILE *fp;
    char ch;
    char str[LENGTH];
  if(argc!=2){
    printf("Usage: Enter correct File Name");
    exit(1);
  }
  if((fp=fopen(argv[1], "a"))==NULL){
    printf("Canot append File %s", argv[1]);
    exit(1);
  }
  printf("Enter the text to append: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")]='\0';
  
  fputs(str, fp);

  fclose(fp);
  printf("File %s is successfully appended", argv[1]);
  }

  void Search_Word(int argc, char *argv[]){
    FILE *fp;
    char word[50];
    char str[LINES];
    int line=1;
    int found=0;
    
    if(argc!=2){
      printf("Usage: Enter correct File Name");
      exit(1);
    }
    if((fp=fopen(argv[1], "r"))==NULL){
      printf("Cannot  open File %s", argv[1]);
      exit(1);
    }
    printf("Enter the word to search: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")]='\0';

    while(fgets(str, LENGTH, fp)!=NULL){
      if(strstr(str, word)){
        printf("The Word %s was found in line %d: %s", word, line, str);
        found=1;
      }
      line++;      
    }

      if(!found){
        printf("The word %s was not found in the file %s", word, argv[1]);
      }
      fclose(fp);
  }

void Delete_File(int argc, char *argv[]){
  FILE *fp;

   if(argc!=2){
      printf("Usage: Enter correct File Name");
      exit(1);
    }
    if((fp=fopen(argv[1], "w"))==NULL){
      printf("Cannot  open File %s", argv[1]);
      exit(1);
    }
    fclose(fp);

    if(remove(argv[1])==0){
      printf("File deleted successfully");
    }
    else printf("Cannot delete file");
}

void Replace_Word(int argc, char *argv[]){
  FILE *fp;
  FILE *temp;
  char word[50];
  char str[LENGTH];
  char new[50];
  int found=0;

  if(argc!=2){
    printf("Usage: <filename> Enter correct file name");
    exit(1);
  }
  if((fp=fopen(argv[1], "r"))==NULL){
    printf("Cannot Open File %s", argv[1]);
    exit(1);
  }
    if((temp=fopen("temp.txt", "w"))==NULL){
    printf("Cannot Open File ");
    fclose(fp);
    exit(1);
  }
  printf("Enter the word to be replaced: ");
  fgets(word, LENGTH, stdin);
  word[strcspn(word, "\n")]='\0';

  printf("Enter the new word to enter: ");
  fgets(new, LENGTH, stdin);
  new[strcspn(new, "\n")]='\0';
    
  while((fgets(str, LENGTH, fp))!=NULL){
    char *pos= strstr(str, word);
    if(pos!=NULL){
      found=1;
      int act=pos-str;
      str[act]='\0';
      fprintf(temp, "%s%s%s", str,new,pos+strlen(word));
    } else fputs(str, temp);
  }
  fclose(fp);
  fclose(temp);

  if(found){
    remove(argv[1]);
    rename("temp.txt", argv[1]);
    printf("Word '%s' replaced with '%s' successfully!\n", word, new);
  } else{
    remove("temp.txt");
    printf("Word '%s' not found in the file", word);
  }

}

void Count_Words(int argc, char *argv[]) {
    FILE *fp;
    char str[LENGTH];
    int word_count = 0;
    int line_count = 0;

    if (argc != 2) {
        printf("Usage: <filename> Enter file name\n");
        exit(1);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(1);
    }
    while(fgets(str, LENGTH, fp)!=NULL){
      line_count++;
      char *token=strtok(str, "\t\n");
      while(token!=NULL){
        word_count++;
        token=strtok(NULL, "\t\n");
      }
    }
    fclose(fp);
    printf("The file contains %d lines and %d words.\n", line_count ,word_count);
}