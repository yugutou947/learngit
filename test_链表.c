#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 45

/*����ṹ*/
struct film {
	char names[LEN];
	int rating;
	struct film * next;
};

/*�൱��gets�������Ż��汾*/
char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
		i++;
		if(st[i] == '\n')
		    st[i]='\0';
		else
		{
			while (getchar() != '\n')
			    continue;
		}
	}
	return ret_val;
}

void eatline(void)
{
	while(getchar() != '\n')
	{
		continue;
	}
}

int main(void)
{
	struct film * head;
	struct film * current, * prev;
	head = NULL;
	char input[LEN];
	
	/*�ռ����洢��Ϣ*/
	puts("�������Ӱ������(����һ�������˳�ѭ��):");
	while(s_gets(input, LEN) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if(head == NULL)                          //��һ���ṹ
		{
			head = current;
		}
		else                                      //�ڶ������Ժ�Ľṹ
		{
			prev->next = current;
		}
		strcpy(current->names, input);
		puts("�������Ӱ������:");
		scanf("%d", &current->rating);
		eatline();
		puts("��������һ����Ӱ������(����һ�������˳�ѭ����:");
		prev = current;
	}
	
	/*��ʾ��Ӱ�б�*/
	if(head == NULL)
	{
		puts("��û�����붫����");
	}
	else
	{
		puts("��Ӱ�б�������ʾ:");
		current = head;
		while(current->next != NULL)
		{
			printf("��Ӱ����%s, ��Ӱ������%d\n", current->names, current->rating);
			current = current->next;
		}
	}
	
	/*�ͷ��ڴ�*/
	current = head;
	while(current->next !=  NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
	
	puts("ȫ������ˣ�");
	
	return 0;
}
