#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct NodeChuoi
{
	char data[10];
	NodeChuoi *pnext;
};
struct NodeKitu
{
	char data;
	NodeKitu *pnext;
};
struct NodeSothuc
{
	double data;
	NodeSothuc *pnext;
};
struct StackKitu
{
	NodeKitu *Phead;
};
struct StackSothuc
{
	NodeSothuc *Phead;
};
struct Queue
{
	NodeChuoi *Phead;
	NodeChuoi *Ptail;
};
void KhoitaoStack(StackSothuc &stacksothuc, StackKitu &stackkitu)
{
	stacksothuc.Phead = NULL;
	stackkitu.Phead = NULL;
}
NodeChuoi *TaoNodeChuoi(char *chuoi)
{
	NodeChuoi *node = (NodeChuoi*)malloc(sizeof(NodeChuoi));
	strcpy_s(node->data, chuoi);
	node->pnext = NULL;
	return node;
}
NodeKitu *TaoNodeKitu(char kitu)
{
	NodeKitu *node = (NodeKitu*)malloc(sizeof(NodeKitu));
	node->data = kitu;
	node->pnext = NULL;
	return node;
}
NodeSothuc *TaoNodeSothuc(double sothuc)
{
	NodeSothuc *node = (NodeSothuc*)malloc(sizeof(NodeSothuc));
	node->data = sothuc;
	node->pnext = NULL;
	return node;
}
void KhoitaoQueue(Queue &queue)
{
	queue.Phead = queue.Ptail = NULL;
}
bool isEmptyChuoi(Queue queue)
{
	if (queue.Phead == NULL)
		return true;
	return false;
}
bool isEmptyKitu(StackKitu stackkitu)
{
	if (stackkitu.Phead == NULL)
		return true;
	return false;
}
bool isEmptySothuc(StackSothuc stacksothuc)
{
	if (stacksothuc.Phead == NULL)
		return true;
	return false;
}
bool PopKitu(StackKitu &stackkitu, char &kitu)//lay kitu
{
	if (isEmptyKitu(stackkitu) == false)
	{
		NodeKitu *node = stackkitu.Phead;
		kitu = node->data;
		stackkitu.Phead = stackkitu.Phead->pnext;
		delete node;
		return true;
	}
	else
		return false;
}
bool PopSothuc(StackSothuc &stacksothuc, double &sothuc)//lay so thuc
{
	if (isEmptySothuc(stacksothuc) == false)
	{
		NodeSothuc *node = stacksothuc.Phead;
		sothuc = node->data;
		stacksothuc.Phead = stacksothuc.Phead->pnext;
		delete node;
		return true;
	}
	else
		return false;
}
char top(StackKitu stackkitu)
{
	return stackkitu.Phead->data;
}
bool PushKitu(StackKitu &stackkitu, NodeKitu *node)
{
	node->pnext = stackkitu.Phead;
	stackkitu.Phead = node;
	return true;
}
bool PushSothuc(StackSothuc &stacksothuc, NodeSothuc *node)
{
	node->pnext = stacksothuc.Phead;
	stacksothuc.Phead = node;
	return true;
}
bool deQueue(Queue &queue, char chuoi[])
{
	if (isEmptyChuoi(queue) == false)
	{
		NodeChuoi *node = queue.Phead;
		strcpy(chuoi, node->data);
		queue.Phead = queue.Phead->pnext;
		delete node;
		return true;
	}
	else
		return false;
}
bool enQueue(Queue &queue, NodeChuoi *node)
{
	if (queue.Phead == NULL)
	{
		queue.Phead = queue.Ptail = node;
		return true;
	}
	else
	{
		queue.Ptail->pnext = node;
		queue.Ptail = node;
		return true;
	}
	return false;
}
bool KiemtraUuTien(char a, char b)//kiem tra do uu tien cua phep toan
{
	switch (a)
	{
	case '+':case '-':if (b == '+' || b == '-')
		return true;
			 else
		return false;
	case '!': return true;
	case '^': if (b == '*' || b == '/' || b == '+' || b == '-' || b == '^')
		return true;
			  else return false;
	case '*':case '/':if (b == '*' || b == '/' || b == '+' || b == '-')
		return true;
			 else
		return false;
	}
}
void xoaKhoangTrang(char bieuthuc[])///////////////////
{
	while (bieuthuc[0] == ' ')//xoa khoang trang o dau
	{
		for (int i = 0; i < strlen(bieuthuc); i++)
		{
			bieuthuc[i] = bieuthuc[i + 1];
		}
	}
	while (bieuthuc[strlen(bieuthuc)] == ' ')//xoa khoang trang o cuoi
	{
		bieuthuc[strlen(bieuthuc)] = '\0';
	}
	for (int i = 0; i < strlen(bieuthuc); i++)//xoa khoang trang o giua
	{
		if (bieuthuc[i] == ' ')
		{
			for (int j = i; j <= strlen(bieuthuc); j++)
			{
				bieuthuc[j] = bieuthuc[j + 1];
			}
			i--;
		}
	}
}
void chen(char *&bieuthuc, int vt)
{
	for (int i = strlen(bieuthuc); i >= vt; i--)////////////
	{
		bieuthuc[i + 1] = bieuthuc[i];
	}
	bieuthuc[vt] = '0';
}
void Hauto(char bieuthuc[], Queue &queue, StackKitu &stackkitu)
{
	for (int i = 0; i < strlen(bieuthuc); i++)////////////
	{
		if (bieuthuc[i] == '('&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] == '(')
		{
			chen(bieuthuc, i + 1);
		}
	}
	int i = 0;
	if (bieuthuc[0] == '-' && (bieuthuc[1] >= '0'&&bieuthuc[1] <= '9'))//kiem tra dau tien la -number+....
	{
		char chuoi2[10] = "";
		int j = 0;
		chuoi2[j] = '-';
		j++;
		i++;
		while (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9' || bieuthuc[i] == '.')
		{
			chuoi2[j++] = bieuthuc[i];
			i++;
		}
		NodeChuoi *node2 = TaoNodeChuoi(chuoi2);
		enQueue(queue, node2);
	}
	if (bieuthuc[0] == '-'&&bieuthuc[1] == '(')//kiem tra dau tien la -(
	{
		int j = 0;
		char chuoi1[2] = "";
		chuoi1[0] = '0';
		NodeChuoi *node1 = TaoNodeChuoi(chuoi1);
		enQueue(queue, node1);
		i++;
		NodeKitu *node = TaoNodeKitu(bieuthuc[0]);
		PushKitu(stackkitu, node);
	}
	while (i < strlen(bieuthuc))
	{
		if (bieuthuc[i] == '(')
		{
			if (bieuthuc[i] == '('&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] >= '0'&&bieuthuc[i + 2] <= '9')
			{
				char c1;
				c1 = '(';
				NodeKitu *node = TaoNodeKitu(c1);
				PushKitu(stackkitu, node);
				i++;
				char chuoi6[10] = "";
				int j = 0;
				chuoi6[j] = '-';
				j++;
				i++;
				while (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9' || bieuthuc[i] == '.')
				{
					chuoi6[j++] = bieuthuc[i];
					i++;
				}
				NodeChuoi *node1 = TaoNodeChuoi(chuoi6);
				enQueue(queue, node1);
			}
			else
			{
				char c1;
				c1 = '(';
				NodeKitu *node = TaoNodeKitu(c1);
				PushKitu(stackkitu, node);
				i++;
			}
		}
		else if (bieuthuc[i] == ')')
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				char c2[2] = "";
				PopKitu(stackkitu, c2[0]);
				NodeChuoi *node = TaoNodeChuoi(c2);
				enQueue(queue, node);
			}
			i++;
			if (isEmptyKitu(stackkitu) == false && top(stackkitu) == '(')
			{
				char ktu;
				PopKitu(stackkitu, ktu);//lay dau ( ra khoi stack kitu
			}
		}
		else if (bieuthuc[i] == '+'&& bieuthuc[i + 1] == '-')// co dang +-
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), bieuthuc[i + 1]))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			if (isEmptyKitu(stackkitu) == false && top(stackkitu) == '(')
			{
				char ktu;
				PopKitu(stackkitu, ktu);//lay dau ( ra khoi stack kitu
			}
			char ktu1;//dua dau - vao stack
			ktu1 = bieuthuc[i + 1];
			NodeKitu *node = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node);
			i += 2;
		}
		else if (bieuthuc[i] == '-'&&bieuthuc[i + 1] == '-')// co dang --
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), bieuthuc[i + 1]))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu1;//dua dau + vao stack
			ktu1 = '+';
			NodeKitu *node = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node);
			i += 2;
		}
		else if (bieuthuc[i] == '/'&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] != '(')//co dang /-
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), bieuthuc[i]))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu1;//dua dau + vao stack
			ktu1 = bieuthuc[i];
			NodeKitu *node = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node);
			i++;
			if (bieuthuc[i] == '-')
			{
				char chuoi2[10] = "";
				int j = 0;
				chuoi2[j] = '-';
				j++;
				i++;
				while (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9' || bieuthuc[i] == '.')
				{
					chuoi2[j++] = bieuthuc[i];
					i++;
				}
				NodeChuoi *node2 = TaoNodeChuoi(chuoi2);
				enQueue(queue, node2);
			}
		}
		else if (bieuthuc[i] == '*'&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] != '(')//co dang *-
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), bieuthuc[i]))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu1;
			ktu1 = bieuthuc[i];
			NodeKitu *node = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node);
			i++;
			if (bieuthuc[i] == '-')
			{
				char chuoi2[10] = "";
				int j = 0;
				chuoi2[j] = '-';
				j++;
				i++;
				while (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9' || bieuthuc[i] == '.')
				{
					chuoi2[j++] = bieuthuc[i];
					i++;
				}
				NodeChuoi *node2 = TaoNodeChuoi(chuoi2);
				enQueue(queue, node2);
			}
		}
		else if (bieuthuc[i] == '*'&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] == '(')//co dang )*-(
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), bieuthuc[i]))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu1;
			ktu1 = bieuthuc[i];
			NodeKitu *node1 = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node1);
			i++;
			if (bieuthuc[i] == '-')//chen so -1 vao giua
			{
				char chuoi2[5] = "";
				chuoi2[0] = '-';
				chuoi2[1] = '1';
				NodeChuoi *node2 = TaoNodeChuoi(chuoi2);
				enQueue(queue, node2);
			}
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), '*'))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu5;
			ktu5 = '*';
			NodeKitu *node5 = TaoNodeKitu(ktu5);
			PushKitu(stackkitu, node5);
			i++;
		}
		else if (bieuthuc[i] == '/'&&bieuthuc[i + 1] == '-'&&bieuthuc[i + 2] == '(')//co dang )*-(
		{
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				char kitunhan = '*';
				if (KiemtraUuTien(top(stackkitu), kitunhan))//kiem tra do uu tien cua ki tu nhan
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu1;
			ktu1 = '*';
			NodeKitu *node1 = TaoNodeKitu(ktu1);
			PushKitu(stackkitu, node1);
			i++;
			if (bieuthuc[i] == '-')//chen so -1 vao giua
			{
				char chuoi2[5] = "";
				chuoi2[0] = '-';
				chuoi2[1] = '1';
				NodeChuoi *node2 = TaoNodeChuoi(chuoi2);
				enQueue(queue, node2);
			}
			while (isEmptyKitu(stackkitu) == false && top(stackkitu) != '(')
			{
				if (KiemtraUuTien(top(stackkitu), '/'))
				{
					char c[2] = "";
					PopKitu(stackkitu, c[0]);
					NodeChuoi *node3 = TaoNodeChuoi(c);
					enQueue(queue, node3);

				}
				else
					break;
			}
			char ktu5;
			ktu5 = '/';
			NodeKitu *node5 = TaoNodeKitu(ktu5);
			PushKitu(stackkitu, node5);
			i++;
		}
		else if (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9')
		{
			char chuoi5[10] = "";
			int j = 0;
			while (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9' || bieuthuc[i] == '.')
			{
				chuoi5[j++] = bieuthuc[i];
				i++;
			}
			NodeChuoi *node = TaoNodeChuoi(chuoi5);
			enQueue(queue, node);
		}
		else
		{
			while (isEmptyKitu(stackkitu) == false && KiemtraUuTien(top(stackkitu), bieuthuc[i]) == true && top(stackkitu) != '(')
			{
				char kitu[2] = "";
				PopKitu(stackkitu, kitu[0]);
				NodeChuoi *node = TaoNodeChuoi(kitu);
				enQueue(queue, node);
			}
			NodeKitu *node = TaoNodeKitu(bieuthuc[i]);//them phep toan vao stack
			PushKitu(stackkitu, node);
			i++;
		}
	}

	while (isEmptyKitu(stackkitu) == false)//lay phan con lai trong stack
	{
		char c[2] = "", kitu;
		PopKitu(stackkitu, kitu);
		c[0] = kitu;
		NodeChuoi *node = TaoNodeChuoi(c);
		enQueue(queue, node);
	}
}
double luythua(double numberone, double numbertwo)
{
	return pow(numbertwo, numberone);
}
double giaithua(double number)
{
	if (number == 0 || number == 1)
		return 1;
	double gt = 1;
	for (int i = number; i > 0; i--)
	{
		gt = gt * i;
	}
	return gt;
}
double Tinhtoan(double numberone, double numbertwo, char pheptoan)
{
	switch (pheptoan)
	{
	case '+':return numbertwo + numberone; break;
	case '-':return numbertwo - numberone; break;
	case '/':return numbertwo / numberone; break;
	case '*':return numbertwo * numberone; break;
	case '^':return luythua(numberone, numbertwo);
	}
}
bool SuLytinhtoan(StackSothuc &stacksothuc, Queue &queue)
{
	//double values;
	while (queue.Phead != NULL)
	{
		char dulieu[10] = "";
		deQueue(queue, dulieu);
		if ((dulieu[0] >= '0'&&dulieu[0] <= '9') || dulieu[0] == '-' && (dulieu[1] >= '0'&&dulieu[1] <= '9'))
		{
			double value1;
			value1 = atof(dulieu);
			NodeSothuc *node = TaoNodeSothuc(value1);
			PushSothuc(stacksothuc, node);
		}
		else if (dulieu[0] == '!')////////////////////////////
		{
			double data;
			PopSothuc(stacksothuc, data);
			double kt = data;
			if (data - (int)kt != 0)
				return false;
			double value = giaithua(data);///////////////////
			NodeSothuc *node = TaoNodeSothuc(value);
			PushSothuc(stacksothuc, node);
		}
		else
		{
			double data1, data2, value;
			char c = dulieu[0];
			PopSothuc(stacksothuc, data1);
			PopSothuc(stacksothuc, data2);
			value = Tinhtoan(data1, data2, c);
			NodeSothuc *node = TaoNodeSothuc(value);
			PushSothuc(stacksothuc, node);
		}
	}
	return true;
}
bool kiemTraBieuThuc(char *bieuthuc)///////////////////////////////
{
	if (bieuthuc[0] == '*' || bieuthuc[0] == '/' || bieuthuc[0] == '^' || bieuthuc[0] == '!' || bieuthuc[strlen(bieuthuc)] == '+' || bieuthuc[strlen(bieuthuc)] == '-' || bieuthuc[strlen(bieuthuc)] == '*' || bieuthuc[strlen(bieuthuc)] == '/' || bieuthuc[strlen(bieuthuc)] == '^')
		return false;
	StackKitu stack;
	stack.Phead = NULL;
	for (int k = 0; k < strlen(bieuthuc); k++)//kiem tra thu tu dong mo ngoac
	{
		if (bieuthuc[k] == '(')
		{
			NodeKitu *node = TaoNodeKitu(bieuthuc[k]);
			PushKitu(stack, node);
		}
		else if (bieuthuc[k] == ')')
		{
			char kitu;
			PopKitu(stack, kitu);
			if (kitu != '(')
				return false;
			else continue;
		}
	}
	if (stack.Phead != NULL)
		return false;
	for (int i = 0; i < strlen(bieuthuc) - 1; i++)
	{
		if ((bieuthuc[i] == '+' || bieuthuc[i] == '-' || bieuthuc[i] == '*' || bieuthuc[i] == '/') && (bieuthuc[i + 1] == '*' || bieuthuc[i + 1] == '/' || bieuthuc[i + 1] == '^' || bieuthuc[i + 1] == '!'))
			return false;
		if (bieuthuc[i] >= '0'&&bieuthuc[i] <= '9'&&bieuthuc[i + 1] == '(')
			return false;
		if (bieuthuc[i] == '(' && (bieuthuc[i + 1] == '*' || bieuthuc[i + 1] == '/' || bieuthuc[i + 1] == '^' || bieuthuc[i + 1] == '!'))
			return false;
		if ((bieuthuc[i] == '+' || bieuthuc[i] == '-' || bieuthuc[i] == '*' || bieuthuc[i] == '/' || bieuthuc[i] == '^' || bieuthuc[i] == '!') && bieuthuc[i + 1] == ')')
			return false;

	}
	return true;
}
void main(int argc, char *argv[])
{

	StackSothuc stacksothuc;
	StackKitu stackkitu;
	Queue queue;
	char bieuthuc[100];
	char fileInput[100];
	KhoitaoStack(stacksothuc, stackkitu);
	KhoitaoQueue(queue);
	strcpy(fileInput, argv[1]);
	FILE *fileinput = fopen(fileInput, "rt");
	if (fileinput == NULL)
	{
		printf("Khong doc duoc file !!");
		return;
	}
	else
	{
		fgets(bieuthuc, 255, fileinput);
		xoaKhoangTrang(bieuthuc);
		if (kiemTraBieuThuc(bieuthuc) == false)
			printf("Bieu thuc sai cu phap !!\n");
		else
			Hauto(bieuthuc, queue, stackkitu);

		if (kiemTraBieuThuc(bieuthuc) == false || SuLytinhtoan(stacksothuc, queue) == false)
		{
			printf("Bieu thuc sai cu phap !!\n");
		}
		else
		{
			double giatri;
			PopSothuc(stacksothuc, giatri);
			printf("Gia tri bieu thuc la: %f\n", giatri);
		}
	}
	fclose(fileinput);
	system("pause");
}