#include <iostream>
#include <vector>
using namespace std;
const int STUDENT_NUM = 305;
const int COURSE_NUM = 105;
int augmentedPathsNum;
int mapping[COURSE_NUM];
int isVisited[COURSE_NUM];
vector<int> coursesAttend[STUDENT_NUM];
int DFS_isAugmentedPathExist(int studentId)
{
    for (int i = 0;i < coursesAttend[studentId].size();i ++)
    {
        int courseId = coursesAttend[studentId][i];
        if (isVisited[courseId] != 0)
            continue;
        isVisited[courseId] = 1;
        if (mapping[courseId] == -1 || DFS_isAugmentedPathExist(mapping[courseId]))
        {
            mapping[courseId] = studentId;
            return 1;
        }
    }
    return 0;
}
int main ()
{
    int casesNum;
    scanf("%d",&casesNum);
    for (int i = 1;i <= casesNum;i ++)
    {
        int coursesNum, studentsNum;
        scanf("%d%d", &coursesNum, &studentsNum);
        for (int j = 1;j <= studentsNum;j ++)
            coursesAttend[j].clear();
        for (int j = 1;j <= coursesNum;j ++)
        {
            int studentsNumOfCourse;
            scanf("%d",&studentsNumOfCourse);
            for (int k = 1;k <= studentsNumOfCourse;k ++)
            {
                int studentId;
                scanf("%d",&studentId);
                coursesAttend[studentId].push_back(j);
            }
        }
        memset(mapping, -1, sizeof(mapping));
        augmentedPathsNum = 0;
        for (int j = 1;j <= studentsNum;j ++)
        {
            memset(isVisited, 0, sizeof(isVisited));
            if ( DFS_isAugmentedPathExist(j) == 1 )
                augmentedPathsNum ++;
        }
        if (augmentedPathsNum == coursesNum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
