function solution(info, query) {
    let answer = [];
    let obj = {};
    let arr = [];
    const makeStr =(arr, point , index , str) =>{
        if(index >= 4)
        {
            obj[str] = (obj[str] || []);
            obj[str].push(point)
            return;
        }
        makeStr(arr, point , index + 1, str + arr[index])
        makeStr(arr, point , index + 1, str + '-');
    }
    info.forEach(str =>{
        let q = str.split(" ");
        makeStr(q , Number(q[4]) , 0 , "");    
    })
    query.forEach(str =>{
        let q = str.split(" ").filter( a=>{ return a !== "and"});
        let s = "";
        for(let i = 0 ; i < 4 ; i++)
            s += q[i];
        
        let size = 0;
        if(obj[s])
            size = obj[s].length;
        let tot = 0;
        for(let i = 0 ; i < size ; i++)
            if(obj[s][i] >= Number(q[4]))
                tot++;
        answer.push(tot);
    })
    console.log(answer)
    return answer;
}

solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"] ,["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"] )