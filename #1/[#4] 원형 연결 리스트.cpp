/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/
#include <stdio.h>
#include <stdlib.h>

//Pragma ���� ����
#pragma region Type Definition
//��� ����
struct Node
{
	int data;
	struct Node* next;
};

//Queue ����ü ����
struct Queue
{
	//�� ��(���� ��ġ)
	Node* front;
	//�� ��(������ ��ġ)
	Node* rear;
	//ť ����
	int length;
};
#pragma endregion

//ť �ʱ�ȭ �޼ҵ�
void InitQueue(Queue* queue)
{
	//front�� rear�� NULL�� ����
	queue->front = queue->rear = NULL;
	//ť ���̸� 0���� ����
	queue->length = 0;
}

//ť�� ������� Ȯ���ϴ� �޼ҵ�
int IsEmpty(Queue* queue)
{
	//���� ������ 0�̸� �� ����
	return queue->length == 0;
}

//ť ���� �޼ҵ�
void Enqueue(Queue* queue, int data)
{
	//���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	//NULL �޸� ������ ���� ���� --> �޸� �������� �Ҵ� ���н�
	if (newNode == NULL) exit(1);
	//�Ű����� data �� ���ο� ��� data ����
	newNode->data = data;
	//���ο� ����� ������ NULL
	newNode->next = NULL;


	if (IsEmpty(queue)) //ť�� ������� ��
	{
		//�� ���� ���ο� ���� ����
		queue->front = newNode;
	}
	else //ť�� ������� ���� ��
	{
		//�� ���� ������ ���ο� ���� ����
		queue->rear->next = newNode;
	}
	//�� �ڸ� ���ο� ���� ����
	queue->rear = newNode;
	//ť ���̸� 1 ����
	queue->length++;
}

//ť ��� ���� �޼ҵ�
int Dequeue(Queue* queue)
{
	//���� ���� ��Ƶδ� ����
	int value = 0;

	//�ӽ� ��� ������ ����
	Node* tmp;

	//ť�� ����� ��
	if (IsEmpty(queue))
	{
		//0�� ����
		return value;
	}

	//�� ���� ��带 tmp�� ���
	tmp = queue->front;
	//��ȯ�� ���� tmp�� data�� ����
	value = tmp->data;
	//�� ���� tmp�� ���� ���� ����
	queue->front = tmp->next;
	//tmp ��� ����
	free(tmp);
	//ť ���� 1 ����
	queue->length--;
	//��ȯ
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

	//ť �ʱ�ȭ
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