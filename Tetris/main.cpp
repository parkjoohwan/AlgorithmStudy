#include <random>
#include <conio.h>
#include <Windows.h>





enum : int

{

	LEFT = 75,

	RIGHT = 77,

	UP = 72,

	DOWN = 80,

	SPACE = 32

};

enum : int { EMPTY, BLOCK, WALL, SHADOW };



namespace

{

	const int _boardWidth = 10;

	const int _boardHeight = 20;

	int board[_boardWidth + 2][_boardHeight + 2];

	const char* _arrayTile[] = { ".", "бс","бр","в╠" };

}



class Block

{

private:

	int _currentX, _currentY;

	int _shadowY = 20;

	int _currentBlockState;

	int _nextBlockState;

	int _currentRotateState;

	struct Point { int _blockX, _blockY; };

	Point _blockShape[7][4][4] =

	{

		{ { 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 } },

	{ { 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 } },

	{ { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 },{ 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 } },

	{ { 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 },{ 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 } },

	{ { 0,0,-1,0,1,0,-1,-1 },{ 0,0,0,-1,0,1,-1,1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,1,-1 } },

	{ { 0,0,1,0,-1,0,1,-1 },{ 0,0,0,1,0,-1,-1,-1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } },

	{ { 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 },{ 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 } },

	};



public:

	void InitializeBlockState();

	int getRandomNumber(int min, int max);

	void gotoxy(int x, int y);

	void PrintOutBoard();

	void PrintInBoard();

	void PrintBlock(bool isBlock);

	int CheckBlockAround(int cx, int cy, int rot);



	int getCurrentX();

	int getCurrentY();

	int getCurrentRotateState();

	int getCurrentBlockState();

	int getNextBlockState();



	void setCurrentBlockState(int c);

	void setNextBlockState(int n);



	bool isMoveDown();

	bool isInputKey();

	void FullLineDelete();



	void PrintNextBlockBox();

	void PrintNextBlock(bool isBlock);

	void EmptyNextBlockBox();



	void PrintShadowBlock(bool isBlock);

};





void Block::gotoxy(int x, int y)

{



	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



void Block::InitializeBlockState()

{

	_currentX = _boardWidth / 2;

	_currentY = 3;

	_currentRotateState = 0;

}



int Block::getRandomNumber(int min, int max)

{

	std::random_device randomNumber;

	std::mt19937_64 randomNumberDevice(randomNumber());



	std::uniform_int_distribution<int> range(min, max);



	return range(randomNumberDevice);

}



void Block::PrintOutBoard()

{

	for (int i = 0; i < _boardWidth + 2; i++)

		for (int j = 0; j < _boardHeight + 2; j++)

		{

			if (i == 0 || i == _boardWidth + 1 || j == 0 || j == _boardHeight + 1)

				board[i][j] = WALL;

			else

				board[i][j] = EMPTY;

		}



	for (int i = 0; i < _boardWidth + 2; i++)

		for (int j = 0; j < _boardHeight + 2; j++)

		{

			gotoxy(i * 2, j);

			puts(_arrayTile[board[i][j]]);

		}

}



void Block::PrintInBoard()

{

	for (int i = 1; i < _boardWidth + 1; i++)

		for (int j = 1; j < _boardHeight + 1; j++)

		{

			gotoxy(i * 2, j);

			puts(_arrayTile[board[i][j]]);

		}

}



void Block::PrintBlock(bool isBlock)

{

	for (int i = 0; i < 4; i++)

	{

		gotoxy((_blockShape[_currentBlockState][_currentRotateState][i]._blockX + _currentX) * 2,

			_blockShape[_currentBlockState][_currentRotateState][i]._blockY + _currentY);

		puts(_arrayTile[isBlock ? BLOCK : EMPTY]);

	}

}



int Block::CheckBlockAround(int cx, int cy, int rot)

{

	int k = EMPTY;

	for (int i = 0; i < 4; i++)

		k = max(k,

			board[_blockShape[_currentBlockState][rot][i]._blockX + cx]

			[_blockShape[_currentBlockState][rot][i]._blockY + cy]);



	return k;

}



int Block::getCurrentX() { return _currentX; }

int Block::getCurrentY() { return _currentY; }

int Block::getCurrentRotateState() { return _currentRotateState; }

int Block::getCurrentBlockState() { return _currentBlockState; }

int Block::getNextBlockState() { return _nextBlockState; }

void Block::setNextBlockState(int n) { _nextBlockState = n; }

void Block::setCurrentBlockState(int c) { _currentBlockState = c; }



bool Block::isMoveDown()

{

	if (CheckBlockAround(_currentX, _currentY + 1, _currentRotateState) != EMPTY)

	{

		FullLineDelete();

		return true;

	}



	PrintBlock(false);

	_currentY++;

	PrintBlock(true);

	return false;

}



bool Block::isInputKey()

{

	int ch, trot;



	if (_kbhit())

	{

		ch = _getch();

		if (ch == 224 || ch == 0)

		{

			ch = _getch();

			switch (ch)

			{

			case LEFT:

				if (CheckBlockAround(_currentX - 1, _currentY, _currentRotateState) == EMPTY)

				{

					PrintBlock(false);

					_currentX--;

					PrintBlock(true);

				}

				break;

			case RIGHT:

				if (CheckBlockAround(_currentX + 1, _currentY, _currentRotateState) == EMPTY)

				{

					PrintBlock(false);

					_currentX++;

					PrintBlock(true);

				}

				break;

			case UP:

				trot = (_currentRotateState == 3) ? 0 : _currentRotateState + 1;

				if (CheckBlockAround(_currentX, _currentY, trot) == EMPTY)

				{

					PrintBlock(false);

					_currentRotateState = trot;

					PrintBlock(true);

				}

				else if (CheckBlockAround(_currentX + 1, _currentY, trot) != EMPTY)

				{

					PrintBlock(false);

					_currentX--;

					if (getCurrentBlockState() == 0)

						_currentX--;

					_currentRotateState = trot;

					PrintBlock(true);

				}

				else if (CheckBlockAround(_currentX - 1, _currentY, trot) != EMPTY)

				{

					PrintBlock(false);

					_currentX++;

					_currentRotateState = trot;

					PrintBlock(true);

				}

				break;

			case DOWN:

				if (isMoveDown())

					return true;

				break;

			}

		}

		else

			switch (ch)

			{

			case SPACE:

				while (isMoveDown() == false);

				return true;

			}

	}



	return false;

}



void Block::FullLineDelete()

{

	for (int i = 0; i < 4; i++)

		board[_blockShape[_currentBlockState][_currentRotateState][i]._blockX + _currentX]

		[_blockShape[_currentBlockState][_currentRotateState][i]._blockY + _currentY] = BLOCK;



	int x, y, ty;

	for (y = 1; y < _boardHeight + 1; y++)

	{

		for (x = 1; x < _boardWidth + 1; x++)

			if (board[x][y] != BLOCK)

				break;

		if (x == _boardWidth + 1)

		{

			for (ty = y; ty > 1; ty--)

				for (x = 1; x < _boardWidth + 1; x++)

					board[x][ty] = board[x][ty - 1];

			PrintInBoard();

			Sleep(200);

		}

	}



}



void Block::PrintNextBlockBox()

{

	for (int i = 18; i < 27; i++)

		for (int j = 12; j < 18; j++)

		{

			gotoxy(i * 2, j);

			if (i == 18 || i == 26 || j == 12 || j == 17)

				puts(_arrayTile[WALL]);

			else

				puts(_arrayTile[EMPTY]);

		}

}



void Block::PrintNextBlock(bool isBlock)

{

	for (int i = 0; i < 4; i++)

	{

		gotoxy((22 + _blockShape[_nextBlockState][_currentRotateState][i]._blockX) * 2,

			15 + _blockShape[_nextBlockState][_currentRotateState][i]._blockY);

		puts(_arrayTile[isBlock ? BLOCK : EMPTY]);

	}

}



void Block::EmptyNextBlockBox()

{

	for (int i = 19; i < 26; i++)

		for (int j = 13; j < 17; j++)

		{

			gotoxy(i * 2, j);

			puts(_arrayTile[EMPTY]);

		}

}



void Block::PrintShadowBlock(bool isBlock)

{

	if (CheckBlockAround(_currentX, _shadowY + 1, _currentRotateState) == EMPTY)

	{

		_shadowY++;

		return;

	}



	if (CheckBlockAround(_currentX, _shadowY, _currentRotateState) != EMPTY)

	{

		_shadowY--;

		return;

	}



	for (int i = 0; i < 4; i++)

	{

		gotoxy((_currentX + _blockShape[_currentBlockState][_currentRotateState][i]._blockX) * 2,
			_shadowY + _blockShape[_currentBlockState][_currentRotateState][i]._blockY);

		if (_shadowY + _blockShape[_currentBlockState][_currentRotateState][i]._blockY
			== _currentY + _blockShape[_currentBlockState][_currentRotateState][i]._blockY)
			puts(_arrayTile[BLOCK]);

		else
			puts(_arrayTile[isBlock ? SHADOW : EMPTY]);
	}
}


int main()

{
	Block block;
	block.PrintOutBoard();
	block.PrintNextBlockBox();
	int frame, interval;
	frame = 20;
	block.setCurrentBlockState(block.getRandomNumber(0, 6));
	while (true)
	{
		block.InitializeBlockState();
		block.setNextBlockState(block.getRandomNumber(0, 6));
		block.PrintBlock(true);
		block.PrintNextBlock(true);
		if (block.CheckBlockAround(block.getCurrentX(), block.getCurrentY(), block.getCurrentRotateState()))
			break;

		interval = frame;
		while (true)
		{
			block.PrintShadowBlock(false);
			if (--interval == 0)
			{
				interval = frame;
				if (block.isMoveDown())
					break;
			}
			if (block.isInputKey())
				break;
			block.PrintShadowBlock(true);
			Sleep(50);

		}
		block.EmptyNextBlockBox();
		block.setCurrentBlockState(block.getNextBlockState());
	}

	return 0;

}