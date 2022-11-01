#include <vector>

class Solution {
public:
    std::vector<int> findBall(std::vector<std::vector<int>>& grid) {
        int columns = grid[0].size(),
            rows = grid.size();
        std::vector<int> answer;
        
        for( int i = 0; i < columns; i++)
        {
            int x = i, 
                y = -1, //will check 0
                tempAnswer;
            bool moveBall = true;
            
            while( moveBall ) 
            {
                int yCheck = y + 1;

                if ( yCheck < rows ) 
                {
                    int movementDir = grid[yCheck][x];
                    if ( x + movementDir >= 0 && x + movementDir < columns ) 
                    {
                        int nextDir = grid[yCheck][x+movementDir];
                        if ( nextDir == movementDir ) 
                        {
                            y++;
                            x += movementDir;
                        } else {
                            tempAnswer = -1;
                            moveBall = false;
                        }
                    }  else {
                        tempAnswer = -1;
                        moveBall = false;
                    }
                } else {
                    tempAnswer = x;
                    moveBall = false;
                }
            }
            answer.push_back(tempAnswer);
        }
        return answer;
    }
};