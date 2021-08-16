#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 45

/*定义结构*/
struct film {
	char names[LEN];
	int rating;
	struct film * next;
};

/*相当于gets函数的优化版本*/
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
	
	/*收集并存储信息*/
	puts("请输入电影的名字(输入一个空行退出循环):");
	while(s_gets(input, LEN) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if(head == NULL)                          //第一个结构
		{
			head = current;
		}
		else                                      //第二个及以后的结构
		{
			prev->next = current;
		}
		strcpy(current->names, input);
		puts("请输入电影的评级:");
		scanf("%d", &current->rating);
		eatline();
		puts("请输入下一部电影的名字(输入一个空行退出循环）:");
		prev = current;
	}
	
	/*显示电影列表*/
	if(head == NULL)
	{
		puts("你没有输入东西。");
	}
	else
	{
		puts("电影列表如下所示:");
		current = head;
		while(current->next != NULL)
		{
			printf("电影名：%s, 电影评级：%d\n", current->names, current->rating);
			current = current->next;
		}
	}
	
	/*释放内存*/
	current = head;
	while(current->next !=  NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
	
	puts("全部完成了！");
	
	return 0;
}
