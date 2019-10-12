/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/
#include <stdio.h>
#include <stdlib.h>

//Pragma 영역 정의
#pragma region Type Definition
//노드 정의
struct Node
{
	int data;
	struct Node* next;
};

//Queue 구조체 정의
struct Queue
{
	//맨 앞(꺼낼 위치)
	Node* front;
	//맨 뒤(보관할 위치)
	Node* rear;
	//큐 길이
	int length;
};
#pragma endregion

//큐 초기화 메소드
void InitQueue(Queue* queue)
{
	//front와 rear를 NULL로 설정
	queue->front = queue->rear = NULL;
	//큐 길이를 0으로 설정
	queue->length = 0;
}

//큐가 비었는지 확인하는 메소드
int IsEmpty(Queue* queue)
{
	//보관 개수가 0이면 빈 상태
	return queue->length == 0;
}

//큐 삽입 메소드
void Enqueue(Queue* queue, int data)
{
	//새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	//NULL 메모리 역참조 예외 설정 --> 메모리 부족으로 할당 실패시
	if (newNode == NULL) exit(1);
	//매개변수 data 로 새로운 노드 data 설정
	newNode->data = data;
	//새로운 노드의 다음은 NULL
	newNode->next = NULL;


	if (IsEmpty(queue)) //큐가 비어있을 때
	{
		//맨 앞을 새로운 노드로 설정
		queue->front = newNode;
	}
	else //큐가 비어있지 않을 때
	{
		//맨 뒤의 다음을 새로운 노드로 설정
		queue->rear->next = newNode;
	}
	//맨 뒤를 새로운 노드로 설정
	queue->rear = newNode;
	//큐 길이를 1 증가
	queue->length++;
}

//큐 요소 삭제 메소드
int Dequeue(Queue* queue)
{
	//리턴 값을 담아두는 변수
	int value = 0;

	//임시 노드 포인터 변수
	Node* tmp;

	//큐가 비었을 때
	if (IsEmpty(queue))
	{
		//0을 리턴
		return value;
	}

	//맨 앞의 노드를 tmp에 기억
	tmp = queue->front;
	//반환할 값은 tmp의 data로 설정
	value = tmp->data;
	//맨 앞은 tmp의 다음 노드로 설정
	queue->front = tmp->next;
	//tmp 노드 해제
	free(tmp);
	//큐 길이 1 감소
	queue->length--;
	//반환
	return value;
}
void Display(Queue* queue) {
	int len = queue->length;
	Node* current = queue->front;
	for (int i = 0; i < len; i++) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main(void)
{
	Queue queue;

	//큐 초기화
	InitQueue(&queue);

	for (int i = 1; i <= 5; i++)
	{
		Enqueue(&queue, i);
	}
	Display(&queue);
	while (!IsEmpty(&queue))
	{
		printf("Dequeue [%d]\n", Dequeue(&queue));
	}
	Display(&queue);
	return 0;
}