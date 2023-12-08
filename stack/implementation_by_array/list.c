#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init(struct stack* st,int size){
	st->arr=(char *)malloc(sizeof(char)*size);
	st->count=0;
	st->size=size;
	return;
}

int isEmpty(struct stack st){
	if (st.count==0){
		return 1;
	}
	return 0;
}

int isFull(struct stack st){
	if (st.count==st.size){
		return 1;
	}
	return 0;
}

void push(struct stack* st,char data){
	if (isFull(*st)){
		return;
	}
	st->arr[st->count++]=data;
	return;
}

void pop(struct stack* st){
	if (isEmpty(*st)){
		return;
	}
	st->count--;
	return;
}

void insert_beg(struct stack* st,char data){
	if (isFull(*st)){
		return;
	}
	for (int i=st->count-1;i>=0;i--){
		st->arr[i+1]=st->arr[i];
	}
	st->arr[0]=data;
	st->count++;
	return;
}

void del_end(struct stack* st){
	if (isEmpty(*st)){
		return;
	}
	st->count--;
	return;
}

void del_beg(struct stack* st){
	if (isEmpty(*st)){
		return;
	}
	for (int i=0;i<st->count-1;i++){
		st->arr[i]=st->arr[i+1];
	}
	st->count--;
	return;
}


char top(struct stack st){
	if (isEmpty(st)){
		return 'x';
	}
	return st.arr[st.count-1];
}

int length(struct stack st){
	return st.count;
}

int search(struct stack st,char data){
	if (isEmpty(st)){
		return INT_MIN;
	}
	for (int i=0;i<st.count;i++){
		if (st.arr[i]==data){
			return i;
		}
	}
	return INT_MIN;
}


void display(struct stack st){
	if (isEmpty(st)){
		return;
	}
	for (int i=0;i<st.count;i++){
		printf("%c ",st.arr[i]);
	}
	printf("\n");
	return;
}

void precedence(char ch){
	switch (ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

int isOperand(char ch){
	return ('a'<=ch && ch<='z') || ('A'<=ch<='Z');
}

void infix_to_postfix(char infix[],char postfix[]){
	struct stack;
    init(&sack);
    int i=0;
    int j=0;
    while (infix[i]!='\0'){
        char c=infix[i];
	if ((c>='a' && c<='z') && (c>='A' && c<='Z')){
		postfix[j++]=c;
	}
	else if(c=='('){
		push(&st,c);
	}
	else if(c==')'){
		while (!isEmpty(st) && top(st)!='('){
			ans[j++]=top(st);
			pop(&st);
		}
		if (top(st)=='('){
			pop(&st);
		}
	}
	else if(c=='+' || c=='-' || c=='*' || c=='\' || c=='^'){
		while (precedence(c)<=top(st) && !isEmpty(st)){
			postfix[j++]=top(st);
			pop(&st);
		}
		push(&st,c);
	}
    }
    while (!isEmpty(st)){
	    postfix[j++]=top(st);
	    pop(&st);
    }

    return postfix;
}






}







