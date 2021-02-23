

function solution(board, moves) {
    var answer = 0;
    var lists = [];
    var top = -1;
    for(var i = 0 ; i < moves.length ; i++)
    {
        var num = moves[i];
        for(var j = 0 ; j < board.length ; j++)
        {
            var t = board[j][num-1];
            if(t > 0)
            {
                if(top < 0 || lists[top] != t){
                    lists.push(t);
                    top++;
                }
                else {
                    lists.pop()
                    top--;
                    answer++;
                }
                board[j][num-1] = 0;
                break;
            }
        }
    }

    console.log(answer);
    return answer;
}

solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]] ,[1,5,3,5,1,2,1,4] )