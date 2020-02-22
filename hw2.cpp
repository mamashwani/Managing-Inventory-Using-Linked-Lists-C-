#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ArgumentManager.h"
using namespace std;

struct node {
	string bookID;
	string bookName;
	string authorName;
	node* next;

};

class Library {
private:
	node* head;
	node* tail;
	int length;

public:
	Library() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	//Maybe make a initiation for newBook... 
	void insert(string id, string bName, string aName) {
		node* newBook = new node();
		newBook->bookID = id;
		newBook->bookName = bName;
		newBook->authorName = aName;
		newBook->next = NULL;

		bool unique = true;

		if (head == NULL) {
			head = newBook;
			tail = newBook;
			length++;
		}
		else {
			node* currentNode = head;
			if (currentNode->bookID == id) {
				unique = false;
			}
			for (int i = 0; i < length - 1 && unique; i++) { //Simple Duplicate Check 
				currentNode = currentNode->next;
				if (currentNode->bookID == id) {
					unique = false;
					break;
				}
			}
			if (unique) {
				tail->next = newBook;
				tail = newBook;
				length++;
			}
		}

	}

	void insertAt(string id, string bName, string aName, int loc) {
		node* newBook = new node();
		newBook->bookID = id;
		newBook->bookName = bName;
		newBook->authorName = aName;
		newBook->next = NULL;

		bool unique = true;

		if (head == NULL) //If list is empty 
		{
			head = newBook;
			tail = newBook;
			length++;

		}
		else { //Else look for spot and insert 
			node* currentNode = head;
			node* trailNode = head;
			node* found = NULL;

			if (currentNode->bookID == id) {
				unique = false;
			}
			for (int i = 0; i < length - 1 && unique; i++) { //Simple Duplicate Check
				if (currentNode->bookID == id) {
					unique = false;
					break;
				}
				else if (currentNode->next->bookID == id) {
					unique = false;
					break;
				}
				if (i + 1 == loc) {
					found = currentNode->next;
					trailNode = currentNode;
				}
				currentNode = currentNode->next;
			}
			if (unique && loc >= length) { //If unique & loc at end or loc > length 
				currentNode->next = newBook;
				tail = newBook;
				length++;

			}
			else if (unique && loc == 0) { //If Loc = 0 and list was not empty. 
				newBook->next = head;
				head = newBook;
				length++;

			}
			else if (unique && found == NULL) { //If Location not found, ex: pos = -2. Add at end. I should organize this. 
				currentNode->next = newBook;
				tail = newBook;
				length++;
			}
			else if (unique) { //If unique and somewhere not at beginning or end 
				trailNode->next = newBook;
				newBook->next = found;
				length++;
			}
		}
	}
	void removeID(string deleteMe) {
		node* currentNode;        //pointer to traverse the list
		node* trailNode = head;

		if (head != NULL) { //If list is not empty 
			currentNode = head;
			if (head->bookID == deleteMe) { //deleting head 
				head = currentNode->next;
				length--;
				if (head == NULL) { //If it only has 1 node
					tail = NULL;
				}
				delete currentNode;
			}

			if (length != 0) { //If list is still not empty 
				currentNode = head;
				for (int i = 0; i < length - 1; i++) {
					trailNode = currentNode;
					currentNode = currentNode->next;
					if (currentNode->bookID == deleteMe) {
						if (currentNode == tail) { //If removing tail 
							trailNode->next = NULL;
							tail = trailNode;
							delete currentNode;
							length--;
							break;
						}
						else {
							trailNode->next = currentNode->next;
							delete currentNode;
							length--;
							break;
						}

					}
				}
			}
		}

	}

	void removePos(int deleteMe) {
		node* currentNode;        //pointer to traverse the list
		node* trailNode = head;
		int count = 0;

		if (head != NULL) { //If list is not empty 
			currentNode = head;
			if (count == deleteMe) { //deleting head 
				head = currentNode->next;
				length--;
				if (head == NULL) { //If it only has 1 node
					tail = NULL;
				}
				delete currentNode;
			}

			else if (length != 0) { //If list is still not empty. But remove pos should only happen once. 
				currentNode = head;
				for (int i = 0; i < length - 1; i++) {
					trailNode = currentNode;
					currentNode = currentNode->next;
					count++;
					if (count == deleteMe) {
						if (currentNode == tail) { //If removing tail 
							trailNode->next = NULL;
							tail = trailNode;
							delete currentNode;
							length--;
							break;
						}
						else {
							trailNode->next = currentNode->next;
							delete currentNode;
							length--;
							break;
						}

					}

				}
			}
		}

	}

	void removeBName(string deleteMe) { // delete by Book Name  
		node* currentNode;        //pointer to traverse the list
		node* trailNode = head;

		if (head != NULL) { //If list is not empty 
			currentNode = head;
			if (head->bookName == deleteMe) { //deleting head 
				head = currentNode->next;
				length--;
				if (head == NULL) { //If it only has 1 node
					tail = NULL;
				}
				delete currentNode;
				//remove(deleteMe); //Recursive call to check if there is still more.
			}

			if (length != 0) { //If list is still not empty 
				currentNode = head;
				for (int i = 0; i < length - 1; i++) {
					trailNode = currentNode;
					currentNode = currentNode->next;
					if (currentNode->bookName == deleteMe) {
						if (currentNode == tail) { //If removing tail 
							trailNode->next = NULL;
							tail = trailNode;
							delete currentNode;
							length--;
							break;
						}
						else {
							trailNode->next = currentNode->next;
							delete currentNode;
							length--;
							break;
						}

					}
				}
			}
		}

	}
	void removeAName(string deleteMe) { // delete node... Edit the ifs & parameters potentially later. 
		node* currentNode;        //pointer to traverse the list
		node* trailNode = head;

		if (head != NULL) { //If list is not empty 
			currentNode = head;
			if (head->authorName == deleteMe) { //deleting head 
				head = currentNode->next;
				length--;
				if (head == NULL) { //If it only has 1 node
					tail = NULL;
				}
				delete currentNode;
				//remove(deleteMe); //Recursive call to check if there is still more.
			}

			if (length != 0) { //If list is still not empty 
				currentNode = head;
				for (int i = 0; i < length - 1; i++) {
					trailNode = currentNode;
					currentNode = currentNode->next;
					if (currentNode->authorName == deleteMe) {
						if (currentNode == tail) { //If removing tail 
							trailNode->next = NULL;
							tail = trailNode;
							delete currentNode;
							length--;
							break;
						}
						else {
							trailNode->next = currentNode->next;
							delete currentNode;
							length--;
							break;
						}

					}
				}
			}
		}

	}
	int getLength() {
		return length;
	}
	void sortID() {
		node* currentNode = head;
		node* trailNode = head;
		node* trailNode2 = trailNode;
		if (head != NULL) {
			for (int i = 0; i < length - 1; i++)
			{
				trailNode = currentNode;
				trailNode2 = trailNode;
				for (int j = 0; j < length - i - 1; j++) {
					trailNode2 = trailNode2->next;
					if (trailNode->bookID > trailNode2->bookID) {
						string tempID = trailNode->bookID;
						string tempBN = trailNode->bookName;
						string tempAN = trailNode->authorName;

						trailNode->bookID = trailNode2->bookID;
						trailNode->bookName = trailNode2->bookName;
						trailNode->authorName = trailNode2->authorName;

						trailNode2->bookID = tempID;
						trailNode2->bookName = tempBN;
						trailNode2->authorName = tempAN;
					}
				}
				currentNode = currentNode->next;
			}
		}
	}
	void sortBookName() {
		node* currentNode = head;
		node* trailNode = head;
		node* trailNode2 = trailNode;
		if (head != NULL) {
			for (int i = 0; i < length - 1; i++)
			{
				trailNode = currentNode;
				trailNode2 = trailNode;
				for (int j = 0; j < length - i - 1; j++) {
					trailNode2 = trailNode2->next;
					if (trailNode->bookName > trailNode2->bookName) {
						string tempID = trailNode->bookID;
						string tempBN = trailNode->bookName;
						string tempAN = trailNode->authorName;

						trailNode->bookID = trailNode2->bookID;
						trailNode->bookName = trailNode2->bookName;
						trailNode->authorName = trailNode2->authorName;

						trailNode2->bookID = tempID;
						trailNode2->bookName = tempBN;
						trailNode2->authorName = tempAN;
					}
				}
				currentNode = currentNode->next;
			}
		}
	}
	void sortAuthorName() {
		node* currentNode = head;
		node* trailNode = head;
		node* trailNode2 = trailNode;
		if (head != NULL) {
			for (int i = 0; i < length - 1; i++)
			{
				trailNode = currentNode;
				trailNode2 = trailNode;
				for (int j = 0; j < length - i - 1; j++) {
					trailNode2 = trailNode2->next;
					if (trailNode->authorName > trailNode2->authorName) {
						string tempID = trailNode->bookID;
						string tempBN = trailNode->bookName;
						string tempAN = trailNode->authorName;

						trailNode->bookID = trailNode2->bookID;
						trailNode->bookName = trailNode2->bookName;
						trailNode->authorName = trailNode2->authorName;

						trailNode2->bookID = tempID;
						trailNode2->bookName = tempBN;
						trailNode2->authorName = tempAN;
					}
				}
				currentNode = currentNode->next;
			}
		}
	}

	void print(string file) {                          //print
		node* currentNode = head;
		ofstream ofs(file);
		int count = 0;
		while (currentNode != NULL) { 	            //travers list
			ofs << "book_id:" << currentNode->bookID << ", book_name:" << currentNode->bookName << ", book_author:" << currentNode->authorName << "\n";
			currentNode = currentNode->next;
			count++;
		}

	}
};



string parser(string line) {
	istringstream savior(line); //Stores "line" which contains the whole record
	string bRecords;
	while (getline(savior, line, ','))  //cuts the line at the commas (loops 3 times)
		bRecords += line.substr(line.find(':') + 1, line.length() - line.find(':')) + '-'; //from : to the end & separates with '-'
	return bRecords; //returns the result
}

string parseAddPos(string s) {
	stringstream okay(s);
	string temp = "";
	getline(okay, temp, 's'); //everything to s 
	getline(okay, temp, ':'); //everything from s to : 
	getline(okay, temp, ' '); //: to ' ' 
	return temp;
}

string parseRem(string s) {
	stringstream rem(s);
	string temp = "";
	getline(rem, temp, ':');
	return temp;
}




int main(int argc, char *argv[])
{

	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string command = am.get("command");
	string output = am.get("output");



	ifstream ifs(input);
	ifstream coms(command);
	//string temp = "output";

	string line;
	Library SaveMe;
	string id, bName, aName;

	while (getline(ifs, line)) { //Input File stuff 
		if (line != "") {
			string parsed = parser(line);
			istringstream iss(parsed);
			getline(iss, id, '-'); //finds up to dashes 
			getline(iss, bName, '-');
			getline(iss, aName, '-');

			SaveMe.insert(id, bName, aName);
		}
	}

	while (getline(coms, line)) {  //Command File stuff
		if (line != "") {
			if (line[0] == 'a') { //if first letter is 'a', add command 
				string pos = parseAddPos(line); //getting position #
				stringstream ss(line);
				line = line.substr(line.find(pos) + 2); //getting info 
				string parsed = parser(line);
				stringstream iss(parsed);
				getline(iss, id, '-'); //find up to dashes
				getline(iss, bName, '-');
				getline(iss, aName, '-');

				SaveMe.insertAt(id, bName, aName, stoi(pos)); //Insert at LL function 
			}
			if (line[0] == 's') { //sort command 
				line = line.substr(line.find(' ') + 1); //getting everything past ' '
				if (line == "book_id") {
					SaveMe.sortID();
				}
				else if (line == "book_name") {
					SaveMe.sortBookName();
				}
				else if (line == "book_author") {
					SaveMe.sortAuthorName();
				}
			}
			if (line[0] == 'r') { //remove command
				line = line.substr(line.find(' ') + 1);
				string removeType = parseRem(line); //Parsing 
				string parsed = parser(line);
				stringstream rem(parsed);
				string something; //The string past the remove type 
				getline(rem, something, '-');

				int i = 0;
				int length = SaveMe.getLength();
				while (i < length) {
					if (removeType == "book_name") {
						SaveMe.removeBName(something);
						i++;
					}
					else if (removeType == "book_author") {
						SaveMe.removeAName(something);
						i++;
					}
					else if (removeType == "book_id") {
						SaveMe.removeID(something);
						i++;
					}
					else if (removeType == "pos") { //Make this.  
						SaveMe.removePos(stoi(something));
						i++;
						break; //Remove pos should only check once. 
					}
				}
			}

		}
	}

	SaveMe.print(output); //Output file... 



	return 0;
}