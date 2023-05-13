#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {		//list node ±¸Á¶Ã¼
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

int check(StackNode* top, char s[]) {
	int i = 0;
	while (s[i] != NULL) {
		switch (s[i]) {
		case '(': case'{': case'[':
			push(&top, s[i]);
			printf("%c", s[i]);
			break;
		if (is_empty(top) == 1) {	//¿­¸° °ýÈ£°¡ ¾Èµé¾î ¿ÔÀ» °æ¿ì
				printf("\nno open bracket\n");
				return 0;
		}
		case ')':
			if (pop(&top) != '(') {	//Â¦ÀÌ ¾È¸Â´Ù¸é
				printf("\nwrong pair\n");
				return 0;
			}
			else printf("%c", s[i]);
			break;
		case '}':
			if (pop(&top) != '{') {	//Â¦ÀÌ ¾È¸Â´Ù¸é
				printf("\nwrong pair\n");
				return 0;
			}
			else printf("%c", s[i]);
			break;
		case ']':
			if (pop(&top) != '[') {	//Â¦ÀÌ ¾È¸Â´Ù¸é
				printf("\nwrong pair\n");
				return 0;
			}
			else printf("%c", s[i]);
			break;
		}
		i++;
	}
	if (top->data != NULL) {
		printf("\nno closed bracket\n");	//´ÝÈù °ýÈ£°¡ ¾ø´Ù¸é
		return 0;
	}
	else
		printf("\nbalanced expression\n");	//Åë°ú*^^*
		return 1;
}

int main(void) {
	StackNode* top = create_stack();
	char s1[20] = "{a+(b+c)}";	//balanced
	char s2[20] = "a+b)*c}";	//no open bracket
	char s3[20] = "a+{c-(b+d})";//wrong pair
	char s4[20] = "(a+b{*c";	//no closed bracket

	check(top, s1);
	check(top, s2);
	check(top, s3);
	check(top, s4);
	

}