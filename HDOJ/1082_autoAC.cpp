#include <iostream>
#include <stack>
using namespace std;
const int MATRIX_LEN = 30;
const int INPUT_LEN = 200;
class Matrix
{
public:
    char name[2];
    int row, col;
};
Matrix matrices[MATRIX_LEN];
stack<Matrix> stackMatrices;
int main ()
{
    int matricesNum;
    scanf("%d",&matricesNum);
    Matrix aMatrix;
    for (int i = 0;i < matricesNum;i ++)
    {
        scanf("%s%d%d",aMatrix.name,&aMatrix.row,&aMatrix.col);
        int pos = aMatrix.name[0] - 'A';
        matrices[pos] = aMatrix;
    }
    char input[INPUT_LEN];
    while (scanf("%s",input) != -1)
    {
        while ( ! stackMatrices.empty())
            stackMatrices.pop();
        int totalMultiCount = 0;
        int isError = 0;
        Matrix left, right;
        for (int i = 0;i < strlen(input);i ++)
        {
            if (isalpha(input[i]))
            {
                aMatrix = matrices[ input[i] - 'A' ];
                stackMatrices.push(aMatrix);
                continue;
            }
            if (input[i] == '(')
                continue;
            right = stackMatrices.top();
            stackMatrices.pop();
            left = stackMatrices.top();
            stackMatrices.pop();
            if (left.col != right.row)
            {
                isError = 1;
                break;
            }
            totalMultiCount += left.row * left.col * right.col;
            aMatrix.row = left.row;
            aMatrix.col = right.col;
            stackMatrices.push(aMatrix);
        }
        if (isError)
            printf("error\n");
        else
            printf("%d\n",totalMultiCount);
    }
    return 0;
}
