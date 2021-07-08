#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* pId);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* pId);

#endif // PARSER_H_INCLUDED
