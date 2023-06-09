#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {		//list node ����ü
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
		case ')':
			if (is_empty(top) == 1) {	//���� ��ȣ�� �ȵ�� ���� ���
				printf("\nno opening bracket\n");
			}
			else if (pop(&top) != '(') {	//¦�� �ȸ´ٸ�
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		case '}':
			if (is_empty(top) == 1) {	//���� ��ȣ�� �ȵ�� ���� ���
				printf("\nno opening bracket\n");
			}
			else if (pop(&top) != '{') {	//¦�� �ȸ´ٸ�
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		case ']':
			if (is_empty(top) == 1) {	//���� ��ȣ�� �ȵ�� ���� ���
				printf("\nno opening bracket\n");
				
			}
			else if (pop(&top) != '[') {	//¦�� �ȸ´ٸ�
				printf("\nwrong pair\n");
			}
			else printf("%c", s[i]);
			break;
		}
		i++;
	}
	if (top->data != NULL) {
		printf("\nno closing bracket\n");	//���� ��ȣ�� ���ٸ�
	}
	else
		printf("\nbalanced expression\n");	//���*^^*
}

int main(void) {
	StackNode* top = create_stack();
	char s1[20] = "{a+(b+c)}";	//�ùٸ� ��
	char s2[20] = "a+b)*c}";	//���� ��ȣ�� ���� ��
	char s3[20] = "a+{c-(b+d})";//��ȣ�� ¦�� ���� ���� ��
	char s4[20] = "(a+b{*c";	//���� ��ȣ�� ���� ��

	printf("�ùٸ� ��\n");
	check(top, s1);

	printf("\n���� ��ȣ�� ���� ���\n");
	check(top, s2);

	printf("\n��ȣ�� ¦�� ���� �ʴ� ���\n");
	check(top, s3);

	printf("\n���� ��ȣ�� ���� ���\n");
	check(top, s4);
}