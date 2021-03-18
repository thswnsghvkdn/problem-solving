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
    let nobj = {};
    Object.keys(obj).filter(str =>{
        nobj[str] = obj[str].sort(function(a,b) { return a > b});
    })

    query.forEach(str =>{
        let q = str.split(" ").filter( a=>{ return a !== "and"});
        let s = "";
        for(let i = 0 ; i < 4 ; i++)
            s += q[i];
        
        let size = 0;
        if(nobj[s])
            size = nobj[s].length;
        let tot = 0;
        
        let start = 0 , end = size;
        if(size > 0){
            while(start < end)
            {
                let mid = Math.floor( (start + end) / 2 );

                if(nobj[s][mid] >= q[4])
                    end = mid;
                else 
                    start = mid + 1;
            }
            answer.push(size - start);
        }
        else answer.push(0);
    })
    console.log(answer)
    return answer;
}

solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"] ,["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"] )