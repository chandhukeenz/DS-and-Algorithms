//Pascal's Triangle
//Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//Input: 5
//Output:
//[
//     [1],
/*    [1,1],
     [1,2,1],
    [1,3,3,1],
   [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>output;
        vector<int>temp;
        int i=1;
        while(numRows>0){
            temp={};
            for(int j=0;j<i;j++){
                if(j==0||j==i-1) temp.push_back(1);
                else temp.push_back(output[i-2][j-1]+output[i-2][j]);
            }
            output.push_back(temp);
            i++;
            numRows--;
        }
        return output;
    }
};