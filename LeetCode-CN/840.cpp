class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		int endRow = rows - 3;
		int endCol = cols - 3;

		int cnt = 0;

		for (int row = 0; row <= endRow; row++)
		{
			for (int col = 0; col <= endCol; col++)
			{
				int bin[16] = 
				{ 
					-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, //0~9
					0,0,0,0,0,0
				};
				for (int i = row; i < row+3; i++)
				{
					for (int j = col; j < col + 3; j++)
					{
						++bin[grid[i][j]];
					}
				}
				if (find_if(bin + 1, bin + 16, [](const int& x) {return x != 0; }) != (bin + 16)) continue;
				int base = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

				bool flag = false;

				for (int i = 0 ; i < 3; i++)
				{
					int sum = 0;
					int xsum = 0;
					for (int j = 0; j < 3; j++)
					{
						sum += grid[row + i][col + j];
						xsum += grid[row + j][col + i];
					}
					if (sum != base || xsum != base)
					{
						flag = true;
						break;
					}
				}

				if (flag) continue;

				int dsum = 0;
				int xdsum = 0;
				for (int i = 0; i < 3; i++)
				{
					dsum += grid[row + i][col + i];
					xdsum += grid[row + 2 - i][col + 2 - i];
				}
				if (dsum != base || xdsum != base) continue;

				++cnt;
			}
		}

		return cnt;
	}
};
