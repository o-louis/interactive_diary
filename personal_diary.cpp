#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// STRUCTURE
struct Story { 
  string author;
  string place;
  string content;
  time_t date_now = time(nullptr);
};

// FUNCTIONS LIST
void clear_screen();
string create_story();
void show_text_menu();
int get_user_choice();
string resume(Story info);
void display_menu(vector <string> stories);
void view_stories(vector <string> stories);
void edit_story(vector <string> stories);
int handle_action(int user_choice, vector <string> stories);

// CONSTANTS
const int ADD_STORY    =  1;
const int VIEW_STORY   =  2;
const int EDIT_STORY   =  3;
const int DELETE_STORY =  4;
const int EXIT         =  5;

void display_menu(vector <string> stories)
{
  int user_choice;

  clear_screen();
  show_text_menu();

  while((user_choice < 1 || user_choice > 5))
  {
    user_choice = get_user_choice();
  }

  clear_screen();
  handle_action(user_choice, stories);
}

int handle_action(int user_choice, vector <string> stories)
{
  string story;

  switch (user_choice)
  {
    case      ADD_STORY: 
      story = create_story();
      stories.push_back(story);
      break;
    case      VIEW_STORY:
      view_stories(stories);
      break;
    case      EDIT_STORY: cout << "1"; break;
    case      DELETE_STORY: cout << "1"; break;

    case      EXIT:
    default:  return -1; break;
  }

  if (user_choice != EXIT)
  {
    display_menu(stories);
  }

  return 0;
}

void edit_story(vector <string> stories)
{
  for (int i = 0; i < stories.size(); i++) {
    cout << stories[i] << "\n";
    cout << "====================================================" << endl;
  }
}

string create_story()
{
  Story info;

  cout << "***********************************\n\n" << endl;
  cin.ignore();

  cout << "Enter name: ";
  getline(cin, info.author);

  cout << "Enter place: ";
  getline(cin, info.place);

  cout << "Describe your thoughts, your feelings...: " << endl;
  getline(cin, info.content);

  cout << "\n\n***********************************" << endl;
  cout << "YOUR STORY HAS BEEN SAVED" << endl;

  return resume(info);
}

void view_stories(vector <string> stories)
{
  char exit;
  
  for (int i = 0; i < stories.size(); i++) {
    cout << stories[i] << "\n";
    cout << "====================================================" << endl;
  }

  cout << "Press ANY KEY then ENTER to go back to the menu . . .\n";
  cin >> exit;
}

string resume(Story info)
{
  return 
  string("Created on: ")
  + ctime(&info.date_now)
  + "\nAuthor: " + info.author
  + "\nPlace: " + info.place
  + "\n\nContent: " + info.content
  + "\n";
}

void show_text_menu()
{
  cout << "***********************************" << endl;
  cout << "  *DAILY DIARY MANAGEMENT SYSTEM*" << endl;
  cout << "***********************************" << endl;
  cout << "\tMAIN MENU:" << endl;
  cout << "ADD STORY\t[1]" << endl;
  cout << "VIEW STORY\t[2]" << endl;
  cout << "EDIT STORY\t[3]" << endl;
  cout << "DELETE STORY\t[4]" << endl;
  cout << "EXIT\t\t[5]" << endl;
}

int get_user_choice()
{
  int user_choice;
  
  cout << "ENTER YOUR CHOICE: ";
  cin >> user_choice;

  return user_choice;
}

void clear_screen()
{
  system("clear");
}

int main()
{
  vector <string> stories;

  display_menu(stories);
  return 0;
}