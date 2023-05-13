#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {		//list node 구조체
	char data;
	struct StackNode* link;
}StackNode;

StackNode* create_stack() {
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	s->data = NULL;
	s->link = NULL;
	return s;
}

int pop(StackNode** t) {
	int item;
	StackNode* tmp = (StackNode*)malloc(sizeof(StackNode));
	tmp = *t;
	item = tmp->data;
	*t = (*t)->link;
	free(tmp);
	return item;
}

void push(StackNode** t, int value) {
	StackNode* tmp = (StackNode*)malloc(sizeof(StackNode));
	tmp->data = value;
	tmp->link = *t;
	*t = tmp;
}

int is_empty(StackNode* top) {
	if (top->data == NULL)
		return 1;
	else
		return 0;
}

void check(StackNode* top, char s[]) {
	int i = 0;
	printf("%s\n", s);
	while (s[i] != NULL) {
		switch (s[i]) {
		case '(': case'{': case'[':
			push(&top, s[i]);
			printf("%c", s[i]);
			break;
			if (is_empty(top) == 1) {	//열린 괄호가 안들어 왔을 경우
				printf("\nno opening bracket\n");
			}
			else
		case ')':
			if (is_empty(top) == 1) {	//열린 괄호가 안들어 왔을 경우
				printf("\nno opening bracket\n");
			}
			else if (pop(&top) != '(') {	//짝이 안맞다면
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		case '}':
			if (is_empty(top) == 1) {	//열린 괄호가 안들어 왔을 경우
				printf("\nno opening bracket\n");
			}
			else if (pop(&top) != '{') {	//짝이 안맞다면
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		case ']':
			if (is_empty(top) == 1) {	//열린 괄호가 안들어 왔을 경우
				printf("\nno opening bracket\n");
				
			}
			else if (pop(&top) != '[') {	//짝이 안맞다면
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		}
		i++;
	}
	if (top->data != NULL) {
		printf("\nno closing bracket\n");	//닫힌 괄호가 없다면
	}
	else
		printf("\nbalanced expression\n");	//통과*^^*
}

int main(void) {
	StackNode* top = create_stack();
	char s1[20] = "{a+(b+c)}";	//올바른 식
	char s2[20] = "a+b)*c}";	//열린 괄호가 없을 때
	char s3[20] = "a+{c-(b+d})";//괄호의 짝이 맞지 않을 때
	char s4[20] = "(a+b{*c";	//닫힌 괄호가 없을 때

	printf("올바른 식\n");
	check(top, s1);

	printf("\n열린 괄호가 없을 경우\n");
	check(top, s2);

	printf("\n괄호의 짝이 맞지 않는 경우\n");
	check(top, s3);

	printf("\n닫힌 괄호가 없을 경우\n");
	check(top, s4);
}