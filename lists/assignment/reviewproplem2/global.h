#ifndef GLOBAL_H
#define GLOBAL_H
 
 
#define em 1
#define st 2
// global file should be included in list.h 
typedef char u8;
#define MaxList 5
typedef struct student 
{
	int degree;
	int department;
	char name[10];
	char address[10];
}Student;
typedef struct employee{
	char name[10];
	char address[10];
	char dataofbirth[10];
	char company[10];
}Employee;

/* 1- if you want to insert data for student set etype =st
   then use value.s to store another values for student
   2- if you want to insert data for employee set etype =em
   then use value.e to store another values for employeee
   */
 // by this way ypu can use lks for two types of entry in the same proramm
 // not wasting memory because of using union
typedef struct elementtype{
	u8 etype;
	union{
		Student s;
		Employee e;
	}value;
}ElementType;
#define ListEntry  ElementType
 

#endif