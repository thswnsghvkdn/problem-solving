function solution(n, s, a, b, fares) {
    let answer = Number.MAX_SAFE_INTEGER;
    let tmap = Array(n)
            .fill(0)
            .reduce( (acc , _ , idx) =>{
                    acc.push(Array(n+1).fill(Infinity));
                    acc[idx][idx] = 0;
                    return acc;
            }, []);
    
    fares.forEach(e => {
        tmap[e[0] - 1][e[1] - 1] = tmap[e[1] - 1][e[0] - 1] = e[2];
    })
    for(let i = 0 ; i < n ; i++)
        tmap[i][i] = 0;

    for(let k = 0 ; k < n ; k ++)
        for(let i = 0 ; i < n ; i++)
            for(let j = 0 ; j < n ; j++)
                {
                    if(tmap[i][k] + tmap[k][j] < tmap[i][j])
                        tmap[j][i] = tmap[i][j] = tmap[i][k] + tmap[k][j];
                }
    answer = tmap[s - 1][a - 1] + tmap[s - 1][b - 1];
    for(let i = 0 ; i < n ; i++)
    {
        answer = Math.min(answer, tmap[s - 1][i] + tmap[i][a - 1] + tmap[i][b - 1]);
    }

    return answer;
}
console.log(solution(6,4,6,2,	[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))