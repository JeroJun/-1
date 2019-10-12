#include <stdio.h>
#include <stdlib.h>

/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/

struct node
{
	int data;
	node* next;
};

void addNode(node* head, int data, bool output = false) {

	//새로운 노드를 생성합니다.
	node* tmp = (node*)malloc(sizeof(node));
	//매개변수로 받아온 데이터를 새로운 노드의 값으로 설정합니다.
	tmp->data = data;
	//새로 생성한 노드의 다음 노드는 NULL이어야 합니다.
	tmp->next = head->next;
	//헤드 노드의 자식이 생겼습니다. next를 새로운 노드를 향해 연결합니다.
	head->next = tmp;
	//완료
	if (output) printf("[%d] added!\n", data);
}
void deleteNode(node* prev, bool output = false) {

	//이전 노드가 가지고 있는 다음노드를 타겟으로 지정
	node* target = prev->next;
	//삭제할 노드가 가르키도 있던 다음노드를 전 노드와 이어줍니다.
	prev->next = target->next;
	//해제
	if (output) printf("[%d] removed!\n", target->data);
	free(target);
	//완료
}
int main() {

	//Create head node
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;

	//Add
	for (int i = 0; i < 50; i++)
	{
		addNode(head, i, true);
	}

	//Cycle variable creation
	node* current = head->next;

	//Final result
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL");

	//Delete
	for (int i = 0; i < 50; i++)
	{
		deleteNode(head);
	}

	return 0;
}