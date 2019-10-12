/**************************************
----------------------------------------
	 Coded by KIM JUN YOUNG
----------------------------------------
**************************************/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	//이중연결리스트는 링크가 2개이다.
	node* prev;
	node* next;
};

struct list {
	int length;
	node* tail;
};

// 리스트 생성
list* CreateList()
{
	//새로운 원형 리스트 생성
	list* newList = (list*)malloc(sizeof(list));

	//만약 메모리 할당에 실패하면 --> NULL 메모리 역참조 예외처리
	if (newList == NULL)
	{
		printf("Memory Error!\n");
	}
	else {
		//새로운 리스트의 tail은 null을 가르킨다.
		newList->tail = NULL;
		newList->length = 0;
	}

	return newList;
}

// 노드 삽입
void AddNode(list* list, int position, node element)
{
	node* preNode = list->tail;
	node* newNode = (node*)malloc(sizeof(node));

	//만약 메모리 할당에 실패하면 --> NULL 메모리 역참조 예외처리
	if (newNode == NULL) {
		printf("Memory Error!");
	}
	else {
		//데이터 삽입
		newNode->data = element.data;

		//만약 리스트가 비어있었던 상태라면
		if (list->length == 0)
		{
			//새로운 노드의 next와 prev모두 자기 자신을 가르켜 원형 순환을 표현한다.
			newNode->next = newNode;
			newNode->prev = newNode;

			//tail 또한 새로운 노드를 가르킨다.
			list->tail = newNode;
		}
		else
		{
			//삽입 위치까지 preNode를 통해 이동
			for (int i = 0; i < position; i++)
			{
				preNode = preNode->next;
			}

			//새로운 노드는 전노드의 next를 가져온다.
			newNode->next = preNode->next;
			//새로운 노드의 전노드는 preNode이다.
			newNode->prev = preNode;
			//새로운 노드의 다음 노드가 가르키던 이전노드는 더이상 preNode가 아닌 새로운 노드를 가르킨다.
			newNode->next->prev = newNode;
			//preNode의 다음 노드는 새로운 노드이다.
			preNode->next = newNode;

			//만약 현재 위치가 원형 리스트의 마지막 위치라면 tail은 새로운 노드다.
			if (position == list->length)
			{
				list->tail = newNode;
			}
		}

		//리스트 길이 증가
		list->length++;
	}
}


// 노드 삭제
void DelNode(list* list, int position)
{
	node* preNode = list->tail;
	node* delNode = list->tail;

	//원형 리스트가 비어있다면
	if (list->length == 0)
	{
		printf("List Empty!\n");

		//tail을 null로 확인 설정
		list->tail = NULL;
	}
	else
	{
		//삭제 위치까지 이동한다.
		for (int i = 0; i < position; i++)
		{
			preNode = preNode->next;
		}

		//삭제할 노드를 찾았다.
		delNode = preNode->next;

		//삭제할 노드는 자신이 가르키던 다음 노드를 이전 노드에게 넘겨준다.
		preNode->next = delNode->next;
		//삭제할 노드의 다음 노드의 이전 노드는 preNode이다.
		delNode->next->prev = preNode;
		//삭제
		free(delNode);

		//만약 끝에 위치한 요소라면 tail을 preNode로 변경시킨다.
		if (position == list->length - 1)
		{
			list->tail = preNode;
		}

		//리스트 길이 감소
		list->length--;
	}
}
//화면 출력
void Display(list* list)
{
	//임의 탐색용 변수를 생성한다. 첫번째 노드부터 시작한다.
	node* cur = list->tail->next;

	//리스트가 비어있다면
	if (list->length == 0)
	{
		printf("List Empty!\n");
		return;
	}

	//리스트의 길이까지 순회
	for (int i = 0; i < list->length; i++)
	{
		printf("[%d] ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//거꾸로 화면 출력
void BackDisplay(list* list)
{
	//임의 탐색용 변수를 생성한다. 마지막 노드부터 시작한다.
	node* node = list->tail;

	//리스트가 비어있다면
	if (list->length == 0)
	{
		printf("List Empty!\n");
		return;
	}

	//리스트 길이만큼 거꾸로 순회
	for (int i = list->length; i > 0; i--)
	{
		printf("[%d] ", node->data);
		node = node->prev;
	}
	printf("\n");
}

int main() {
	list* list;
	node node;
	list = CreateList();

	for (int i = 0; i < 6; i++) {
		node.data = i;
		AddNode(list, i, node);
	}
	Display(list);
	BackDisplay(list);

	DelNode(list, 0); DelNode(list, 3); DelNode(list, 2);

	Display(list);
	BackDisplay(list);

	return 0;
}