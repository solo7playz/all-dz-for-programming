#include "Library.h"

// class Liblary


// class Member

Member::Member() {}
Member::Member(std::string name, long long memberId) : name(name), memberId(memberId) {

}

// get; set;

std::string Member::getName() { return this->name; }
long long Member::getMemberId() { return this->memberId; }
std::shared_ptr<Book[]> Member::getBorrowedBooks() { return this->borrowedBooks; }

void Member::setName(std::string name) { this->name = name; }
void Member::setMemberId(long long memberId) { this->memberId = memberId; }
void Member::setBorrowedBooks(std::shared_ptr<Book[]> borrowedBooks, int len) {
	this->borrowedBooks = borrowedBooks;
	this->len = len;
}

//function

Book Member::borrowBook(std::string name) {
	for (int i = 0; i < this->len; i++) {
		if (tmpBook.books[i].getTitle() == name) {
			this->borrowedBooks[i] = tmpBook.books[i];
			std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->len - 1);
			for (int j = 0; j < i - 1; j++) {
				tmp[i] = tmpBook.books[i];
			}
			for (int j = i + 1; j < this->len; j++) {
				tmp[i] = tmpBook.books[i];
			}
			tmpBook.books.reset();
			tmpBook.books = std::make_shared<Book[]>(len);
			for (int j = 0; j < this->len; j++) {
				tmpBook.books[i] = tmp[i];
			}
			break;
		}
	}
	return this->borrowedBooks[0];
}

void Member::returnBook(std::string& name) {
	for (int i = 0; i < this->len; i++) {
		if (this->borrowedBooks[i].getTitle() == name) {
			tmpBook.books[i] = this->borrowedBooks[i];
			std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->len);
			for (int j = 0; j < i - 1; j++) {
				tmp[i] = this->borrowedBooks[i];
			}
			for (int j = i; j < this->len; j++) {
				tmp[i] = this->borrowedBooks[i];
			}
			this->borrowedBooks.reset();
			this->borrowedBooks = std::make_shared<Book[]>(len);
			for (int j = 0; j < this->len; j++) {
				this->borrowedBooks[i] = tmp[i];
			}
			break;
		}
	}
}

// class Book

Book::Book() {}
Book::Book(std::string autor, std::string title, long long ISBN, bool isAvailable) : autor(autor), title(title), ISBN(ISBN), isAvailable(isAvailable) {}

// get; set;

std::string Book::getAutor() { return this->autor; }
std::string Book::getTitle() { return this->title; }
long long Book::getISBN() { return this->ISBN; }
bool Book::getIsAvailable() { return this->isAvailable; }

void Book::setAutor(std::string autor) { this->autor = autor; }
void Book::setTitle(std::string title) { this->title = title; }
void Book::setISBN(long long ISBN) { this->ISBN = ISBN; }
void Book::setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }

//functions

void Book::displayDetails() {
	if (isAvailable == true) {
		std::cout << "Номер книги - " << this->ISBN << std::endl << "Название книги - " << this->title << std::endl << "Автор книги - " << this->autor << std::endl << "Книга есть в наличии" << std::endl;
	}
	else {
		std::cout << "Номер книги - " << this->ISBN << std::endl << "Название книги - " << this->title << std::endl << "Автор книги - " << this->autor << std::endl << "Книги нет в наличии" << std::endl;
	}
}

void Library::addBook(Book book) {
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->lenOfBooks + 1);
	for (int i = 0; i < lenOfBooks; i++) {
		tmp[i] = this->books[i];
	}
	tmp[lenOfBooks] = book;
	this->books.reset();
	this->books = std::make_shared<Book[]>(lenOfBooks + 1);
	for (int i = 0; i < lenOfBooks + 1; i++) {
		books[i] = tmp[i];
	}
}
void Library::removeBook(long long ISBN) {
	std::shared_ptr<Book[]> tmp = std::make_shared<Book[]>(this->lenOfBooks - 1);
	int i = 0;
	while(books[i].getISBN() != ISBN){
		tmp[i] = this->books[i];
		i++;
	}
	for (int j = i; j < lenOfBooks; i++) {
		tmp[j - 1] = this->books[j];
	}
	this->books.reset();
	this->books = std::make_shared<Book[]>(lenOfBooks - 1);
	for (int i = 0; i < lenOfBooks + 1; i++) {
		books[i] = tmp[i];
	}
}

Book Library::findBook(long long ISBN) {
	for (int i = 0; i < lenOfBooks; i++) {
		if (this->books[i].getISBN() == ISBN) {
			return this->books[i];
			break;
		}
	}
}

void Library::registerMember(Member member) {
	std::shared_ptr<Member[]> tmp = std::make_shared<Member[]>(this->lenOfMembers + 1);
	for (int i = 0; i < lenOfMembers; i++) {
		tmp[i] = this->members[i];
	}
	tmp[lenOfMembers] = member;
	this->members.reset();
	this->members = std::make_shared<Member[]>(lenOfMembers + 1);
	for (int i = 0; i < lenOfMembers + 1; i++) {
		this->members[i] = tmp[i];
	}
}
void Library::deleteMember(long long memberId) {
	std::shared_ptr<Member[]> tmp = std::make_shared<Member[]>(this->lenOfMembers - 1);
	int i = 0;
	while(this->members[i].getMemberId() != memberId) {
		tmp[i] = this->members[i];
		i++;
	}
	for (int j = i; j < lenOfMembers; j++) {
		tmp[i - 1] = members[i];
	}
	this->members.reset();
	this->members = std::make_shared<Member[]>(lenOfMembers - 1);
	for (int i = 0; i < lenOfMembers + 1; i++) {
		this->members[i] = tmp[i];
	}
}
void Library::displayBooks() {
	for (int i = 0;i < lenOfBooks; i++) {
		std::cout << "title - " << books[i].getTitle() << std::endl << "autor - " << books[i].getAutor() << std::endl << "ISBN - " << books[i].getISBN();
	}

}