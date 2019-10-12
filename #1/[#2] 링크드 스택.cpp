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
	//새로운 노드 포인터에 메모리 할당
	nptr newNode = (nptr)malloc(sizeof(node));
	//NULL 메모리 역참조 예외 처리
	if (newNode == NULL) exit(1);
	//새로운 노드에 data할당
	newNode->data = data;
	//head를 top으로 간주한다. 스택의 top을 새로 만들어진 노드로 대체한다.
	newNode->next = stack->top;
	stack->top = newNode;
	//길이 증가
	stack->length++;
	//출력
	if (output) printf("%d Added!\n", data);
}

int pop(stack* stack, bool output = false) {
	if (stack->length > 0) { //만약 스택이 비어있지 않다면
		//top을 잠시 가져옵니다
		nptr tmp = stack->top;
		//top을 tmp의 다음노드로 변경합니다
		stack->top = tmp->next;
		//리턴값을 가져옵니다.
		int popValue = tmp->data;
		//해제
		free(tmp);
		//길이 감소
		stack->length--;
		//완료
		if (output) printf("%d popped!\n", popValue);
		return popValue;
	}
	else {
		printf("스택이 비어있습니다!\n");
		return -1;
	}
}

//길이 리턴 메소드
int getLength(stack* stack) {
	return stack->length;
}

//스택 해제 메소드
void flush(stack* stack) {
	while (stack->top != NULL) {
		pop(stack);
	}
	free(stack);
}

void display(stack* stack) {
	//탐색용 노트 포인터
	nptr current = stack->top;
	//출력
	printf("--------------------------------------------------------------------------------\n");
	printf("Head / Top -> ");
	//Stack의 길이 만큼 탐색
	for (int i = 0; i < stack->length; i++) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	printf("--------------------------------------------------------------------------------\n");
}

int main() {
	//스택 메모리 할당
	stack* mystack = (stack*)malloc(sizeof(stack));

	//스택 초기화
	init(mystack);

	for (int i = 0; i < 10; i++) push(mystack, i, true);
	printf("스택 길이: %d\n", getLength(mystack));

	display(mystack);

	for (int i = 0; i < 10; i++) pop(mystack, true);
	printf("스택 길이: %d\n", getLength(mystack));

	flush(mystack);

	return 0;
}