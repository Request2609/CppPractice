/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Nov 2018 08:20:06 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LettersNum 6
#define TextCharTypeNum 54
typedef struct{//三叉链表的结点结构体定义
	int weight;
	int Parent;
	int Lchild;
	int Rchild;
}HFTreeNode;
void SelectTwoMinimumWeightNodes(HFTreeNode Tree[],int Range,int *Node1,int *Node2)//在哈夫曼树数组从第一个元素到第Range元素找出两个不重复的权值最小的树结点
{
    int cmp = 998,i;
    for(i=1;i<=Range;i++)
    {
        if(Tree[i].weight<cmp&&Tree[i].Parent==0)
        {
            cmp = Tree[i].weight;
            *Node1 = i;
        }
    }
    cmp = 998;
    for(i=1;i<=Range;i++)
    {
        if((Tree[i].weight<cmp)&&Tree[i].Parent==0&&i!=*Node1)
        {
            cmp = Tree[i].weight;
            *Node2 = i;
        }
    }
    return;
}

void CreateHuffmanTree(HFTreeNode *Tree,int weights[],int LeafsNum)//由于大小固定哈夫曼树的存储采用静态三叉链表自底而顶构建
{
    int NodesNum = 2*LeafsNum-1;//整棵树结点数
    int i;
    int Node1,Node2;

    for(i=1;i<=LeafsNum;i++){Tree[i].weight = weights[i-1];Tree[i].Parent=Tree[i].Lchild=Tree[i].Rchild=0;}//初始前n个元素作为根基
    for(i=LeafsNum+1;i<=NodesNum;i++){Tree[i].weight = Tree[i].Parent = Tree[i].Lchild = Tree[i].Rchild = 0;}
    for(i=LeafsNum+1;i<=NodesNum;i++)
    {
        SelectTwoMinimumWeightNodes(Tree,i-1,&Node1,&Node2);
        Tree[i].weight = Tree[Node1].weight+Tree[Node2].weight;//子母结点的连接
        Tree[i].Lchild = Node1;
        Tree[i].Rchild = Node2;
        Tree[Node1].Parent = i;
        Tree[Node2].Parent = i;
    }
    return;
}
void PrintTreeContent(HFTreeNode *Tree,int LeafsNum)
{
    int i;
    for(i = 1;i<=2*LeafsNum-1;i++)
    {
        printf("%d %d %d %d\n",Tree[i].weight,Tree[i].Parent,Tree[i].Lchild,Tree[i].Rchild);

    }
    return;
}
void SetBinaryCode(HFTreeNode *Tree,int WhichLetter,char **Aim)
{
    int Codelength = 0,i=WhichLetter,j;
    while(Tree[i].Parent!=0)
    {
        i = Tree[i].Parent;
        Codelength++;
    }
    *Aim = (char*)malloc((Codelength+1)*sizeof(char));

    i = WhichLetter;
    for(j=Codelength-1;j>=0;j--)
    {
        if(Tree[Tree[i].Parent].Lchild==i)
        {
            (*Aim)[j] = '0';
            i = Tree[i].Parent;

        }
        else if(Tree[Tree[i].Parent].Rchild==i)
        {
            (*Aim)[j] = '1';
            i = Tree[i].Parent;
        }

    }
    (*Aim)[Codelength]='\0';
    return;
}
void PrintLetterCorrespondingCodes(char *Codes[],int CodesSize,char ValidLetters[])
{
    int i;
    for(i=0;i<CodesSize;i++)
    {
        printf("%c:%s\n",ValidLetters[i],Codes[i]);
    }
    return;
}
void Encode(char *Aim,char *Codes[],int CodesSize,char ValidLetters[])//字母转为01串
{
    int i,j;
    for(i=0;i<strlen(Aim);i++)
    {
        for(j=0;j<CodesSize;j++)
        {
            if(Aim[i]==ValidLetters[j]){printf("%s",Codes[j]);break;}
        }
    }
    return;
}
void Decode(char *Aim,char *Codes[],int CodesSize,char ValidLetters[])//01串转为字母
{//0010000100111101测试数据
    int i,j,k,maxCodeLength=0,maxcmp,check,flag,AimLen;
    for(i=0;i<CodesSize;i++)if(strlen(Codes[i])>maxCodeLength)maxCodeLength = strlen(Codes[i]);
    //printf("最长码长度%d\n",maxCodeLength);
    AimLen = strlen(Aim);
    //printf("二进制串长度%d\n",AimLen);
    i=0;
    while(i<AimLen)
    {

        flag = 0;
        maxcmp = 0;
        for(k=0;k<CodesSize;k++)
        {
            j = 0;
            for(check=i;check<i+maxCodeLength&&check<AimLen;check++)
            {
                if(Aim[check]!=Codes[k][check-i])break;
                else j++;
            }
            if(j>maxcmp)
            {
                maxcmp = j;
                flag = k;

            }
        }
        printf("%c",ValidLetters[flag]);
        i+=strlen(Codes[flag]);
        //printf("此段译码长度%d\n",strlen(Codes[flag]));
    }
    return;
}
void CountTextCharNums(int *TextCharWeights,char Text[])
{
    int i;
    for(i=0;i<TextCharTypeNum;i++)
    {
        TextCharWeights[i]=0;
    }
    for(i=0;i<strlen(Text);i++)
    {
        if(Text[i]==' ')TextCharWeights[TextCharTypeNum-2]++;
        else if(Text[i]=='.')TextCharWeights[TextCharTypeNum-1]++;
        else if(Text[i]>='A'&&Text[i]<='Z')TextCharWeights[Text[i]-'A']++;
        else if(Text[i]>='a'&&Text[i]<='z')TextCharWeights[Text[i]-'a'+(TextCharTypeNum-2)/2]++;

    }
    return;
}
float ComputeAverageBinStrLength(char *Codes[],int CodesSize)
{
    unsigned i;
    float result,Sum=0;
    for(i=0;i<CodesSize;i++)
    {
        Sum += strlen(Codes[i]);
    }
    result = Sum/(float)CodesSize;
    return result;
}
int GetValidWeightsNum(int weights[])
{
    int i,Num=0;
    for(i=0;i<TextCharTypeNum;i++)
    {
        if(weights[i]>0)Num++;
    }
    return Num;
}
void CopytoNewWeightsArr(int *NewWeights,int OldWeights[],char *ValidLetters,int ValidWeights,char TextChar[])
{
    int i,k=0;
    for(i=0;i<ValidWeights;i++)
    {
        NewWeights[i] = 0;
    }
    for(i=0;i<TextCharTypeNum;i++)
    {
        if(OldWeights[i]>0&&k<ValidWeights)
        {
            NewWeights[k] = OldWeights[i];
            ValidLetters[k] =  TextChar[i];
            k++;
        }

    }
    return;
}
int main()
{
    int i;
	char TextChar[TextCharTypeNum];
	for(i=0;i<TextCharTypeNum;i++)
    {
        if(i<(TextCharTypeNum-2)/2)TextChar[i]='A'+i;
        else if(i<TextCharTypeNum-2)TextChar[i]='a'+i-(TextCharTypeNum-2)/2;
        else if(i==TextCharTypeNum-2)TextChar[i]=' ';
        else if(i==TextCharTypeNum-1)TextChar[i]='.';

        //printf("%c",TextChar[i]);
    }
	char Text[200],buf;
	for(i=0;i<200;i++)Text[i]='\0';
	i=0;
	while(i<200)//给Text赋值
    {
        buf = getchar();
        if(buf=='\n')continue;
        else if(buf=='#')break;
        else Text[i++]=buf;
    }

	int TextCharWeights[TextCharTypeNum];//未缩减前的weights数组
	int ValidWeights;//weight不为零的字符数量


	CountTextCharNums(TextCharWeights,Text);//统计Text里所有字符数量
	ValidWeights = GetValidWeightsNum(TextCharWeights);
	int Weights[ValidWeights];//仅有非零weight的weights数组
    char ValidLetters[ValidWeights];
	char *Codes[ValidWeights];
    CopytoNewWeightsArr(Weights,TextCharWeights,ValidLetters,ValidWeights,TextChar);

    HFTreeNode HFTree[ValidWeights*2];
    CreateHuffmanTree(HFTree,Weights,ValidWeights);
    //PrintTreeContent(HFTree,TextCharTypeNum);
    for(i=0;i<ValidWeights;i++)SetBinaryCode(HFTree,i+1,&Codes[i]);
    PrintLetterCorrespondingCodes(Codes,ValidWeights,ValidLetters);
    Encode(Text,Codes,ValidWeights,ValidLetters);
    printf("\n");
    char BinStr[3000];
    i=0;
    getchar();
    while(i<3000)
    {
        buf = getchar();
        if(buf=='1'||buf=='0')BinStr[i++]=buf;
        else {BinStr[i++]='\0';break;}
    }
    //printf("\n%s\n",BinStr);
    Decode(BinStr,Codes,ValidWeights,ValidLetters);
    printf("\n%.2f\n",ComputeAverageBinStrLength(Codes,ValidWeights));
	return 0;
}

