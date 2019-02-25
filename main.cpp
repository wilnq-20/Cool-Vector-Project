/* 
Name: Nicholas Q. Williams
Date: 2/14/19
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "CoolVector.h"

using namespace std;

vector<string> split(const string & s, char delim);

int main()
{
    CoolVector a, b;

    string filename, line;
    cout << "What filename do you want to read? ";
    //filename="run1.txt";//
    cin >> filename;
    ifstream infile(filename);
    while (getline(infile, line))
    {
        if (line == "") continue; // if there's a blank line in the file, skip it

        cout << "Command: " << line << endl;
        vector<string> words = split(line, ' ');

        if (words[0] == "get")
        {
            int pos = stoi(words[2]);
            if (words[1] == "a")
            {
                cout << "Item is " << a.get(pos) << endl;
            }
            else
            {
                cout << "Item is " << b.get(pos) << endl;
            }
        }
        if (words[0] == "set")
        {
            int pos = stoi(words[2]);
            int item = stoi(words[3]);
            if (words[1] == "a")
            {
                a.set(pos, item);
            }
            else
            {
                b.set(pos, item);
            }
        }
        else if (words[0] == "append")
        {
            if (words[1] == "a")
            {
                if (words[2] == "b")
                    a.append(b);
                else
                    a.append(stoi(words[2]));//returns "value"
            }
            else
            {
                if (words[2] == "a")
                    b.append(a);
                else
                    b.append(stoi(words[2])); 
            }
        }
        else if (words[0] == "prepend") 
        {
          if (words[1] == "a")
          {
            if (words[2] == "b") {
              a.prepend(b); 
            }
            else {
              a.append(stoi(words[2])); 
            }
          }
          else 
          {
            if (words[2] == "a") {
              b.append(a); 
            }
            else {
              b.append(stoi(words[2])); 
            }
          }
        }
        else if (words[0] == "insert") 
        { 
          if (words[1] == "a") {
            if (words[3] == "a" || words[3] == "b") {
              if (words[3] == "a") {
                a.insert(stoi(words[2]), a);  
              }
              else {
                a.insert(stoi(words[2]), b); 
              }
            }
            else {
              int pos = stoi(words[2]); 
              int item = stoi(words[3]);
              a.insert(pos, item); 
            }
          }
          else if (words[1] =="b") {
            if (words[3] == "a" || words[3] =="b") {
              if (words[3] == "a") {
                b.insert(stoi(words[2]), a); 
              }
              else {
                b.insert(stoi(words[2]), b); 
              }
            }
            else {
              int pos = stoi(words[2]); 
              int item = stoi(words[3]); 
              b.insert(pos, item); 
            }
          }
        }
        else if (words[0] == "clear") {
          if (words[1] == "a") {
            a.clear(); 
          }
          else {
            b.clear(); 
          }
        }
        else if (words[0] == "remove") {
          if (words.size() == 2) {
            int pos = stoi(words[2]); 
            if (words[1] == "a") { 
              a.remove(pos); 
            } 
            else { 
              b.remove(pos); 
            }
          }
          else {
            int start = stoi(words[2]); 
            int end = stoi(words[3]); 
            if (words[1] == "a") {
              a.remove(start, end); 
            }
            else {
              b.remove(start, end); 
            }
          }
        }
        else if (words[0] == "slice") {
          int start = stoi(words[2]); 
          int end = stoi(words[3]); 

          if (words[1] == "a") {
            if (words[4] == "a") {
              a = a.slice(start, end); 
            }
            else {
              b = a.slice(start, end); 
            }
          }
          else {
            if (words[4] == "a") {
              a = b.slice(start, end); 
            }
            else {
              b = b.slice(start, end); 
            }
          }
        }

        cout << "CoolVector a: " << a << endl << "CoolVector b: " << b << endl << endl;
    }

    return 0;
}

vector<string> split(const string & s, char delim)
{
    stringstream ss(s);  // this requires #include <sstream>
    string item;
    vector<string> elems;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}
