class Solution {
    public boolean isValidSudoku(char[][] board) {
        int m=board.length;
        int n=board[0].length;
     

        for(int i=0;i<9;i++){
            Set<Character>seen= new HashSet<>();
            for(int j=0;j<9;j++){
                char ch= board[i][j];
                if(ch=='.') continue;
                if(!seen.add(ch)) return false;
            }
        }


        for(int j=0;j<9;j++){
            Set<Character>seen= new HashSet<>();
            for(int i=0;i<9;i++){
                char ch= board[i][j];
                if(ch=='.') continue;
                if(!seen.add(ch)) return false;
            }
        }

        for(int boxRow=0;boxRow<3;boxRow++){
            for(int boxCol=0;boxCol<3;boxCol++){
                Set<Character> seen= new HashSet<>();
                for(int r=boxRow*3;r<boxRow*3+3;r++){
                    for(int c=boxCol*3;c<boxCol*3+3;c++){
                        if(board[r][c]=='.') continue;
                        if(!seen.add(board[r][c])) return false;
                    }
                }
            }
        }
        return true;

    }
}