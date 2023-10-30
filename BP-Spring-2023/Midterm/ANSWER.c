#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRY_COUNT	100
#define MAX_NAME_LEN	10
#define MAX_NUM_LEN		20
#define MAX_LINE_LEN	40

typedef struct tagEntry{
	char name[MAX_NAME_LEN];
	char number[MAX_NUM_LEN];
} entry;

int init(entry entries[], const int size);
int readline(char line[], const int size);
int list_by_name(const entry entries[], const int size, const char str[]);
int list_by_number(const entry entries[], const int size, const char str[]);
int list(const entry entries[], const int size, const int n);
int strcmpi(const char str1[], const char str2[]);
int get_arg(const char str[]);
int to_plain(const char str[], char plain[]);
int prompt();

void main(){
	char line[MAX_LINE_LEN];
	entry entries[MAX_ENTRY_COUNT];
	int num_entries = init(entries, MAX_ENTRY_COUNT);

	while(prompt() && readline(line, MAX_LINE_LEN)){
		if(!strncmp(line, "list", 4))
			list(entries, num_entries, get_arg(line));
		else if (isalpha(line[0]))
			list_by_name(entries, MAX_ENTRY_COUNT, line);
		else
			list_by_number(entries, MAX_ENTRY_COUNT, line);
	}

	printf("goodbye\n");
}

int get_arg(const char str[]){
	int i = 0, arg = 0;
	while(str[i++] != '(');
	while(isdigit(str[i++]))
		arg = arg * 10 + (str[i-1] - '0');
	return arg;
}

int strcmpi(const char str1[], const char str2[]){
	int i = 0;
	while(str1[i] && str2[i] && tolower(str1[i]) == tolower(str2[i]))
		i++;
	return str1[i] - str2[i];
}

int list(const entry entries[], const int size, const int n){
	int i = size - n;
	i = i < 0 ? 0 : i;
	while(i < size){
		printf("%s,%s\n", entries[i].name, entries[i].number);
		i++;
	}
	return n > size ? size : n;
}

int to_plain(const char str[], char plain[]){
	int i = 0, j = 0;
	while(str[i])
		if (str[i] == '(' || str[i] == ')' || str[i] == '-')
			i++;
		else
			plain[j++] = str[i++];
	plain[j] = '\0';
	return i - j;
}

int list_by_number(const entry entries[], const int size, const char str[]){
	int i;
	char plain_str[MAX_NUM_LEN];
	char plain_num[MAX_NUM_LEN];
	to_plain(str, plain_str);
	for(i=0; i < size; i++){
		to_plain(entries[i].number, plain_num);
		if(strstr(plain_num, plain_str))
			printf("%s,%s\n", entries[i].name, entries[i].number);
	}
	return i;
}

int list_by_name(const entry entries[], const int size, const char str[]){
	int i;
	for(i=0; i < size; i++)
		if(!strcmpi(entries[i].name, str))
			printf("%s,%s\n", entries[i].name, entries[i].number);
	return i;
}

int init(entry entries[], const int size){
	char line[MAX_LINE_LEN];
	char c;
	int i = 0, j, k;
	while(readline(line, MAX_LINE_LEN) && strcmp(line, "~") && i < size)
	{
		j = k = 0;
		while(line[j] != ',')
			entries[i].name[k++] = line[j++];
		entries[i].name[k] = '\0';
		k = 0;
		j++;
		while(line[j] != '\0')
			entries[i].number[k++] = line[j++];
		entries[i].number[k] = '\0';
		i++;
	}
	return i;
}

int readline(char line[], const int size){
	char c;
	int i = 0;
	while((c = getchar()) != '\n' && i < size - 1)
		line[i++] = c;
	line[i] = '\0';
	return i;
}

int prompt(){
	return printf("Search> ");
}