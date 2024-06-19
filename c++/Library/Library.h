#pragma once
#include <typeinfo>
#include <iostream>
#include <string>
#include <map>
#include <vector>

class Book {
protected:
	std::string autor;
	std::string title;
	long long ISBN;
	bool isAvailable;
public:
	Book();
	Book(std::string autor, std::string title, long long ISBN, bool isAvailable);

	// get; set;

	std::string getAutor();
	std::string getTitle();
	long long getISBN();
	bool getIsAvailable();

	void setAutor(std::string autor);
	void setTitle(std::string title);
	void setISBN(long long ISBN);
	void setIsAvailable(bool isAvailable);

	// functions

	void displayDetails();
};

class Library {
	int lenOfBooks;
	int lenOfMembers;
public:

	std::shared_ptr<Book[]> books = std::make_shared<Book[]>(lenOfBooks);
	std::shared_ptr<Member[]> members = std::make_shared<Member[]>(lenOfMembers);
	Library() {}
	Library(std::shared_ptr<Book[]> books, std::shared_ptr<Member[]> members);
	void addBook(Book book);
	void removeBook(long long ISBN);
	Book findBook(long long ISBN);
	void registerMember(Member member);
	void deleteMember(long long memberId);
	void displayBooks();
};

class Member {
	int len;
	std::string name;
	long long memberId;
	std::shared_ptr<Book[]> borrowedBooks = std::make_shared<Book[]>();
	Library tmpBook;
public:
	Member();
	Member(std::string name, long long memberId);

	// get; set;

	std::string getName();
	long long getMemberId();
	std::shared_ptr<Book[]> getBorrowedBooks();

	void setName(std::string name);
	void setMemberId(long long memberId);
	void setBorrowedBooks(std::shared_ptr<Book[]> borrowedBooks, int len);

	// functions

	Book borrowBook(std::string name);
	void returnBook(std::string& name);
};

