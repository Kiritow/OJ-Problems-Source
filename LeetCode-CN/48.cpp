class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n % 2) // odd number, easy
        {
            int mid = n / 2;

            for (int dis = 1; dis <= mid; dis++)
            {
                // do chain swap at distance:dis
                int swap_n = 2 * dis + 1;
                // save right col
                vector<int> tvec;
                int begin_pos = mid - dis;
                for (int i = 0; i < swap_n; i++)
                {
                    tvec.push_back(matrix[begin_pos + i][mid + dis]);
                }
                // start rotate
                // RIGHT <- UPPER
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", begin_pos + i, mid + dis, mid - dis, begin_pos + i);
                    matrix[begin_pos + i][mid + dis] = matrix[mid - dis][begin_pos + i];
                }
                // UPPER <- LEFT
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", mid - dis, begin_pos + i, begin_pos + i, mid - dis);
                    matrix[mid - dis][begin_pos + (swap_n - i - 1)] = matrix[begin_pos + i][mid - dis];
                }
                // LEFT <- DOWNER
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", begin_pos + i, mid - dis, mid + dis, begin_pos + i);
                    matrix[begin_pos + i][mid - dis] = matrix[mid + dis][begin_pos + i];
                }
                // DOWNER <- TEMP
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-tvec[%d]\n", mid + dis, begin_pos + i, i);
                    matrix[mid + dis][begin_pos + (swap_n - i - 1)] = tvec[i];
                }

                // debug
                //print(matrix);
            }
        }
        else // oh, this stuff sucks.
        {
            int mid = n / 2 ;

            for (int dis = 1; dis <= mid ; dis++)
            {
                // do chain swap at distance:dis
                int swap_n = 2 * dis;
                // save right col
                vector<int> tvec;
                int begin_pos = mid - dis;
                for (int i = 0; i < swap_n; i++)
                {
                    tvec.push_back(matrix[begin_pos + i][mid + dis - 1]);
                }
                // start rotate
                // RIGHT <- UPPER
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", begin_pos + i, mid + dis, mid - dis, begin_pos + i);
                    matrix[begin_pos + i][mid + dis - 1] = matrix[mid - dis][begin_pos + i];
                }
                // UPPER <- LEFT
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", mid - dis, begin_pos + i, begin_pos + i, mid - dis);
                    matrix[mid - dis][begin_pos + (swap_n - i - 1)] = matrix[begin_pos + i][mid - dis];
                }
                // LEFT <- DOWNER
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-matrix[%d][%d]\n", begin_pos + i, mid - dis, mid + dis, begin_pos + i);
                    matrix[begin_pos + i][mid - dis] = matrix[mid + dis -1][begin_pos + i];
                }
                // DOWNER <- TEMP
                for (int i = 0; i < swap_n; i++)
                {
                    //printf("matrix[%d][%d]<-tvec[%d]\n", mid + dis, begin_pos + i, i);
                    matrix[mid + dis -1][begin_pos + (swap_n - i - 1)] = tvec[i];
                }

                // debug
                //print(matrix);
            }
        }
    }
};
