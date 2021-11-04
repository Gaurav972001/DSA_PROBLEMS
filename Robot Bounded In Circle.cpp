class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int xdir = 0, ydir = 1;
        int x = 0, y = 0;

        for (char &i : instructions)
        {
            if (i == 'G')
            {
                x += xdir;
                y += ydir;
            }
            else if (i == 'L')
            {
                int temp = xdir;
                xdir = 0 - ydir;
                ydir = temp;
            }
            else
            {
                int temp = xdir;
                xdir = ydir;
                ydir = 0 - temp;
            }
        }
        return (x == 0 and y == 0) or (xdir != 0 or ydir != 1);
    }
};
