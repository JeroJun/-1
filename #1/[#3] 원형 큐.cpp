/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/

#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef struct element {
	int key;
}element;

//front �� rear�� -1�� �ʱ�ȭ
int front = -1;
int rear = -1;

//���ο� ť ����
element queue[MAX_QUEUE_SIZE];

//front �� rear�� ���ٸ� ť�� ����ִ� ���̴�
int isEmpty(void) {
	return front == rear ? true : false;
}
//ť�� �����ִ��� Ȯ���ϴ� �޼ҵ�
int isFull(void) {
	//rear + 1 �� ť �ִ� ũ��� ������ ������ ���� 0�� �Ǹ� ť�� �����ִ� ���̴�.
	return (rear + 1) % MAX_QUEUE_SIZE == front ? true : false;
}
//ť ��� ���� �޼ҵ�
void addQ(element item) {
	if (isFull()) //���� �����ִٸ�
		printf("Overflow\n");
	else { //�׷��� �ʴٸ� rear�� ���� �� ������ ����
		queue[++rear] = item;
	}
}
//ť ��� ���� �޼ҵ�
element delQ() {
	if (isEmpty()) { //���� ť�� ����ִٸ�
		printf("Underflow\n");
	}
	else {
		//ť�� ����Ʈ�� ��ĭ �����ϰ� ����
		return queue[front = (front + 1) % MAX_QUEUE_SIZE];
	}
}
void Display() {
	//ť�� ������� �ʴٸ�
	if (!isEmpty()) {
		//i�� ��������
		int i = front;
		//i�� rear�� �����ϱ� ������
		while (i != rear) {
			//i �� ������Ų�� (mod ���� ���, �������� ���ϱ�)
			i = ++i % MAX_QUEUE_SIZE;
			//����Ѵ�
			printf("[%d] ", queue[i].key);
		}
	}
	printf("\n");
}

int main() {

	for (int i = 0; i < 10; i++) {
		addQ({ i });
		Display();
	}
	for (int i = 0; i < 11; i++) {
		delQ();
		Display();
	}
	return 0;
}

