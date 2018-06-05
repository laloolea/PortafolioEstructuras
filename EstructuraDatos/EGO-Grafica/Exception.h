//
// Created by Eduardo Gonzalez Olea on 5/22/18.
//

#ifndef EGO_GRAFICA_EXCEPTION_H
#define EGO_GRAFICA_EXCEPTION_H

#include <string>

class Exception {
public:

	/**
	* \brief Constructs a new exception with "Has ocurr an error" as its detail message.
	*/
	Exception() { message = "Has ocurr an error.";}

	/**
	* \brief Constructs a new exception with the specified detail message.
	* \paramn _message string that contains the message.
	*/
	Exception(std::string _message) {message = _message;}

	/**
	* \brief Gets the message of this error.
	* \returns the message error.
	*/
	std::string getMessage() {return message;}

protected:
	std::string message;
};

class IllegalArgumentException : Exception {
public:
	IllegalArgumentException() {
		message = "Invalid argument to this function";
	}
};

class IndexOutOfBoundsException : Exception {
public:
	IndexOutOfBoundsException() {
		message = "Index out of the range";
	}
};

class EmptyContainerException : Exception {
public:
	EmptyContainerException() {
		message = "The container is empty";
	}
};

class NullPointerException : Exception {
public:
	NullPointerException() {
		message = "Null pointer";
	}
};

#endif //EGO_GRAFICA_EXCEPTION_H
