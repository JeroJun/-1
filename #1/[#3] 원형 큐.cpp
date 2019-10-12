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

//front 와 rear를 -1로 초기화
int front = -1;
int rear = -1;

//새로운 큐 정의
element queue[MAX_QUEUE_SIZE];

//front 와 rear가 같다면 큐는 비어있는 것이다
int isEmpty(void) {
	return front == rear ? true : false;
}
//큐가 꽉차있는지 확인하는 메소드
int isFull(void) {
	//rear + 1 을 큐 최대 크기로 나머지 연산한 값이 0이 되면 큐는 꽉차있는 것이다.
	return (rear + 1) % MAX_QUEUE_SIZE == front ? true : false;
}
//큐 요소 삽입 메소드
void addQ(element item) {
	if (isFull()) //만약 꽉차있다면
		printf("Overflow\n");
	else { //그렇지 않다면 rear를 증가 후 아이템 삽입
		queue[++rear] = item;
	}
}
//큐 요소 삭제 메소드
element delQ() {
	if (isEmpty()) { //만약 큐가 비어있다면
		printf("Underflow\n");
	}
	else {
		//큐의 프론트를 한칸 증가하고 리턴
		return queue[front = (front + 1) % MAX_QUEUE_SIZE];
	}
}
void Display() {
	//큐가 비어있지 않다면
	if (!isEmpty()) {
		//i를 시작으로
		int i = front;
		//i가 rear에 도달하기 전까지
		while (i != rear) {
			//i 를 증가시킨다 (mod 연산 사용, 원형으로 도니까)
			i = ++i % MAX_QUEUE_SIZE;
			//출력한다
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

