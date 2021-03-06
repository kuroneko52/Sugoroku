// ConsoleApplication1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define DICE_NUMBER 10
#define TROUT_NUMBER 30

int ThrowDices(int n)
{
	int	sum = 0;

	for (int i = 0; i < n; i++)
		sum += ((rand() % 3) + 1);

	return sum;
}

void ShowBoard(int pos)
{
	for (int i = 0; i < pos; i++)
		cout << "_ ";

	cout << "▲";

	for (int i = pos + 1; i < 30; i++)
		cout << "_ ";

	cout << "|上がり！" << endl;
}

int main()
{
	int	replay;

	srand((unsigned int)time(NULL));

	cout << "▲すごろく▼" << endl;
	cout << "30マス先にゴールがあります。" << endl;
	cout << "1,2,3の３つの目を持つ特別なサイコロ10個を、好きな数だけ振って駒を進めます。" << endl;
	cout << "ぴったり上がりに止まれば終わりです。目の数が多ければ、余った目の数だけ戻ります。" << endl;
	cout << "----------------------------------------------" << endl;

	do
	{
		int	position = 0;

		ShowBoard(position);

		for (int turn = 1; ; turn++)
		{
			int	n;
			int	me;

			while (1)
			{
				cout << "残り" << TROUT_NUMBER - position << "マスです。サイコロの数は？";
				cin >> n;

				if (n <= DICE_NUMBER)
					break;
				else
					printf("サイコロは10個までです。");
			}

			me = ThrowDices(n);

			cout << "出た目の合計 " << me;

			position += me;

			if (position == TROUT_NUMBER)
			{
				cout << "おめでとう！！ " << turn << "回目で上がりです" << endl;
				break;
			}

			if (position > TROUT_NUMBER)
				position = TROUT_NUMBER - (position - TROUT_NUMBER);

			ShowBoard(position);
		}

		cout << "もう一度やりますか？（Yes:1 No:0）" << endl;
		cin >> replay;

	} while (replay != 0);

	return 0;
}

