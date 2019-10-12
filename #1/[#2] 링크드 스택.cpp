/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

typedef node* nptr;

typedef struct _stack {
	int length;
	nptr top;
}stack;

void init(stack* sptr) {
	sptr->length = 0;
	sptr->top = NULL;
}

void push(stack* stack, int data, bool output = false) {
	//���ο� ��� �����Ϳ� �޸� �Ҵ�
	nptr newNode = (nptr)malloc(sizeof(node));
	//NULL �޸� ������ ���� ó��
	if (newNode == NULL) exit(1);
	//���ο� ��忡 data�Ҵ�
	newNode->data = data;
	//head�� top���� �����Ѵ�. ������ top�� ���� ������� ���� ��ü�Ѵ�.
	newNode->next = stack->top;
	stack->top = newNode;
	//���� ����
	stack->length++;
	//���
	if (output) printf("%d Added!\n", data);
}

int pop(stack* stack, bool output = false) {
	if (stack->length > 0) { //���� ������ ������� �ʴٸ�
		//top�� ��� �����ɴϴ�
		nptr tmp = stack->top;
		//top�� tmp�� �������� �����մϴ�
		stack->top = tmp->next;
		//���ϰ��� �����ɴϴ�.
		int popValue = tmp->data;
		//����
		free(tmp);
		//���� ����
		stack->length--;
		//�Ϸ�
		if (output) printf("%d popped!\n", popValue);
		return popValue;
	}
	else {
		printf("������ ����ֽ��ϴ�!\n");
		return -1;
	}
}

//���� ���� �޼ҵ�
int getLength(stack* stack) {
	return stack->length;
}

//���� ���� �޼ҵ�
void flush(stack* stack) {
	while (stack->top != NULL) {
		pop(stack);
	}
	free(stack);
}

void display(stack* stack) {
	//Ž���� ��Ʈ ������
	nptr current = stack->top;
	//���
	printf("--------------------------------------------------------------------------------\n");
	printf("Head / Top -> ");
	//Stack�� ���� ��ŭ Ž��
	for (int i = 0; i < stack->length; i++) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	printf("--------------------------------------------------------------------------------\n");
}

int main() {
	//���� �޸� �Ҵ�
	stack* mystack = (stack*)malloc(sizeof(stack));

	//���� �ʱ�ȭ
	init(mystack);

	for (int i = 0; i < 10; i++) push(mystack, i, true);
	printf("���� ����: %d\n", getLength(mystack));

	display(mystack);

	for (int i = 0; i < 10; i++) pop(mystack, true);
	printf("���� ����: %d\n", getLength(mystack));

	flush(mystack);

	return 0;
}