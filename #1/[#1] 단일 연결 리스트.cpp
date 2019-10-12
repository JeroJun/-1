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

	//���ο� ��带 �����մϴ�.
	node* tmp = (node*)malloc(sizeof(node));
	//�Ű������� �޾ƿ� �����͸� ���ο� ����� ������ �����մϴ�.
	tmp->data = data;
	//���� ������ ����� ���� ���� NULL�̾�� �մϴ�.
	tmp->next = head->next;
	//��� ����� �ڽ��� ������ϴ�. next�� ���ο� ��带 ���� �����մϴ�.
	head->next = tmp;
	//�Ϸ�
	if (output) printf("[%d] added!\n", data);
}
void deleteNode(node* prev, bool output = false) {

	//���� ��尡 ������ �ִ� ������带 Ÿ������ ����
	node* target = prev->next;
	//������ ��尡 ����Ű�� �ִ� ������带 �� ���� �̾��ݴϴ�.
	prev->next = target->next;
	//����
	if (output) printf("[%d] removed!\n", target->data);
	free(target);
	//�Ϸ�
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