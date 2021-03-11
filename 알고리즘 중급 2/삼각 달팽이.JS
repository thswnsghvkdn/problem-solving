function solution(n) {
    var answer = [];
    function get_max(n)
    {
        return n === 1 ? 1 : get_max(n - 1) + n;
    }
    let snail = Array(n);
    for(let i = 0 ; i < n ; i++)
     snail[i]  = Array( i + 1 );
    let max = get_max(n);
    let num = 1;
    let i = -1 , j = 0;
    while(num <= max)
    {
        while(i + 1 < n && !snail[i+1][j] && num <= max)
        {
            snail[++i][j] = num++;
        }
        while(j + 1 < n && !snail[i][j+1] && num <= max)
        {
            snail[i][++j] = num++;
        }
        while(i - 1 > 0 && j - 1 > 0  && !snail[i-1][j-1] && num <= max)
        {
            snail[--i][--j] = num++;
        }
    }
    for(let i = 0 ; i < n ; i++)
        for(let j = 0 ; j <= i ; j++)
            answer.push(snail[i][j]);
    return answer;
}

solution(6)